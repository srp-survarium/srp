btPolyhedralConvexAabbCachingShape *__usercall btPolyhedralConvexAabbCachingShape::btPolyhedralConvexAabbCachingShape@<eax>(
        btPolyhedralConvexAabbCachingShape *this@<ecx>,
        btPolyhedralConvexAabbCachingShape *result@<eax>)
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
  result->m_polyhedron = 0;
  result->__vftable = (btPolyhedralConvexAabbCachingShape_vtbl *)&btPolyhedralConvexAabbCachingShape::`vftable';
  result->m_localAabbMin.mVec128.m128_i32[0] = (int)v2;
  result->m_localAabbMin.mVec128.m128_i32[1] = (int)v2;
  result->m_localAabbMin.mVec128.m128_i32[2] = (int)v2;
  result->m_localAabbMin.mVec128.m128_i32[3] = 0;
  result->m_localAabbMax.mVec128.m128_i32[0] = -1082130432;
  result->m_localAabbMax.mVec128.m128_i32[1] = -1082130432;
  result->m_localAabbMax.mVec128.m128_i32[2] = -1082130432;
  result->m_localAabbMax.mVec128.m128_i32[3] = 0;
  result->m_isLocalAabbValid = 0;
  return result;
}
