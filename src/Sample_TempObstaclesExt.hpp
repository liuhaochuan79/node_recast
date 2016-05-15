#ifndef Sample_TempObstaclesExt_hpp
#define Sample_TempObstaclesExt_hpp

#include <Sample_TempObstacles.h>

struct vertex3 {
    float x;
    float y;
    float z;
};

struct vpath {
    int nlen;
    vertex3 *datas;
};

class Sample_TempObstaclesExt : public Sample_TempObstacles {

public:
    Sample_TempObstaclesExt();
    void SetCellSize(float val) { m_cellSize = val; }
    void SetCellHeight(float val) { m_cellHeight = val; }
    void SetAgentHeight(float val) { m_agentHeight = val; }
    void SetAgentRadius(float val) { m_agentRadius = val; }
    void SetAgentMaxClimb(float val) { m_agentMaxClimb = val; }
    void SetAgentMaxSlope(float val) { m_agentMaxSlope = val; }
    void SetRegionMinSize(float val) { m_regionMinSize = val; }
    void SetRegionMergeSize(float val) { m_regionMergeSize = val; }
    void SetEdgeMaxLen(float val) { m_edgeMaxLen = val; }
    void SetEdgeMaxError(float val) { m_edgeMaxError = val; }
    void SetVertsPerPoly(float val) { m_vertsPerPoly = val; }
    void SetDetailSampleDist(float val) { m_detailSampleDist = val; }
    void SetDetailSampleMaxError(float val) { m_detailSampleMaxError = val; }
    void SetPartitionType(int val) { m_partitionType = val; }
    unsigned int addTempObstacle(const float posX,const float posY,const float posZ,const float radius, const float height);
    unsigned int removeTempObstacle(const unsigned int ref);
    unsigned int findNearestPoint(float cx, float cy, float cz,float extx, float exty, float extz,float *nearestPos,dtPolyRef *ref);
    unsigned int findRandomPoint(float *randomPt,dtPolyRef *ref);
    unsigned int findPath(float startPosX, float startPosY, float startPosZ,float endPosX, float endPosY, float endPosZ, int maxPath,vpath *ret);
    bool Build();
};

#endif