
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/time.h>
#include <math.h>
#include <Sample_TempObstacles.h>
#include "Sample_TempObstaclesExt.hpp"
#include <DetourTileCache.h>
#include <DetourNavMeshQuery.h>

#include <time.h>

Sample_TempObstaclesExt::Sample_TempObstaclesExt() {
  srand(time(NULL));
}

bool Sample_TempObstaclesExt::Build() 
{
  return handleBuild();
}

unsigned int Sample_TempObstaclesExt::addTempObstacle(const float posX,const float posY,const float posZ,const float radius, const float height)
{
  float p[3];
  p[0] = posX;
  p[1] = posY;
  p[2] = posZ;
  unsigned int ref;
  m_tileCache->addObstacle(p, radius, height, &ref);
  return ref;
}

unsigned int Sample_TempObstaclesExt::removeTempObstacle(const unsigned int ref)
{
  dtStatus status = m_tileCache->removeObstacle(ref);
  return status;
}

unsigned int Sample_TempObstaclesExt::findNearestPoint(float cx, float cy, float cz,float extx, float exty, float extz,float *nearestPos,dtPolyRef *ref)
{
  dtNavMeshQuery* m_navQuery = getNavMeshQuery();
  const float p[3] = {cx,cy,cz};
  const float ext[3] = {extx,exty,extz};
  dtQueryFilter filter;
  filter.setIncludeFlags(3);
  filter.setExcludeFlags(0);
  dtStatus status = m_navQuery->findNearestPoly(p, ext, &filter, ref, nearestPos);
  return status;
}

// Returns a random number [0..1)
static float frand()
{
//  return ((float)(rand() & 0xffff)/(float)0xffff);
  return (float)rand()/(float)RAND_MAX;
}

unsigned int Sample_TempObstaclesExt::getRandomPoint(float *randomPt,dtPolyRef *ref)
{
    dtQueryFilter filter;
    filter.setIncludeFlags(3);
    filter.setExcludeFlags(0);
    dtNavMeshQuery* m_navQuery = getNavMeshQuery();
    dtStatus status = m_navQuery->findRandomPoint(&filter, frand, ref, randomPt);
    return status;
}

unsigned int Sample_TempObstaclesExt::findPath(float startPosX, float startPosY, float startPosZ,
              float endPosX, float endPosY, float endPosZ, int maxPath,vpath *ret) 
{
  dtNavMeshQuery* m_navQuery = getNavMeshQuery();
  if( m_navQuery == NULL) {
    printf("NavMeshQuery is not ready");
    return DT_FAILURE;
  }
  float startPos[3] = { startPosX, startPosY, startPosZ };
  float endPos[3] = { endPosX, endPosY, endPosZ };
  const float ext[3] = {2,4,2};
  dtStatus status;
  dtPolyRef path[maxPath+1];
  int pathCount;
  dtQueryFilter filter;
  filter.setIncludeFlags(3);
  filter.setExcludeFlags(0);
  // Change costs.
  filter.setAreaCost(SAMPLE_POLYAREA_GROUND, 1.0f);
  filter.setAreaCost(SAMPLE_POLYAREA_WATER, 10.0f);
  filter.setAreaCost(SAMPLE_POLYAREA_ROAD,   1.0f);
  filter.setAreaCost(SAMPLE_POLYAREA_DOOR,   1.0f);
  filter.setAreaCost(SAMPLE_POLYAREA_GRASS,  2.0f);
  filter.setAreaCost(SAMPLE_POLYAREA_JUMP,   1.5f);
  float nearestStartPos[3];
  dtPolyRef startRef = 0;
  m_navQuery->findNearestPoly(startPos, ext, &filter, &startRef, nearestStartPos);
  float nearestEndPos[3];
  dtPolyRef endRef = 0;
  m_navQuery->findNearestPoly(endPos, ext, &filter, &endRef, nearestEndPos);
  //printf("Use %u , %u as start / end polyRefs \n", startRef, endRef);
  status = m_navQuery->findPath(startRef, endRef, nearestStartPos, nearestEndPos, &filter, path, &pathCount, maxPath);
  if (dtStatusFailed(status)) {
      printf("Cannot find a path: %u\n", status);
      return status;
  } 
  
  //printf("Found a %u polysteps path \n", pathCount);
  float straightPath[maxPath*3];
  unsigned char straightPathFlags[maxPath];
  dtPolyRef straightPathRefs[maxPath];
  int straightPathCount = 0;
  int maxStraightPath = maxPath;
  int options = 0;
  status = m_navQuery->findStraightPath(nearestStartPos, nearestEndPos, path, pathCount, straightPath,
                              straightPathFlags, straightPathRefs, &straightPathCount, maxStraightPath, options);

  if (dtStatusFailed(status)) {
    printf("Cannot find a straight path: %u\n", status);
    return status;
  }
  //printf("Found a %u steps path \n", straightPathCount);
  ret->nlen = straightPathCount;
  ret->datas = new vertex3[straightPathCount];
  for (int i = 0; i < straightPathCount; ++i) {
    const float* v = &straightPath[i*3];
    ret->datas[i].x = v[0];
    ret->datas[i].y = v[1];
    ret->datas[i].z = v[2];
    // why ?
    if (!(fabs(v[0]) < 0.0000001f && fabs(v[1]) < 0.0000001f && fabs(v[2]) < 0.0000001f)) {
      //sprintf(buff, "__tmp_recastjs_data.push({x:%f, y:%f, z:%f});", v[0], v[1], v[2]);
      //emscripten_run_script(buff);
    } else {
      //sprintf(buff, "ignore %f, %f, %f", v[0], v[1], v[2]);
      //emscripten_log(buff);
    }
  }
  return status;
}