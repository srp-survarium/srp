btBoxBoxCollisionAlgorithm *__thiscall btBoxBoxCollisionAlgorithm::`vector deleting destructor'(
        btBoxBoxCollisionAlgorithm *this,
        char a2)
{
  btBoxBoxCollisionAlgorithm::~btBoxBoxCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
