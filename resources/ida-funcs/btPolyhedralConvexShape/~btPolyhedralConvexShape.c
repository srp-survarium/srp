void __thiscall btPolyhedralConvexShape::~btPolyhedralConvexShape(btPolyhedralConvexShape *this)
{
  btConvexPolyhedron *m_polyhedron; // eax

  m_polyhedron = this->m_polyhedron;
  this->__vftable = (btPolyhedralConvexShape_vtbl *)&btPolyhedralConvexShape::`vftable';
  if ( m_polyhedron )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_polyhedron);
  }
  this->__vftable = (btPolyhedralConvexShape_vtbl *)&btCollisionShape::`vftable';
}
