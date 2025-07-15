btTriangleShapeEx *__thiscall btPolyhedralConvexAabbCachingShape::`scalar deleting destructor'(
        btTriangleShapeEx *this,
        char a2)
{
  btConvexPolyhedron *m_polyhedron; // eax

  m_polyhedron = this->m_polyhedron;
  this->__vftable = (btTriangleShapeEx_vtbl *)&btPolyhedralConvexShape::`vftable';
  if ( m_polyhedron )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_polyhedron);
  }
  this->__vftable = (btTriangleShapeEx_vtbl *)&btCollisionShape::`vftable';
  if ( (a2 & 1) != 0 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
