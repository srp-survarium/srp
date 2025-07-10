char __thiscall btGjkConvexCast::calcTimeOfImpact(
        btGjkConvexCast *this,
        const btTransform *fromA,
        const btTransform *toA,
        const btTransform *fromB,
        const btTransform *toB,
        btConvexCast::CastResult *result)
{
  _DWORD *v6; // edx
  const btConvexShape *v7; // edi
  const btConvexShape *v8; // ecx
  unsigned __int64 v9; // xmm0_8
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  btVoronoiSimplexSolver *v20; // [esp+794h] [ebp-164h]
  float v21; // [esp+7ACh] [ebp-14Ch]
  int v22; // [esp+7B0h] [ebp-148h]
  float v23; // [esp+7B4h] [ebp-144h]
  float v24; // [esp+7B8h] [ebp-140h]
  float v25; // [esp+7BCh] [ebp-13Ch]
  float v26; // [esp+7C0h] [ebp-138h]
  btIDebugDraw debugDraw; // [esp+7C8h] [ebp-130h] BYREF
  btVector3 v28; // [esp+7D8h] [ebp-120h]
  btVector3 v29; // [esp+7E8h] [ebp-110h]
  float v30[2]; // [esp+7F8h] [ebp-100h] BYREF
  btTransform output; // [esp+808h] [ebp-F0h] BYREF
  unsigned __int64 v32; // [esp+848h] [ebp-B0h]
  unsigned __int64 v33; // [esp+850h] [ebp-A8h]
  btVector3 v34; // [esp+858h] [ebp-A0h]
  btVector3 v35; // [esp+868h] [ebp-90h]
  unsigned __int64 v36; // [esp+878h] [ebp-80h]
  unsigned __int64 v37; // [esp+880h] [ebp-78h]
  int v38; // [esp+888h] [ebp-70h]
  int v39; // [esp+88Ch] [ebp-6Ch]
  btGjkPairDetector v40; // [esp+898h] [ebp-60h] BYREF

  btVoronoiSimplexSolver::reset((btVoronoiSimplexSolver *)this, (int)this->m_simplexSolver);
  v7 = (const btConvexShape *)v6[3];
  v8 = (const btConvexShape *)v6[2];
  v24 = (float)(toA->m_origin.mVec128.m128_f32[0] - fromA->m_origin.mVec128.m128_f32[0])
      - (float)(toB->m_origin.mVec128.m128_f32[0] - fromB->m_origin.mVec128.m128_f32[0]);
  v20 = (btVoronoiSimplexSolver *)v6[1];
  v21 = 0.0;
  v25 = (float)(toA->m_origin.mVec128.m128_f32[1] - fromA->m_origin.mVec128.m128_f32[1])
      - (float)(toB->m_origin.mVec128.m128_f32[1] - fromB->m_origin.mVec128.m128_f32[1]);
  v26 = (float)(toA->m_origin.mVec128.m128_f32[2] - fromA->m_origin.mVec128.m128_f32[2])
      - (float)(toB->m_origin.mVec128.m128_f32[2] - fromB->m_origin.mVec128.m128_f32[2]);
  v23 = 0.0;
  v22 = 0;
  debugDraw.__vftable = (btIDebugDraw_vtbl *)&btPointCollector::`vftable';
  strcpy((char *)v30, "k\v^]");
  btGjkPairDetector::btGjkPairDetector(&v40, v8, v7, v20, 0);
  v38 = 1566444395;
  output = *fromA;
  v32 = fromB->m_basis.m_el[0].mVec128.m128_u64[0];
  v33 = fromB->m_basis.m_el[0].mVec128.m128_u64[1];
  v34.mVec128 = (__m128)fromB->m_basis.m_el[1];
  v35.mVec128 = (__m128)fromB->m_basis.m_el[2];
  v36 = fromB->m_origin.mVec128.m128_u64[0];
  v9 = fromB->m_origin.mVec128.m128_u64[1];
  v39 = 0;
  v37 = v9;
  btGjkPairDetector::getClosestPointsNonVirtual(
    (btGjkPairDetector *)&debugDraw,
    (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)&v40,
    (btDiscreteCollisionDetectorInterface::Result *)&output,
    &debugDraw);
  if ( LOBYTE(v30[1]) )
  {
    v10 = v30[0];
    if ( v30[0] <= 0.001 )
    {
LABEL_10:
      if ( (float)((float)((float)(v28.mVec128.m128_f32[2] * v26) + (float)(v28.mVec128.m128_f32[1] * v25))
                 + (float)(v28.mVec128.m128_f32[0] * v24)) < (float)-result->m_allowedPenetration )
      {
LABEL_11:
        result->m_fraction = v21;
        result->m_normal = (btVector3)v28.mVec128;
        result->m_hitPoint = (btVector3)v29.mVec128;
        return 1;
      }
    }
    else
    {
      while ( ++v22 <= 32 )
      {
        v11 = v21
            - (float)(v10
                    / (float)((float)((float)(v28.mVec128.m128_f32[2] * v26) + (float)(v28.mVec128.m128_f32[1] * v25))
                            + (float)(v28.mVec128.m128_f32[0] * v24)));
        v21 = v11;
        if ( v11 > *(float *)&clear_value )
          break;
        if ( v11 < 0.0 )
          break;
        if ( v23 >= v11 )
          break;
        v23 = v11;
        ((void (__thiscall *)(btConvexCast::CastResult *, _DWORD))result->DebugDraw)(result, LODWORD(v11));
        v12 = toA->m_origin.mVec128.m128_f32[1];
        output.m_origin.mVec128.m128_f32[0] = (float)(toA->m_origin.mVec128.m128_f32[0] * v11)
                                            + (float)(fromA->m_origin.mVec128.m128_f32[0]
                                                    * (float)(*(float *)&clear_value - v11));
        v13 = (float)(fromA->m_origin.mVec128.m128_f32[1] * (float)(*(float *)&clear_value - v11)) + (float)(v12 * v11);
        v14 = toA->m_origin.mVec128.m128_f32[2];
        output.m_origin.mVec128.m128_f32[1] = v13;
        v15 = (float)(fromA->m_origin.mVec128.m128_f32[2] * (float)(*(float *)&clear_value - v21)) + (float)(v14 * v21);
        v16 = fromB->m_origin.mVec128.m128_f32[0];
        output.m_origin.mVec128.m128_f32[2] = v15;
        v17 = (float)(toB->m_origin.mVec128.m128_f32[0] * v21) + (float)(v16 * (float)(*(float *)&clear_value - v21));
        v18 = toB->m_origin.mVec128.m128_f32[1];
        *(float *)&v36 = v17;
        *((float *)&v36 + 1) = (float)(fromB->m_origin.mVec128.m128_f32[1] * (float)(*(float *)&clear_value - v21))
                             + (float)(v18 * v21);
        *(float *)&v37 = (float)(fromB->m_origin.mVec128.m128_f32[2] * (float)(*(float *)&clear_value - v21))
                       + (float)(toB->m_origin.mVec128.m128_f32[2] * v21);
        btGjkPairDetector::getClosestPointsNonVirtual(
          (btGjkPairDetector *)&debugDraw,
          (const btDiscreteCollisionDetectorInterface::ClosestPointInput *)&v40,
          (btDiscreteCollisionDetectorInterface::Result *)&output,
          &debugDraw);
        if ( !LOBYTE(v30[1]) )
          break;
        v10 = v30[0];
        if ( v30[0] < 0.0 )
          goto LABEL_11;
        if ( v30[0] <= 0.001 )
          goto LABEL_10;
      }
    }
  }
  return 0;
}
