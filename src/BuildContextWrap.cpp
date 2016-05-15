//
//  BuildContextWrap.cpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#include "BuildContextWrap.hpp"
#include <SampleInterfaces.h>

Nan::Persistent<FunctionTemplate> BuildContextWrap::constructor_template;

NAN_MODULE_INIT(BuildContextWrap::Init) {
    Nan::HandleScope scope;
    Local<FunctionTemplate> t = Nan::New<FunctionTemplate>(New);
    t->InstanceTemplate()->SetInternalFieldCount(1);
    t->SetClassName(Nan::New("BuildContext").ToLocalChecked());
    
    constructor_template.Reset(t);
    Nan::Set(target, Nan::New("BuildContext").ToLocalChecked(),
             Nan::GetFunction(t).ToLocalChecked());
}

NAN_METHOD(BuildContextWrap::New) {
    if (!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Use the new operator to create new objects");
    }
    BuildContextWrap *obj = new BuildContextWrap();
    obj->m_buildContext = new BuildContext();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}