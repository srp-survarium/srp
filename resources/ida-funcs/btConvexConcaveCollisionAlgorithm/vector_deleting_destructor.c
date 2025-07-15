btConvexConcaveCollisionAlgorithm *__thiscall btConvexConcaveCollisionAlgorithm::`vector deleting destructor'(
        btConvexConcaveCollisionAlgorithm *this,
        char a2)
{
  btConvexConcaveCollisionAlgorithm::~btConvexConcaveCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
