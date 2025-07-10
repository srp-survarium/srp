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
  const btConvexShape *m_collisionShape; // ecx
  float m_ccdSweptSphereRadius; // xmm0_4
  float m_fraction; // xmm0_4
  const vostok::math::float4x4 *v15; // xmm1_4
  float v16; // xmm0_4
  const btConvexShape *v17; // ecx
  float v18; // xmm0_4
  const vostok::math::float4x4 *v19; // [esp+14C4h] [ebp-2A4h]
  btGjkConvexCast v20; // [esp+14C8h] [ebp-2A0h] BYREF
  void **v21; // [esp+14D8h] [ebp-290h] BYREF
  int v22; // [esp+14DCh] [ebp-28Ch]
  int v23; // [esp+14E0h] [ebp-288h]
  const vostok::math::float4x4 *v24; // [esp+14E8h] [ebp-280h]
  const vostok::math::float4x4 *v25; // [esp+14ECh] [ebp-27Ch]
  const vostok::math::float4x4 *v26; // [esp+14F0h] [ebp-278h]
  int v27; // [esp+14F4h] [ebp-274h]
  float v28; // [esp+14F8h] [ebp-270h]
  float v29; // [esp+1508h] [ebp-260h]
  btConvexCast::CastResult v30; // [esp+1518h] [ebp-250h] BYREF
  _BYTE v31[320]; // [esp+15D8h] [ebp-190h] BYREF
  float v32; // [esp+1718h] [ebp-50h]
  __int16 v33; // [esp+1738h] [ebp-30h]

  v5 = col0->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[2]
     - col0->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v6 = col0->m_interpolationWorldTransform.m_origin.mVec128.m128_f32[1]
     - col0->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v19 = clear_value;
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
  m_ccdSweptSphereRadius = col1->m_ccdSweptSphereRadius;
  v23 = 0;
  v30.m_debugDrawer = 0;
  v33 &= 0xFFF0u;
  v20.m_convexA = m_collisionShape;
  v20.m_simplexSolver = (btVoronoiSimplexSolver *)v31;
  v20.m_convexB = (const btConvexShape *)&v21;
  v28 = m_ccdSweptSphereRadius;
  v29 = m_ccdSweptSphereRadius;
  v24 = clear_value;
  v25 = clear_value;
  v26 = clear_value;
  v30.m_fraction = 9.9999998e17;
  v27 = 0;
  v21 = &btSphereShape::`vftable';
  v22 = 8;
  v30.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  v30.m_allowedPenetration = 0.0;
  v32 = FLOAT_0_000099999997;
  v20.__vftable = (btGjkConvexCast_vtbl *)&btGjkConvexCast::`vftable';
  if ( btGjkConvexCast::calcTimeOfImpact(
         &v20,
         &col0->m_worldTransform,
         &col0->m_interpolationWorldTransform,
         &col1->m_worldTransform,
         &col1->m_interpolationWorldTransform,
         &v30) )
  {
    m_fraction = v30.m_fraction;
    if ( col0->m_hitFraction > v30.m_fraction )
      col0->m_hitFraction = v30.m_fraction;
    if ( col1->m_hitFraction > m_fraction )
      col1->m_hitFraction = m_fraction;
    v15 = clear_value;
    if ( *(float *)&clear_value > m_fraction )
      *(float *)&v19 = m_fraction;
  }
  else
  {
    v15 = clear_value;
  }
  v23 = 0;
  v30.m_debugDrawer = 0;
  v16 = col0->m_ccdSweptSphereRadius;
  v17 = (const btConvexShape *)col1->m_collisionShape;
  v33 &= 0xFFF0u;
  v20.m_simplexSolver = (btVoronoiSimplexSolver *)v31;
  v28 = v16;
  v29 = v16;
  v24 = v15;
  v25 = v15;
  v26 = v15;
  v30.m_fraction = 9.9999998e17;
  v20.m_convexB = v17;
  v27 = 0;
  v21 = &btSphereShape::`vftable';
  v22 = 8;
  v30.__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  v30.m_allowedPenetration = 0.0;
  v32 = FLOAT_0_000099999997;
  v20.__vftable = (btGjkConvexCast_vtbl *)&btGjkConvexCast::`vftable';
  v20.m_convexA = (const btConvexShape *)&v21;
  if ( btGjkConvexCast::calcTimeOfImpact(
         &v20,
         &col0->m_worldTransform,
         &col0->m_interpolationWorldTransform,
         &col1->m_worldTransform,
         &col1->m_interpolationWorldTransform,
         &v30) )
  {
    v18 = v30.m_fraction;
    if ( col0->m_hitFraction > v30.m_fraction )
      col0->m_hitFraction = v30.m_fraction;
    if ( col1->m_hitFraction > v18 )
      col1->m_hitFraction = v18;
    if ( *(float *)&v19 > v18 )
      *(float *)&v19 = v18;
  }
  return *(float *)&v19;
}
