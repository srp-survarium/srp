btPolyhedralConvexAabbCachingShape *__usercall btPolyhedralConvexAabbCachingShape::btPolyhedralConvexAabbCachingShape@<eax>(
        btPolyhedralConvexAabbCachingShape *this@<ecx>,
        btConvexInternalShape *a2@<eax>)
{
  btPolyhedralConvexAabbCachingShape *result; // eax
  int v3; // xmm0_4

  result = (btPolyhedralConvexAabbCachingShape *)btConvexInternalShape::btConvexInternalShape(this, a2);
  result->m_polyhedron = 0;
  v3 = LODWORD(s_bm_current_air_resistance);
  result->__vftable = (btPolyhedralConvexAabbCachingShape_vtbl *)&btPolyhedralConvexAabbCachingShape::`vftable';
  result->m_localAabbMin.mVec128.m128_i32[0] = v3;
  result->m_localAabbMin.mVec128.m128_i32[1] = v3;
  result->m_localAabbMin.mVec128.m128_i32[2] = v3;
  result->m_localAabbMin.mVec128.m128_i32[3] = 0;
  result->m_localAabbMax.mVec128.m128_f32[0] = FLOAT_N1_0;
  result->m_localAabbMax.mVec128.m128_f32[1] = FLOAT_N1_0;
  result->m_localAabbMax.mVec128.m128_f32[2] = FLOAT_N1_0;
  result->m_localAabbMax.mVec128.m128_i32[3] = 0;
  result->m_isLocalAabbValid = 0;
  return result;
}
