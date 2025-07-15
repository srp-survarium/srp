btConvexPlaneCollisionAlgorithm *__thiscall btConvexPlaneCollisionAlgorithm::`scalar deleting destructor'(
        btConvexPlaneCollisionAlgorithm *this,
        char a2)
{
  btConvexPlaneCollisionAlgorithm::~btConvexPlaneCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
