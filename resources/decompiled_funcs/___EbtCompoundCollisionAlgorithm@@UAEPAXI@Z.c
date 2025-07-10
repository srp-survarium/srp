btCompoundCollisionAlgorithm *__thiscall btCompoundCollisionAlgorithm::`vector deleting destructor'(
        btCompoundCollisionAlgorithm *this,
        char a2)
{
  btCompoundCollisionAlgorithm::~btCompoundCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
