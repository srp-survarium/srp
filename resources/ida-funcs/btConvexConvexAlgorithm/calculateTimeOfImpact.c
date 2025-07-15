double __thiscall btConvexConvexAlgorithm::calculateTimeOfImpact(
        btConvexConvexAlgorithm *this,
        btCollisionObject *col0,
        btCollisionObject *col1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  btSphereShape *v12; // ecx
  float m_fraction; // xmm0_4
  float v14; // xmm0_4
  float v15; // [esp+1Ch] [ebp-2A8h]
  const btConvexShape *m_collisionShape; // [esp+20h] [ebp-2A4h]
  const btConvexShape *v17; // [esp+20h] [ebp-2A4h]
  btGjkConvexCast v18; // [esp+24h] [ebp-2A0h] BYREF
  btConvexCast::CastResult result; // [esp+34h] [ebp-290h] BYREF
  _BYTE v20[64]; // [esp+F4h] [ebp-1D0h] BYREF
  _BYTE v21[320]; // [esp+134h] [ebp-190h] BYREF
  float v22; // [esp+274h] [ebp-50h]
  __int16 v23; // [esp+294h] [ebp-30h]

  v5 = col0->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[2]
     - col0->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v6 = col0->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[1]
     - col0->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v15 = s_bm_current_air_resistance;
  v7 = col0->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[0]
     - col0->m_worldTransform.m_origin.mVec128.m128_f32[0];
  if ( (float)(col0->m_ccdMotionThreshold * col0->m_ccdMotionThreshold) > (float)((float)((float)(v5 * v5)
                                                                                        + (float)(v6 * v6))
                                                                                + (float)(v7 * v7)) )
  {
    v8 = col1->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[0]
       - col1->m_worldTransform.m_origin.mVec128.m128_f32[0];
    v9 = col1->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[1]
       - col1->m_worldTransform.m_origin.mVec128.m128_f32[1];
    v10 = col1->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[2]
        - col1->m_worldTransform.m_origin.mVec128.m128_f32[2];
    if ( (float)(col1->m_ccdMotionThreshold * col1->m_ccdMotionThreshold) > (float)((float)((float)(v10 * v10)
                                                                                          + (float)(v9 * v9))
                                                                                  + (float)(v8 * v8)) )
      return 1.0;
  }
  if ( disableCcd )
    return 1.0;
  m_collisionShape = (const btConvexShape *)col0->m_collisionShape;
  btSphereShape::btSphereShape((btSphereShape *)this, col1->m_ccdSweptSphereRadius);
  result.m_debugDrawer = 0;
  v23 &= ~1u;
  v23 &= ~2u;
  v23 &= ~4u;
  v23 &= ~8u;
  v18.m_simplexSolver = (btVoronoiSimplexSolver *)v21;
  v18.m_convexA = m_collisionShape;
  v18.m_convexB = (const btConvexShape *)v20;
  result.m_fraction = FLOAT_9_9999998e17;
  result.m_allowedPenetration = 0.0;
  result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  v22 = FLOAT_0_000099999997;
  v18.__vftable = (btGjkConvexCast_vtbl *)&btGjkConvexCast::`vftable';
  if ( btGjkConvexCast::calcTimeOfImpact(
         &v18,
         &col0->m_worldTransform,
         &col0->m_interpolationWorldTransform,
         &col1->m_worldTransform,
         (btGjkPairDetector *)&col1->m_interpolationWorldTransform,
         &result) )
  {
    m_fraction = result.m_fraction;
    if ( col0->m_hitFraction > result.m_fraction )
      col0->m_hitFraction = result.m_fraction;
    if ( col1->m_hitFraction > m_fraction )
      col1->m_hitFraction = m_fraction;
    if ( s_bm_current_air_resistance > m_fraction )
      v15 = m_fraction;
  }
  v17 = (const btConvexShape *)col1->m_collisionShape;
  btSphereShape::btSphereShape(v12, col0->m_ccdSweptSphereRadius);
  result.m_debugDrawer = 0;
  v23 &= ~1u;
  v23 &= ~2u;
  v23 &= ~4u;
  v23 &= ~8u;
  v18.m_simplexSolver = (btVoronoiSimplexSolver *)v21;
  v18.m_convexA = (const btConvexShape *)v20;
  v18.m_convexB = v17;
  result.m_fraction = FLOAT_9_9999998e17;
  result.m_allowedPenetration = 0.0;
  result.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  v22 = FLOAT_0_000099999997;
  v18.__vftable = (btGjkConvexCast_vtbl *)&btGjkConvexCast::`vftable';
  if ( btGjkConvexCast::calcTimeOfImpact(
         &v18,
         &col0->m_worldTransform,
         &col0->m_interpolationWorldTransform,
         &col1->m_worldTransform,
         (btGjkPairDetector *)&col1->m_interpolationWorldTransform,
         &result) )
  {
    v14 = result.m_fraction;
    if ( col0->m_hitFraction > result.m_fraction )
      col0->m_hitFraction = result.m_fraction;
    if ( col1->m_hitFraction > v14 )
      col1->m_hitFraction = v14;
    if ( v15 > v14 )
      return v14;
  }
  return v15;
}
