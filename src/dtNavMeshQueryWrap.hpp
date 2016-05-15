//
//  dtNavMeshQueryWrap.hpp
//  binding
//
//  Created by pop on 16/5/13.
//
//

#ifndef dtNavMeshQueryWrap_hpp
#define dtNavMeshQueryWrap_hpp

#include <node.h>
#include <nan.h>

using namespace v8;

class dtNavMeshQuery;
class dtNavMeshQueryWrap : public Nan::ObjectWrap {
    
public:
    static Nan::Persistent<v8::FunctionTemplate> constructor_template;
    static NAN_MODULE_INIT(Init);
    static NAN_METHOD(New);
    
private:
    dtNavMeshQuery *m_dtNavMeshQuery;
};

#endif /* dtNavMeshQueryWrap_hpp */
