var addon = require('bindings')('addon');

var startTime = 0;
var endTime = 0;
var costTime = 0;
//上下文
var buildContext = new addon.BuildContext();

//输入网格
startTime = new Date().getTime();
var inputGeom = new addon.InputGeom();
var error = inputGeom.load(buildContext, __dirname + '/maz0001.obj');
if( !error) {
  console.log('加载网格文件失败!');
  process.exit(0);
}
else {
 console.log('加载网格文件成功'); 
}
endTime = new Date().getTime();
costTime = endTime - startTime;
console.log('加载网格文件消耗时间:' + costTime + 'ms');

var sample_TempObstacles = new addon.Sample_TempObstacles();

//设置参数
sample_TempObstacles.setCellSize(0.1);
sample_TempObstacles.setCellHeight(0.2);
sample_TempObstacles.setAgentHeight(2.0);
//这个参数如果设置太大,可能会截断某些很狭窄的地形
//recast.set_agentRadius(0.6);
sample_TempObstacles.setAgentRadius(0.0);
//这个参数可以定义多边形大小,越小,多边形越多
sample_TempObstacles.setAgentMaxClimb(0.9);
sample_TempObstacles.setAgentMaxSlope(45.0);
sample_TempObstacles.setRegionMinSize(8);
sample_TempObstacles.setRegionMergeSize(20.0);
sample_TempObstacles.setEdgeMaxLen(12.0);
sample_TempObstacles.setEdgeMaxError(1.3);
sample_TempObstacles.setVertsPerPoly(6);
sample_TempObstacles.setDetailSampleDist(6.0);
sample_TempObstacles.setDetailSampleMaxError(1.0);
sample_TempObstacles.setPartitionType(0);

//设置上下文
sample_TempObstacles.setContext(buildContext);
//设置输入网格
sample_TempObstacles.setInputGeom(inputGeom);

//建立导航网格
startTime = new Date().getTime();
error = sample_TempObstacles.build();
if( !error) {
  console.log('建立导航网格失败!');
  process.exit(0);
}
else {
 console.log('建立导航网格成功'); 
}
endTime = new Date().getTime();
costTime = endTime - startTime;
console.log('建立导航网格消耗时间:' + costTime + 'ms');

//添加临时障碍
//坐标，半径，高度
var x = 1.0;
var y = 1.0;
var z = 1.0;
var radius = 1.0;
var height = 2.0;
var ref1 = sample_TempObstacles.addTempObstacle(x,y,z,radius,height);
sample_TempObstacles.update(0);
console.log('addTempObstacle result ref1:' + ref1);
var ref2 = sample_TempObstacles.addTempObstacle(x,y,z,radius,height);
sample_TempObstacles.update(0);
console.log('addTempObstacle result ref2:' + ref2);

//删除零食障碍
var status = sample_TempObstacles.removeTempObstacle(ref1);
sample_TempObstacles.update(0);
console.log('removeTempObstacle status:' + status);

ref1 = sample_TempObstacles.addTempObstacle(x,y,z,radius,height);
sample_TempObstacles.update(0);
console.log('addTempObstacle result ref1:' + ref1);

var nPt = sample_TempObstacles.findNearestPoint(0,0,0,2.0,2.0,2.0);
console.log('FindNearestPoint result:');
console.dir(nPt);


//删除所有临时障碍
sample_TempObstacles.clearAllTempObstacles();
sample_TempObstacles.update(0);

//测试随机寻路1000次消耗时间毫秒
startTime = new Date().getTime();
for(var i = 0; i < 1000; i++) {
  //随机得到一个合法的点
  var ranPt1 = sample_TempObstacles.findRandomPoint();
  //console.log(ranPt1);

  var ranPt2 = sample_TempObstacles.findRandomPoint();
  //console.log(ranPt2);

  //寻路
  var path1 = sample_TempObstacles.findPath(ranPt1.x,ranPt1.y,ranPt1.z,ranPt2.x,ranPt2.y,ranPt2.z,1000);
  //console.log('findPath result1:');
  //console.dir(path1);

  //var path2 = sample_TempObstacles.findPath(ranPt2.x,ranPt2.y,ranPt2.z,ranPt1.x,ranPt1.y,ranPt1.z,1000);
  //console.log('findPath result2:');
  //console.dir(path2);
}

endTime = new Date().getTime();
costTime = endTime - startTime;
console.log('测试随机寻路1000次消耗时间:' + costTime + 'ms');

