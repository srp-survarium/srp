btManifoldResult *__thiscall `btConvexConvexAlgorithm::processCollision'::`16'::btDummyResult::`vector deleting destructor'(
        btManifoldResult *this,
        char a2)
{
  this->__vftable = (btManifoldResult_vtbl *)&btDiscreteCollisionDetectorInterface::Result::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
