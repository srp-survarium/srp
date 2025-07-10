btPolyhedralConvexShape *__usercall btPolyhedralConvexShape::btPolyhedralConvexShape@<eax>(
        btPolyhedralConvexShape *this@<ecx>,
        btPolyhedralConvexShape *result@<eax>)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  v2 = clear_value;
  result->m_shapeType = 35;
  result->m_userPointer = 0;
  result->m_localScaling.mVec128.m128_i32[0] = (int)v2;
  result->m_localScaling.mVec128.m128_i32[1] = (int)v2;
  result->m_localScaling.mVec128.m128_i32[2] = (int)v2;
  result->m_localScaling.mVec128.m128_i32[3] = 0;
  result->m_collisionMargin = 0.039999999;
  result->__vftable = (btPolyhedralConvexShape_vtbl *)&btPolyhedralConvexShape::`vftable';
  result->m_polyhedron = 0;
  return result;
}
