btPolyhedralConvexAabbCachingShape *__thiscall btPolyhedralConvexAabbCachingShape::`scalar deleting destructor'(
        btPolyhedralConvexAabbCachingShape *this,
        char a2)
{
  btPolyhedralConvexShape::~btPolyhedralConvexShape(this);
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
