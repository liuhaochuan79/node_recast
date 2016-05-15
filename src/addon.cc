#include <node.h>
#include <nan.h>

#include "BuildContextWrap.hpp"
#include "InputGeomWrap.hpp"
#include "dtCrowdWrap.hpp"
#include "dtNavMeshWrap.hpp"
#include "dtNavMeshQueryWrap.hpp"
#include "Sample_TempObstaclesWrap.hpp"

using namespace v8;

void InitAll(Handle<Object> exports) {
    
    BuildContextWrap::Init(exports);
    InputGeomWrap::Init(exports);
    Sample_TempObstaclesWrap::Init(exports);
    dtCrowdWrap::Init(exports);
    dtNavMeshWrap::Init(exports);
    dtNavMeshQueryWrap::Init(exports);
}

NODE_MODULE(addon, InitAll)
