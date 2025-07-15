btGImpactCollisionAlgorithm *__thiscall btGImpactCollisionAlgorithm::`scalar deleting destructor'(
        btGImpactCollisionAlgorithm *this,
        char a2)
{
  btGImpactCollisionAlgorithm::~btGImpactCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
