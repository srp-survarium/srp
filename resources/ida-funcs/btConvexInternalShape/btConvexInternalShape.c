btConvexInternalShape *__usercall btConvexInternalShape::btConvexInternalShape@<eax>(
        btConvexInternalShape *this@<ecx>,
        btConvexInternalShape *result@<eax>)
{
  int v2; // xmm0_4

  result->m_userPointer = 0;
  v2 = LODWORD(s_bm_current_air_resistance);
  result->m_shapeType = 35;
  result->__vftable = (btConvexInternalShape_vtbl *)&btConvexInternalShape::`vftable';
  result->m_localScaling.mVec128.m128_i32[0] = v2;
  result->m_localScaling.mVec128.m128_i32[1] = v2;
  result->m_localScaling.mVec128.m128_i32[2] = v2;
  result->m_localScaling.mVec128.m128_i32[3] = 0;
  result->m_implicitShapeDimensions.mVec128.m128_i32[0] = 0;
  result->m_implicitShapeDimensions.mVec128.m128_i32[1] = 0;
  result->m_implicitShapeDimensions.mVec128.m128_i32[2] = 0;
  result->m_implicitShapeDimensions.mVec128.m128_i32[3] = 0;
  result->m_collisionMargin = FLOAT_0_039999999;
  return result;
}
