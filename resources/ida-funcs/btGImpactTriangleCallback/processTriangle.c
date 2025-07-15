void __thiscall btGImpactTriangleCallback::processTriangle(
        btGImpactTriangleCallback *this,
        btTriangleShape *triangle,
        int partId,
        int triangleIndex)
{
  bool v5; // zf
  float margin; // xmm0_4
  btGImpactCollisionAlgorithm *algorithm; // eax
  const btVector3 *v8; // [esp+0h] [ebp-90h]
  btPolyhedralConvexShape v9; // [esp+10h] [ebp-80h] BYREF

  btTriangleShape::btTriangleShape(triangle, &v9, &triangle->m_localScaling, &triangle->m_implicitShapeDimensions, v8);
  v5 = !this->swapped;
  margin = this->margin;
  algorithm = this->algorithm;
  v9.__vftable = (btPolyhedralConvexShape_vtbl *)&btTriangleShapeEx::`vftable';
  v9.m_collisionMargin = margin;
  if ( v5 )
  {
    algorithm->m_part1 = partId;
    this->algorithm->m_triface1 = triangleIndex;
  }
  else
  {
    algorithm->m_part0 = partId;
    this->algorithm->m_triface0 = triangleIndex;
  }
  btGImpactCollisionAlgorithm::gimpact_vs_shape(
    this->algorithm,
    this->body0,
    this->body1,
    (btStaticPlaneShape *)this->gimpactshape0,
    (btGImpactShapeInterface *)&v9,
    this->swapped);
  btPolyhedralConvexShape::~btPolyhedralConvexShape(&v9);
}
