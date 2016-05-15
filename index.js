/*
* @Author: pop
* @Date:   2016-05-15 15:25:15
* @Last Modified by:   pop
* @Last Modified time: 2016-05-15 16:04:17
*/

'use strict';

function Recast() {
  this.addon = require('bindings')('addon');
  this.buildContext = new this.addon.BuildContext();
  this.inputGeom = new this.addon.InputGeom();
  this.sample_TempObstacles = new this.addon.Sample_TempObstacles();
  //设置上下文
  this.sample_TempObstacles.setContext(this.buildContext);
  //设置输入网格
  this.sample_TempObstacles.setInputGeom(this.inputGeom);
}

Recast.prototype.setCellSize = function(val) {
  this.sample_TempObstacles.setCellSize(val);
};

Recast.prototype.setCellHeight = function(val) {
  this.sample_TempObstacles.setCellHeight(val);
};

Recast.prototype.setAgentHeight = function(val) {
  this.sample_TempObstacles.setAgentHeight(val);
};

Recast.prototype.setAgentRadius = function(val) {
  this.sample_TempObstacles.setAgentRadius(val);
};

Recast.prototype.setAgentMaxClimb = function(val) {
  this.sample_TempObstacles.setAgentMaxClimb(val);
};

Recast.prototype.setAgentMaxSlope = function(val) {
  this.sample_TempObstacles.setAgentMaxSlope(val);
};

Recast.prototype.setRegionMinSize = function(val) {
  this.sample_TempObstacles.setRegionMinSize(val);
};

Recast.prototype.setRegionMergeSize = function(val) {
  this.sample_TempObstacles.setRegionMergeSize(val);
};

Recast.prototype.setEdgeMaxLen = function(val) {
  this.sample_TempObstacles.setEdgeMaxLen(val);
};

Recast.prototype.setEdgeMaxError = function(val) {
  this.sample_TempObstacles.setEdgeMaxError(val);
};

Recast.prototype.setVertsPerPoly = function(val) {
  this.sample_TempObstacles.setVertsPerPoly(val);
};

Recast.prototype.setDetailSampleDist = function(val) {
  this.sample_TempObstacles.setDetailSampleDist(val);
};

Recast.prototype.setDetailSampleMaxError = function(val) {
  this.sample_TempObstacles.setDetailSampleMaxError(val);
};

Recast.prototype.setPartitionType = function(val) {
  this.sample_TempObstacles.setPartitionType(val);
};

Recast.prototype.setDefault = function() {
  //设置参数
  this.setCellSize(0.1);
  this.setCellHeight(0.2);
  this.setAgentHeight(2.0);
  //直径如果设置太大,会截断狭窄的地形
  //this.setAgentRadius(0.6);
  this.setAgentRadius(0.0);
  this.setAgentMaxClimb(0.9);
  this.setAgentMaxSlope(45.0);
  this.setRegionMinSize(8);
  this.setRegionMergeSize(20.0);
  this.setEdgeMaxLen(12.0);
  this.setEdgeMaxError(1.3);
  this.setVertsPerPoly(6);
  this.setDetailSampleDist(6.0);
  this.setDetailSampleMaxError(1.0);
  this.setPartitionType(0);
};

Recast.prototype.load = function(fileName) {
  return this.inputGeom.load(this.buildContext, fileName);
};

Recast.prototype.build = function() {
  return this.sample_TempObstacles.build();
};

Recast.prototype.addTempObstacle = function(x,y,z,radius,height) {
  return this.sample_TempObstacles.addTempObstacle(x,y,z,radius,height);
};

Recast.prototype.removeTempObstacle = function(ref) {
  return this.sample_TempObstacles.removeTempObstacle(ref);
};

Recast.prototype.clearAllTempObstacles = function() {
  return this.sample_TempObstacles.clearAllTempObstacles();
};

Recast.prototype.update = function(dt) {
 this.sample_TempObstacles.update(dt);
};

Recast.prototype.findRandomPoint = function() {
  return this.sample_TempObstacles.findRandomPoint();
};

Recast.prototype.findPath = function(x1,y1,z1,x2,y2,z2,maxPath) {
  return this.sample_TempObstacles.findPath(x1,y1,z1,x2,y2,z2,maxPath);
};


module.exports = Recast;



