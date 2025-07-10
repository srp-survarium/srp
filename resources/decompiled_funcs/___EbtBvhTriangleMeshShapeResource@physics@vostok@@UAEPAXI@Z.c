vostok::physics::btBvhTriangleMeshShapeResource *__thiscall vostok::physics::btBvhTriangleMeshShapeResource::`vector deleting destructor'(
        vostok::physics::btBvhTriangleMeshShapeResource *this,
        char a2)
{
  vostok::physics::btBvhTriangleMeshShapeResource::~btBvhTriangleMeshShapeResource(this);
  if ( (a2 & 1) != 0 && this )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
