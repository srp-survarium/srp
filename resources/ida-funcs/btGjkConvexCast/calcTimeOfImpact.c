bool __thiscall btGjkConvexCast::calcTimeOfImpact(
        btGjkConvexCast *this,
        const btTransform *fromA,
        const btTransform *toA,
        const btTransform *fromB,
        btMatrix3x3 *toB,
        btConvexCast::CastResult *result)
{
  btConvexShape *m_convexB; // edi
  btConvexShape *m_convexA; // ecx
  btGjkPairDetector *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  int v18; // xmm3_4
  btVector3 *p_m_hitPoint; // edi
  int *v20; // edi
  bool v21; // al
  btVoronoiSimplexSolver *m_simplexSolver; // [esp+0h] [ebp-1A4h]
  float v23; // [esp+14h] [ebp-190h]
  int v24; // [esp+18h] [ebp-18Ch]
  float v25; // [esp+1Ch] [ebp-188h]
  float v26; // [esp+24h] [ebp-180h]
  float v27; // [esp+28h] [ebp-17Ch]
  float v28; // [esp+2Ch] [ebp-178h]
  btIDebugDraw v29[4]; // [esp+34h] [ebp-170h] BYREF
  btVector3 v30; // [esp+44h] [ebp-160h]
  int v31; // [esp+54h] [ebp-150h]
  int v32; // [esp+58h] [ebp-14Ch]
  int v33; // [esp+5Ch] [ebp-148h]
  int v34; // [esp+60h] [ebp-144h]
  float v35[2]; // [esp+64h] [ebp-140h] BYREF
  btTransform v36; // [esp+74h] [ebp-130h] BYREF
  btTransform v37; // [esp+B4h] [ebp-F0h]
  float v38; // [esp+F4h] [ebp-B0h]
  int v39; // [esp+F8h] [ebp-ACh]
  btDiscreteCollisionDetectorInterface::ClosestPointInput v40; // [esp+104h] [ebp-A0h] BYREF

  btVoronoiSimplexSolver::reset((btVoronoiSimplexSolver *)this, (int)this->m_simplexSolver);
  v24 = 0;
  v23 = 0.0;
  v26 = (float)(toA->m_origin.mVec128.m128_f32[0] - fromA->m_origin.mVec128.m128_f32[0])
      - (float)(toB[1].m_el[0].mVec128.m128_f32[0] - fromB->m_origin.mVec128.m128_f32[0]);
  v27 = (float)(toA->m_origin.mVec128.m128_f32[1] - fromA->m_origin.mVec128.m128_f32[1])
      - (float)(toB[1].m_el[0].mVec128.m128_f32[1] - fromB->m_origin.mVec128.m128_f32[1]);
  v28 = (float)(toA->m_origin.mVec128.m128_f32[2] - fromA->m_origin.mVec128.m128_f32[2])
      - (float)(toB[1].m_el[0].mVec128.m128_f32[2] - fromB->m_origin.mVec128.m128_f32[2]);
  v25 = 0.0;
  btMatrix3x3::setIdentity(toB, (int)&v40.m_transformB.m_basis.m_el[2]);
  m_simplexSolver = this->m_simplexSolver;
  m_convexB = (btConvexShape *)this->m_convexB;
  m_convexA = (btConvexShape *)this->m_convexA;
  v29[0].__vftable = (btIDebugDraw_vtbl *)&btPointCollector::`vftable';
  strcpy((char *)v35, "k\v^]");
  btGjkPairDetector::btGjkPairDetector((btGjkPairDetector *)&v40, m_convexA, m_convexB, 0, m_simplexSolver);
  v39 = 0;
  v38 = FLOAT_9_9999998e17;
  v36 = *fromA;
  v37 = *fromB;
  btGjkPairDetector::getClosestPointsNonVirtual(v9, &v40, (btDiscreteCollisionDetectorInterface::Result *)&v36, v29, 0);
  if ( !LOBYTE(v35[1]) )
    return 0;
  v10 = v35[0];
  while ( v10 > 0.001 )
  {
    if ( ++v24 > 32 )
      return 0;
    v11 = v23
        - (float)(v10
                / (float)((float)((float)(v30.mVec128.m128_f32[2] * v28) + (float)(v30.mVec128.m128_f32[1] * v27))
                        + (float)(v30.mVec128.m128_f32[0] * v26)));
    v23 = v11;
    if ( v11 > s_bm_current_air_resistance )
      return 0;
    if ( v11 < 0.0 )
      return 0;
    if ( v25 >= v11 )
      return 0;
    v25 = v11;
    ((void (__thiscall *)(btConvexCast::CastResult *, _DWORD))result->DebugDraw)(result, LODWORD(v11));
    v12 = toA->m_origin.mVec128.m128_f32[1];
    v36.m_origin.mVec128.m128_f32[0] = (float)(fromA->m_origin.mVec128.m128_f32[0]
                                             * (float)(s_bm_current_air_resistance - v11))
                                     + (float)(toA->m_origin.mVec128.m128_f32[0] * v11);
    v13 = (float)(fromA->m_origin.mVec128.m128_f32[1] * (float)(s_bm_current_air_resistance - v11)) + (float)(v12 * v11);
    v14 = toA->m_origin.mVec128.m128_f32[2];
    v36.m_origin.mVec128.m128_f32[1] = v13;
    v15 = (float)(fromA->m_origin.mVec128.m128_f32[2] * (float)(s_bm_current_air_resistance - v11)) + (float)(v14 * v11);
    v16 = fromB->m_origin.mVec128.m128_f32[0];
    v36.m_origin.mVec128.m128_f32[2] = v15;
    v17 = (float)(toB[1].m_el[0].mVec128.m128_f32[0] * v11) + (float)(v16 * (float)(s_bm_current_air_resistance - v11));
    v18 = toB[1].m_el[0].mVec128.m128_i32[1];
    v37.m_origin.mVec128.m128_f32[0] = v17;
    v37.m_origin.mVec128.m128_f32[1] = (float)(fromB->m_origin.mVec128.m128_f32[1]
                                             * (float)(s_bm_current_air_resistance - v11))
                                     + (float)(*(float *)&v18 * v11);
    v37.m_origin.mVec128.m128_f32[2] = (float)(fromB->m_origin.mVec128.m128_f32[2]
                                             * (float)(s_bm_current_air_resistance - v11))
                                     + (float)(toB[1].m_el[0].mVec128.m128_f32[2] * v11);
    btGjkPairDetector::getClosestPointsNonVirtual(
      (btGjkPairDetector *)toB,
      &v40,
      (btDiscreteCollisionDetectorInterface::Result *)&v36,
      v29,
      0);
    if ( !LOBYTE(v35[1]) )
      return 0;
    v10 = v35[0];
    if ( v35[0] < 0.0 )
    {
      result->m_fraction = v11;
      result->m_normal = (btVector3)v30.mVec128;
      p_m_hitPoint = &result->m_hitPoint;
      goto LABEL_12;
    }
  }
  if ( (float)((float)((float)(v30.mVec128.m128_f32[2] * v28) + (float)(v30.mVec128.m128_f32[1] * v27))
             + (float)(v30.mVec128.m128_f32[0] * v26)) >= COERCE_FLOAT(LODWORD(result->m_allowedPenetration) ^ _mask__NegFloat_) )
    return 0;
  result->m_normal = (btVector3)v30.mVec128;
  result->m_fraction = v23;
  p_m_hitPoint = &result->m_hitPoint;
LABEL_12:
  p_m_hitPoint->mVec128.m128_i32[0] = v31;
  v20 = &p_m_hitPoint->mVec128.m128_i32[1];
  *v20++ = v32;
  *v20 = v33;
  v21 = 1;
  v20[1] = v34;
  return v21;
}
