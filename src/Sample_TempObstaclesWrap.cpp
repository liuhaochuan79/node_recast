//
//  Sample_TempObstaclesWrap.cpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#include "Sample_TempObstaclesWrap.hpp"
#include <SampleInterfaces.h>
#include <InputGeom.h>
#include "BuildContextWrap.hpp"
#include "InputGeomWrap.hpp"
#include "macros.h"
#include "DetourStatus.h"
#include "Sample_TempObstaclesExt.hpp"

Nan::Persistent<FunctionTemplate> Sample_TempObstaclesWrap::constructor_template;

NAN_MODULE_INIT(Sample_TempObstaclesWrap::Init) {
    Nan::HandleScope scope;
    Local<FunctionTemplate> t = Nan::New<FunctionTemplate>(New);
    t->InstanceTemplate()->SetInternalFieldCount(1);
    t->SetClassName(Nan::New("Sample_TempObstacles").ToLocalChecked());
    Nan::SetPrototypeMethod(t, "setContext", SetContext);
    Nan::SetPrototypeMethod(t, "setInputGeom", SetInputGeom);
    Nan::SetPrototypeMethod(t, "build", Build);
    Nan::SetPrototypeMethod(t, "setCellSize", SetCellSize);
    Nan::SetPrototypeMethod(t, "setCellHeight", SetCellHeight);
    Nan::SetPrototypeMethod(t, "setAgentHeight", SetAgentHeight);
    Nan::SetPrototypeMethod(t, "setAgentRadius", SetAgentRadius);
    Nan::SetPrototypeMethod(t, "setAgentMaxClimb", SetAgentMaxClimb);
    Nan::SetPrototypeMethod(t, "setAgentMaxSlope", SetAgentMaxSlope);
    Nan::SetPrototypeMethod(t, "setRegionMinSize", SetRegionMinSize);
    Nan::SetPrototypeMethod(t, "setRegionMergeSize", SetRegionMergeSize);
    Nan::SetPrototypeMethod(t, "setEdgeMaxLen", SetEdgeMaxLen);
    Nan::SetPrototypeMethod(t, "setEdgeMaxError", SetEdgeMaxError);
    Nan::SetPrototypeMethod(t, "setVertsPerPoly", SetVertsPerPoly);
    Nan::SetPrototypeMethod(t, "setDetailSampleDist", SetDetailSampleDist);
    Nan::SetPrototypeMethod(t, "setDetailSampleMaxError", SetDetailSampleMaxError);
    Nan::SetPrototypeMethod(t, "setPartitionType", SetPartitionType);
    Nan::SetPrototypeMethod(t, "update", Update);
    Nan::SetPrototypeMethod(t, "addTempObstacle", AddTempObstacle);
    Nan::SetPrototypeMethod(t, "removeTempObstacle", RemoveTempObstacle);
    Nan::SetPrototypeMethod(t, "clearAllTempObstacles", ClearAllTempObstacles);
    Nan::SetPrototypeMethod(t, "findNearestPoint", FindNearestPoint);
    Nan::SetPrototypeMethod(t, "getRandomPoint", GetRandomPoint);
    Nan::SetPrototypeMethod(t, "findPath", FindPath);

    constructor_template.Reset(t);
    Nan::Set(target, Nan::New("Sample_TempObstacles").ToLocalChecked(),
             Nan::GetFunction(t).ToLocalChecked());
}

NAN_METHOD(Sample_TempObstaclesWrap::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Use the new operator to create new objects");
    }
    Sample_TempObstaclesWrap *obj = new Sample_TempObstaclesWrap();
    obj->m_sample_TempObstacles = new Sample_TempObstaclesExt();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetContext) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    BuildContextWrap *buildContext = Nan::ObjectWrap::Unwrap<BuildContextWrap>(info[0]->ToObject());
    BuildContext *ctx = buildContext->getBuildContext();
    obj->getSample_TempObstacles()->setContext(ctx);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetInputGeom) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    InputGeomWrap *inputGeomWrap = Nan::ObjectWrap::Unwrap<InputGeomWrap>(info[0]->ToObject());
    InputGeom *inputGeom = inputGeomWrap->getInputGeom();
    obj->getSample_TempObstacles()->handleMeshChanged(inputGeom);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::Build) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    bool result = obj->getSample_TempObstacles()->Build();
    info.GetReturnValue().Set(result);
}

NAN_METHOD(Sample_TempObstaclesWrap::SetCellSize) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetCellSize(val);
    //printf("SetCellSize:%f\n",(float)val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetCellHeight) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetCellHeight(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetAgentHeight) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetAgentHeight(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetAgentRadius) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetAgentRadius(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetAgentMaxClimb) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetAgentMaxClimb(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetAgentMaxSlope) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetAgentMaxSlope(val);
    info.GetReturnValue().Set(info.This());
    
}

NAN_METHOD(Sample_TempObstaclesWrap::SetRegionMinSize) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetRegionMinSize(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetRegionMergeSize) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetRegionMergeSize(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetEdgeMaxLen) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetEdgeMaxLen(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetEdgeMaxError) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetEdgeMaxError(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetVertsPerPoly) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetVertsPerPoly(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetDetailSampleDist) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetDetailSampleDist(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetDetailSampleMaxError) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, val,0);
    obj->getSample_TempObstacles()->SetDetailSampleMaxError(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::SetPartitionType) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_INTEGER(0, val,0);
    obj->getSample_TempObstacles()->SetPartitionType(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::Update) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_INTEGER(0, val,0);
    obj->getSample_TempObstacles()->handleUpdate(val);
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::AddTempObstacle) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, posX,0);
    OPTIONAL_ARGUMENT_FLOAT(1, posY,0);
    OPTIONAL_ARGUMENT_FLOAT(2, posZ,0);
    OPTIONAL_ARGUMENT_FLOAT(3, radius,0);
    OPTIONAL_ARGUMENT_FLOAT(4, height,0);
    unsigned int ref = obj->getSample_TempObstacles()->addTempObstacle(posX,posY,posZ,radius,height);
    info.GetReturnValue().Set(ref);
}

NAN_METHOD(Sample_TempObstaclesWrap::RemoveTempObstacle) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_INTEGER(0, ref,0);
    unsigned int status = obj->getSample_TempObstacles()->removeTempObstacle(ref);
    if (dtStatusFailed(status)) {
      info.GetReturnValue().Set(false); 
    }
    else {
        info.GetReturnValue().Set(true);
    }
}

NAN_METHOD(Sample_TempObstaclesWrap::ClearAllTempObstacles) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    obj->getSample_TempObstacles()->clearAllTempObstacles();
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Sample_TempObstaclesWrap::FindNearestPoint) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, posX,0);
    OPTIONAL_ARGUMENT_FLOAT(1, posY,0);
    OPTIONAL_ARGUMENT_FLOAT(2, posZ,0);
    OPTIONAL_ARGUMENT_FLOAT(3, extentX,0);
    OPTIONAL_ARGUMENT_FLOAT(4, extentY,0);
    OPTIONAL_ARGUMENT_FLOAT(5, extentZ,0);
    dtPolyRef ref = 0;
    float nearestPos[3];
    int status = obj->getSample_TempObstacles()->findNearestPoint(posX,posY,posZ,extentX,extentY,extentZ,nearestPos,&ref);
    if (dtStatusFailed(status)) {
      info.GetReturnValue().Set(Nan::Null()); 
    }
    else {
        v8::Local<v8::Object> ret = Nan::New<v8::Object>();
        Nan::Set(ret, Nan::New("x").ToLocalChecked(), Nan::New(nearestPos[0]));
        Nan::Set(ret, Nan::New("y").ToLocalChecked(), Nan::New(nearestPos[1]));
        Nan::Set(ret, Nan::New("z").ToLocalChecked(), Nan::New(nearestPos[2]));
        Nan::Set(ret, Nan::New("ref").ToLocalChecked(), Nan::New(ref));
        info.GetReturnValue().Set(ret);
    }
}

NAN_METHOD(Sample_TempObstaclesWrap::GetRandomPoint) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());

    dtPolyRef ref = 0;
    float randomPt[3];
    int status = obj->getSample_TempObstacles()->getRandomPoint(randomPt,&ref);
    if (dtStatusFailed(status)) {
      info.GetReturnValue().Set(Nan::Null()); 
    }
    else {
        v8::Local<v8::Object> ret = Nan::New<v8::Object>();
        Nan::Set(ret, Nan::New("x").ToLocalChecked(), Nan::New(randomPt[0]));
        Nan::Set(ret, Nan::New("y").ToLocalChecked(), Nan::New(randomPt[1]));
        Nan::Set(ret, Nan::New("z").ToLocalChecked(), Nan::New(randomPt[2]));
        Nan::Set(ret, Nan::New("ref").ToLocalChecked(), Nan::New(ref));
        info.GetReturnValue().Set(ret);
    }
}

NAN_METHOD(Sample_TempObstaclesWrap::FindPath) {
    Sample_TempObstaclesWrap* obj = Nan::ObjectWrap::Unwrap<Sample_TempObstaclesWrap>(info.This());
    OPTIONAL_ARGUMENT_FLOAT(0, sx,0);
    OPTIONAL_ARGUMENT_FLOAT(1, sy,0);
    OPTIONAL_ARGUMENT_FLOAT(2, sz,0);
    OPTIONAL_ARGUMENT_FLOAT(3, ex,0);
    OPTIONAL_ARGUMENT_FLOAT(4, ey,0);
    OPTIONAL_ARGUMENT_FLOAT(5, ez,0);
    OPTIONAL_ARGUMENT_INTEGER(6, maxPath,0);

    vpath path;
    int status = obj->getSample_TempObstacles()->findPath(sx,sy,sz,ex,ey,ez,maxPath,&path);
    if (dtStatusFailed(status)) {
      info.GetReturnValue().Set(Nan::Null()); 
    }
    else {
        v8::Local<v8::Array> result = Nan::New<v8::Array>(path.nlen);
        for(int i = 0; i < path.nlen; i++) {
            v8::Local<v8::Object> dt = Nan::New<v8::Object>();
            Nan::Set(dt, Nan::New("x").ToLocalChecked(), Nan::New(path.datas[i].x));
            Nan::Set(dt, Nan::New("y").ToLocalChecked(), Nan::New(path.datas[i].y));
            Nan::Set(dt, Nan::New("z").ToLocalChecked(), Nan::New(path.datas[i].z));
            result->Set(i, dt);
        }
        info.GetReturnValue().Set(result);
        if(path.datas) { delete path.datas; }
    }
}

