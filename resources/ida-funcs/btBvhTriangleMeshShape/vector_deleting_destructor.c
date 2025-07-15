btBvhTriangleMeshShape *__thiscall btBvhTriangleMeshShape::`vector deleting destructor'(
        btBvhTriangleMeshShape *this,
        char a2)
{
  btBvhTriangleMeshShape::~btBvhTriangleMeshShape(this);
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
