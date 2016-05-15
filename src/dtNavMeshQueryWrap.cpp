//
//  dtNavMeshQueryWrap.cpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#include "dtNavMeshQueryWrap.hpp"
#include <DetourNavMeshQuery.h>

Nan::Persistent<FunctionTemplate> dtNavMeshQueryWrap::constructor_template;

NAN_MODULE_INIT(dtNavMeshQueryWrap::Init) {
    Nan::HandleScope scope;
    Local<FunctionTemplate> t = Nan::New<FunctionTemplate>(New);
    t->InstanceTemplate()->SetInternalFieldCount(1);
    t->SetClassName(Nan::New("dtNavMeshQuery").ToLocalChecked());
    constructor_template.Reset(t);
    Nan::Set(target, Nan::New("dtNavMeshQuery").ToLocalChecked(),
             Nan::GetFunction(t).ToLocalChecked());
}

NAN_METHOD(dtNavMeshQueryWrap::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Use the new operator to create new objects");
    }
    dtNavMeshQueryWrap *obj = new dtNavMeshQueryWrap();
    obj->m_dtNavMeshQuery = new dtNavMeshQuery();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}