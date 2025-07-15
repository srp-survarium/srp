btBridgedManifoldResult *__thiscall `btConvexConvexAlgorithm::processCollision'::`16'::btDummyResult::`vector deleting destructor'(
        btBridgedManifoldResult *this,
        char a2)
{
  this->__vftable = (btBridgedManifoldResult_vtbl *)&btDiscreteCollisionDetectorInterface::Result::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
