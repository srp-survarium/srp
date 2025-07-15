btSoftBodyConcaveCollisionAlgorithm *__thiscall btSoftBodyConcaveCollisionAlgorithm::`vector deleting destructor'(
        btSoftBodyConcaveCollisionAlgorithm *this,
        char a2)
{
  btSoftBodyConcaveCollisionAlgorithm::~btSoftBodyConcaveCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
