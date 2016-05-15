//
//  dtNavMeshWrap.hpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#ifndef dtNavMeshWrap_hpp
#define dtNavMeshWrap_hpp

#include <node.h>
#include <nan.h>

using namespace v8;

class dtNavMesh;
class dtNavMeshWrap : public Nan::ObjectWrap {
    
public:
    static Nan::Persistent<v8::FunctionTemplate> constructor_template;
    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);
    
private:
    dtNavMesh *m_dtNavMesh;
};


#endif /* dtNavMeshWrap_hpp */
