void __stdcall btTriangleShape::btTriangleShape(btTriangleShape *this)
{
  const btVector3 *p1; // edx
  const btVector3 *p2; // ecx
  const btVector3 *p0; // esi
  const vostok::math::float4x4 *v4; // xmm0_4

  v4 = clear_value;
  this->m_userPointer = 0;
  this->m_localScaling.mVec128.m128_i32[0] = (int)v4;
  this->m_localScaling.mVec128.m128_i32[1] = (int)v4;
  this->m_localScaling.mVec128.m128_u64[1] = (unsigned int)v4;
  this->m_collisionMargin = 0.039999999;
  this->m_polyhedron = 0;
  this->__vftable = (btTriangleShape_vtbl *)&btTriangleShape::`vftable';
  this->m_shapeType = 1;
  this->m_vertices1[0] = (btVector3)p0->mVec128;
  this->m_vertices1[1] = (btVector3)p1->mVec128;
  this->m_vertices1[2] = (btVector3)p2->mVec128;
}
