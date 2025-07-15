btConvexHullShape *__thiscall btConvexHullShape::`scalar deleting destructor'(btConvexHullShape *this, char a2)
{
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_unscaledPoints);
  btPolyhedralConvexShape::~btPolyhedralConvexShape(this);
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
