btSphereTriangleCollisionAlgorithm *__thiscall btSphereTriangleCollisionAlgorithm::`vector deleting destructor'(
        btSphereTriangleCollisionAlgorithm *this,
        char a2)
{
  btSphereTriangleCollisionAlgorithm::~btSphereTriangleCollisionAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
