//
//  InputGeomWarp.hpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#ifndef InputGeomWrap_hpp
#define InputGeomWrap_hpp

#include <node.h>
#include <nan.h>
#include <InputGeom.h>

using namespace v8;

class InputGeomNode : public InputGeom {

};

class InputGeomWrap : public Nan::ObjectWrap {
    
public:
    static Nan::Persistent<v8::FunctionTemplate> constructor_template;
    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);
    static NAN_METHOD(Load);
    
public:
    InputGeom* getInputGeom() { return m_inputGeom; };
    
private:
    InputGeom *m_inputGeom;
};


#endif /* InputGeomWarp_hpp */
