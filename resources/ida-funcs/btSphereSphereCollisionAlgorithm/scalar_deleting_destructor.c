btSphereSphereCollisionAlgorithm *__thiscall btSphereSphereCollisionAlgorithm::`scalar deleting destructor'(
        btSphereSphereCollisionAlgorithm *this,
        char a2)
{
  btSphereSphereCollisionAlgorithm::~btSphereSphereCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
