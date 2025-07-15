btConvexPlaneCollisionAlgorithm::CreateFunc *__thiscall btSphereSphereCollisionAlgorithm::CreateFunc::`vector deleting destructor'(
        btConvexPlaneCollisionAlgorithm::CreateFunc *this,
        char a2)
{
  this->__vftable = (btConvexPlaneCollisionAlgorithm::CreateFunc_vtbl *)&btCollisionAlgorithmCreateFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
