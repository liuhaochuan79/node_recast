//
//  dtCrowdWrap.hpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#ifndef dtCrowdWrap_hpp
#define dtCrowdWrap_hpp

#include <node.h>
#include <nan.h>

using namespace v8;

class dtCrowd;
class dtCrowdWrap : public Nan::ObjectWrap {
    
public:
    static Nan::Persistent<v8::FunctionTemplate> constructor_template;
    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);
    
private:
    dtCrowd *m_dtCrowd;
};

#endif /* dtCrowdWrap_hpp */
