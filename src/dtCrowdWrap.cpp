//
//  dtCrowdWrap.cpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#include "dtCrowdWrap.hpp"
#include <DetourCrowd.h>

Nan::Persistent<FunctionTemplate> dtCrowdWrap::constructor_template;

NAN_MODULE_INIT(dtCrowdWrap::Init) {
    Nan::HandleScope scope;
    Local<FunctionTemplate> t = Nan::New<FunctionTemplate>(New);
    t->InstanceTemplate()->SetInternalFieldCount(1);
    t->SetClassName(Nan::New("dtCrowd").ToLocalChecked());
    constructor_template.Reset(t);
    Nan::Set(target, Nan::New("dtCrowd").ToLocalChecked(),
             Nan::GetFunction(t).ToLocalChecked());
}

NAN_METHOD(dtCrowdWrap::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Use the new operator to create new objects");
    }
    dtCrowdWrap *obj = new dtCrowdWrap();
    obj->m_dtCrowd = new dtCrowd();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}