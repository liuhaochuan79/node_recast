//
//  dtNavMeshWrap.cpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#include "dtNavMeshWrap.hpp"
#include <DetourNavMesh.h>

Nan::Persistent<FunctionTemplate> dtNavMeshWrap::constructor_template;


NAN_MODULE_INIT(dtNavMeshWrap::Init) {
    Nan::HandleScope scope;
    Local<FunctionTemplate> t = Nan::New<FunctionTemplate>(New);
    t->InstanceTemplate()->SetInternalFieldCount(1);
    t->SetClassName(Nan::New("dtNavMeshQuery").ToLocalChecked());
    constructor_template.Reset(t);
    Nan::Set(target, Nan::New("dtNavMeshQuery").ToLocalChecked(),
             Nan::GetFunction(t).ToLocalChecked());
}

NAN_METHOD(dtNavMeshWrap::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Use the new operator to create new objects");
    }
    dtNavMeshWrap *obj = new dtNavMeshWrap();
    obj->m_dtNavMesh = new dtNavMesh();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}
