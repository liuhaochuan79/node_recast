//
//  Sample_TempObstaclesWrap.hpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#ifndef Sample_TempObstaclesWrap_hpp
#define Sample_TempObstaclesWrap_hpp

#include <node.h>
#include <nan.h>

using namespace v8;

class Sample_TempObstaclesExt;
class Sample_TempObstaclesWrap : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::FunctionTemplate> constructor_template;
    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);
    static NAN_METHOD(SetContext);
    static NAN_METHOD(SetInputGeom);
    static NAN_METHOD(Build);
    static NAN_METHOD(SetCellSize);
    static NAN_METHOD(SetCellHeight);
    static NAN_METHOD(SetAgentHeight);
    static NAN_METHOD(SetAgentRadius);
    static NAN_METHOD(SetAgentMaxClimb);
    static NAN_METHOD(SetAgentMaxSlope);
    static NAN_METHOD(SetRegionMinSize);
    static NAN_METHOD(SetRegionMergeSize);
    static NAN_METHOD(SetEdgeMaxLen);
    static NAN_METHOD(SetEdgeMaxError);
    static NAN_METHOD(SetVertsPerPoly);
    static NAN_METHOD(SetDetailSampleDist);
    static NAN_METHOD(SetDetailSampleMaxError);
    static NAN_METHOD(SetPartitionType);
    static NAN_METHOD(Update);
    static NAN_METHOD(AddTempObstacle);
    static NAN_METHOD(RemoveTempObstacle);
    static NAN_METHOD(ClearAllTempObstacles);
    static NAN_METHOD(FindNearestPoint);
    static NAN_METHOD(GetRandomPoint);
    static NAN_METHOD(FindPath);

public:
    Sample_TempObstaclesExt* getSample_TempObstacles() { return m_sample_TempObstacles; };

private:
    Sample_TempObstaclesExt *m_sample_TempObstacles;
};


#endif /* Sample_TempObstaclesWrap_hpp */
