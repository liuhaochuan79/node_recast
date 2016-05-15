# node_recast
recast navigation for node.js addon
# install:  npm install node_recast
# uninstall: npm uninstall node_recast

# Usage

function testRecast() {
  let node_recast = require('node_recast');
  let recast = new node_recast();
  //设置参数
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
  let error = recast.load('/Users/pop/project/bin/en/col/an0101.obj');
  if( !error) {
    console.log('加载网格文件失败!');
    process.exit(0);
  }
  else {
    console.log('加载网格文件成功');
  }

  error = recast.build();
  if( !error) {
    console.log('建立导航网格失败!');
    process.exit(0);
  }
  else {
    console.log('建立导航网格成功');
  }

  let startTime = 0;
  let endTime = 0;
  let costTime = 0;
  //添加临时障碍
  //坐标，半径，高度
  let x = 1.0;
  let y = 1.0;
  let z = 1.0;
  let radius = 1.0;
  let height = 2.0;
  let ref1 = recast.addTempObstacle(x,y,z,radius,height);
  recast.update(0);
  console.log('addTempObstacle result ref1:' + ref1);
  var ref2 = recast.addTempObstacle(x,y,z,radius,height);
  recast.update(0);
  console.log('addTempObstacle result ref2:' + ref2);

  //删除零食障碍
  var status = recast.removeTempObstacle(ref1);
  recast.update(0);
  console.log('removeTempObstacle status:' + status);

  ref1 = recast.addTempObstacle(x,y,z,radius,height);
  recast.update(0);
  console.log('addTempObstacle result ref1:' + ref1);

  //删除所有临时障碍
  recast.clearAllTempObstacles();
  recast.update(0);

  //测试随机寻路1000次消耗时间毫秒
  startTime = new Date().getTime();
  for(var i = 0; i < 1000; i++) {
    //随机得到一个合法的点
    var ranPt1 = recast.findRandomPoint();
    //console.log(ranPt1);

    var ranPt2 = recast.findRandomPoint();
    //console.log(ranPt2);

    //寻路
    var path1 = recast.findPath(ranPt1.x,ranPt1.y,ranPt1.z,ranPt2.x,ranPt2.y,ranPt2.z,1000);
    //console.log('findPath result1:');
    //console.dir(path1);

    //var path2 = sample_TempObstacles.findPath(ranPt2.x,ranPt2.y,ranPt2.z,ranPt1.x,ranPt1.y,ranPt1.z,1000);
    //console.log('findPath result2:');
    //console.dir(path2);
  }

  endTime = new Date().getTime();
  costTime = endTime - startTime;
  console.log('测试随机寻路1000次消耗时间:' + costTime + 'ms');
}

testRecast();
