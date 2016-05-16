# npm install
npm install node_recast

# Usage

``` js
var node_recast = require('node_recast');
var recast = new node_recast();
recast.setCellSize(0.1);
recast.setCellHeight(0.2);
recast.setAgentHeight(2.0);
recast.setAgentRadius(0.0);
recast.setAgentMaxClimb(0.9);
recast.setAgentMaxSlope(45.0);
recast.setRegionMinSize(8);
recast.setRegionMergeSize(20.0);
recast.setEdgeMaxLen(12.0);
recast.setEdgeMaxError(1.3);
recast.setVertsPerPoly(6);
recast.setDetailSampleDist(6.0);
recast.setDetailSampleMaxError(1.0);
recast.setPartitionType(0);

recast.load('/path/objfile.obj');

recast.build();

var nPt = recast.findNearestPoint(0,0,0,2.0,2.0,2.0);
console.log('FindNearestPoint result:');
console.dir(nPt);

var ref = recast.addTempObstacle(0.1,0.2,0.3,radius,height);
recast.update(0);

recast.removeTempObstacle(ref);
recast.update(0);

recast.clearAllTempObstacles();
recast.update(0);

var ranPt1 = recast.findRandomPoint();

var ranPt2 = recast.findRandomPoint();

var path1 = recast.findPath(ranPt1.x,ranPt1.y,ranPt1.z,ranPt2.x,ranPt2.y,ranPt2.z,1000);
console.dir(path1);
```

# Testing

node ./node_modules/node_recast/test/test.js

# Author

liuhaochuan & zhangyu