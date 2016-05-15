//
//  InputGeomWarp.cpp
//  binding
//
//  Created by pop on 16/5/13.
//
//


#include "InputGeomWrap.hpp"
#include "macros.h"
#include "BuildContextWrap.hpp"
#include <SampleInterfaces.h>

Nan::Persistent<FunctionTemplate> InputGeomWrap::constructor_template;

NAN_MODULE_INIT(InputGeomWrap::Init) {
    Nan::HandleScope scope;
    Local<FunctionTemplate> t = Nan::New<FunctionTemplate>(New);
    t->InstanceTemplate()->SetInternalFieldCount(1);
    t->SetClassName(Nan::New("InputGeom").ToLocalChecked());
    Nan::SetPrototypeMethod(t, "load", Load);
    constructor_template.Reset(t);
    Nan::Set(target, Nan::New("InputGeom").ToLocalChecked(),
             Nan::GetFunction(t).ToLocalChecked());
}

NAN_METHOD(InputGeomWrap::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Use the new operator to create new objects");
    }
    InputGeomWrap *obj = new InputGeomWrap();
    obj->m_inputGeom = new InputGeom();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(InputGeomWrap::Load) {
    InputGeomWrap* thisobj = Nan::ObjectWrap::Unwrap<InputGeomWrap>(info.This());
    BuildContextWrap *buildContext = Nan::ObjectWrap::Unwrap<BuildContextWrap>(info[0]->ToObject());
    REQUIRE_ARGUMENT_STRING(1, filename);
    rcContext *ctx = buildContext->getBuildContext();
    bool result = thisobj->getInputGeom()->load(ctx,*filename);
    //info.This()->ForceSet(Nan::New("filename").ToLocalChecked(), info[0].As<String>(), ReadOnly);
    info.GetReturnValue().Set(result);
}

/*
 NAN_METHOD(CalculatePrimes) {
 int under = To<int>(info[0]).FromJust();
 Callback *callback = new Callback(info[1].As<Function>());
 
 AsyncQueueWorker(new PrimeWorker(callback, under));
 }
*/