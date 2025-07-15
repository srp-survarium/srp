btConvexConvexAlgorithm *__thiscall btConvexConvexAlgorithm::`scalar deleting destructor'(
        btConvexConvexAlgorithm *this,
        char a2)
{
  btConvexConvexAlgorithm::~btConvexConvexAlgorithm(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
