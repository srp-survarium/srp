void __thiscall btGImpactTriangleCallback::processTriangle(
        btGImpactTriangleCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  bool v5; // zf
  float margin; // xmm0_4
  btTriangleShape v7; // [esp+90h] [ebp-80h] BYREF

  btTriangleShape::btTriangleShape(&v7);
  v5 = !this->swapped;
  margin = this->margin;
  v7.__vftable = (btTriangleShape_vtbl *)&btTriangleShapeEx::`vftable';
  v7.m_collisionMargin = margin;
  if ( v5 )
  {
    this->algorithm->m_part1 = partId;
    this->algorithm->m_triface1 = triangleIndex;
  }
  else
  {
    this->algorithm->m_part0 = partId;
    this->algorithm->m_triface0 = triangleIndex;
  }
  btGImpactCollisionAlgorithm::gimpact_vs_shape(
    this->algorithm,
    this->body0,
    this->body1,
    this->gimpactshape0,
    &v7,
    this->swapped);
  v7.__vftable = (btTriangleShape_vtbl *)&btPolyhedralConvexShape::`vftable';
  if ( v7.m_polyhedron )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v7.m_polyhedron);
  }
}
