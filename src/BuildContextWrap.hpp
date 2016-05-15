//
//  BuildContextWrap.hpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#ifndef BuildContextWrap_hpp
#define BuildContextWrap_hpp

#include <node.h>
#include <nan.h>

using namespace v8;

class BuildContext;
class BuildContextWrap : public Nan::ObjectWrap {
    
public:
    static Nan::Persistent<v8::FunctionTemplate> constructor_template;
    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);
    
public:
    BuildContext* getBuildContext() { return m_buildContext; };
    
private:
    BuildContext *m_buildContext;
};

#endif /* BuildContextWrap_hpp */
