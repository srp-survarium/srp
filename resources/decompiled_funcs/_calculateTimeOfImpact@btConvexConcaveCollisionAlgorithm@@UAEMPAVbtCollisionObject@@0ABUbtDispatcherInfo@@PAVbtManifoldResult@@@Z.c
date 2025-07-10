double __thiscall btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact(
        btConvexConcaveCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCollisionObject *v5; // edi
  float *v6; // esi
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm2_4
  float v15; // xmm6_4
  unsigned int v16; // xmm7_4
  float v17; // xmm6_4
  unsigned int v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  __m128i v21; // xmm6
  __m128i v22; // xmm6
  float v23; // xmm7_4
  float v24; // xmm7_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  unsigned int v27; // eax
  float v28; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm7_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  btCollisionShape *m_collisionShape; // ecx
  float m_hitFraction; // xmm0_4
  float v39; // [esp+8F0h] [ebp-200h]
  unsigned int v40; // [esp+8FCh] [ebp-1F4h]
  float ccdSphereRadius; // [esp+8FCh] [ebp-1F4h]
  __m128i v42; // [esp+900h] [ebp-1F0h] BYREF
  float v43; // [esp+918h] [ebp-1D8h]
  __int64 v44; // [esp+91Ch] [ebp-1D4h]
  __int64 v45; // [esp+924h] [ebp-1CCh]
  float v46; // [esp+92Ch] [ebp-1C4h]
  btTransform to; // [esp+930h] [ebp-1C0h] BYREF
  __m128i v48; // [esp+970h] [ebp-180h] BYREF
  __m128i v49; // [esp+980h] [ebp-170h] BYREF
  __m128i v50; // [esp+990h] [ebp-160h] BYREF
  __m128i v51; // [esp+9A0h] [ebp-150h] BYREF
  __m128i v52; // [esp+9B0h] [ebp-140h] BYREF
  float v53; // [esp+9CCh] [ebp-124h]
  btTransform from; // [esp+9D0h] [ebp-120h] BYREF
  btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback v55; // [esp+A10h] [ebp-E0h] BYREF

  v5 = body1;
  v6 = (float *)body1;
  if ( this->m_isSwapped )
    v5 = body0;
  else
    v6 = (float *)body0;
  v7 = v6[32] - v6[16];
  v8 = v6[34] - v6[18];
  v9 = v6[33] - v6[17];
  if ( (float)(v6[65] * v6[65]) > (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) )
    return 1.0;
  btTransform::inverse(&v5->m_worldTransform, &to);
  v10 = v6[17];
  v11 = v6[16];
  v12 = v6[18];
  *(float *)v52.m128i_i32 = (float)((float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * v11)
                                          + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v10))
                                  + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v12))
                          + to.m_origin.mVec128.m128_f32[0];
  v13 = (float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * v11) + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v10);
  v14 = to.m_basis.m_el[1].mVec128.m128_f32[2] * v12;
  v15 = v6[16];
  *(float *)&v52.m128i_i32[1] = (float)(v13 + v14) + to.m_origin.mVec128.m128_f32[1];
  *(float *)&v16 = (float)((float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v15)
                                 + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v10))
                         + (float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[18]))
                 + to.m_origin.mVec128.m128_f32[2];
  v17 = v6[6];
  v52.m128i_i64[1] = v16;
  *(float *)&v18 = (float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[14])
                         + (float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v17))
                 + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v6[10]);
  v19 = v6[8];
  v20 = v6[4];
  v43 = (float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v6[5])
              + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v6[9]))
      + (float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[13]);
  *(float *)&v45 = (float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v20)
                         + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v19))
                 + (float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[12]);
  *((float *)&v45 + 1) = (float)((float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * v6[6])
                               + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v6[10]))
                       + (float)(to.m_basis.m_el[1].mVec128.m128_f32[2] * v6[14]);
  v46 = (float)((float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * v6[5])
              + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v6[9]))
      + (float)(to.m_basis.m_el[1].mVec128.m128_f32[2] * v6[13]);
  *(float *)&v44 = (float)((float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * v6[4])
                         + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v6[8]))
                 + (float)(to.m_basis.m_el[1].mVec128.m128_f32[2] * v6[12]);
  *((float *)&v44 + 1) = (float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * v6[6])
                               + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v6[10]))
                       + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v6[14]);
  v53 = (float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * v6[5])
              + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v6[9]))
      + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v6[13]);
  *(float *)v49.m128i_i32 = (float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * v6[4])
                                  + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v6[8]))
                          + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v6[12]);
  *(float *)&v49.m128i_i32[1] = v53;
  v50.m128i_i64[0] = __PAIR64__(LODWORD(v46), v44);
  v49.m128i_i64[1] = HIDWORD(v44);
  v21 = _mm_load_si128(&v49);
  v50.m128i_i64[1] = HIDWORD(v45);
  from.m_basis.m_el[0] = (btVector3)v21;
  v22 = _mm_load_si128(&v50);
  v51.m128i_i64[0] = __PAIR64__(LODWORD(v43), v45);
  from.m_basis.m_el[1] = (btVector3)v22;
  v51.m128i_i64[1] = v18;
  from.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v51);
  from.m_origin = (btVector3)_mm_load_si128(&v52);
  *(float *)v42.m128i_i32 = (float)((float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * v6[32])
                                          + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v6[33]))
                                  + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v6[34]))
                          + to.m_origin.mVec128.m128_f32[0];
  *(float *)&v42.m128i_i32[1] = (float)((float)((float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * v6[32])
                                              + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v6[33]))
                                      + (float)(to.m_basis.m_el[1].mVec128.m128_f32[2] * v6[34]))
                              + to.m_origin.mVec128.m128_f32[1];
  *(float *)&v42.m128i_i32[2] = (float)((float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v6[32])
                                              + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v6[33]))
                                      + (float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[34]))
                              + to.m_origin.mVec128.m128_f32[2];
  v42.m128i_i32[3] = 0;
  *((float *)&v44 + 1) = (float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v6[22])
                               + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v6[26]))
                       + (float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[30]);
  v23 = v6[24];
  *(float *)&v44 = (float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v6[21])
                         + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v6[25]))
                 + (float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[29]);
  v22.m128i_i32[0] = (int)v6[22];
  v46 = (float)((float)(to.m_basis.m_el[2].mVec128.m128_f32[0] * v6[20])
              + (float)(to.m_basis.m_el[2].mVec128.m128_f32[1] * v23))
      + (float)(to.m_basis.m_el[2].mVec128.m128_f32[2] * v6[28]);
  *((float *)&v45 + 1) = (float)((float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * *(float *)v22.m128i_i32)
                               + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v6[26]))
                       + (float)(to.m_basis.m_el[1].mVec128.m128_f32[2] * v6[30]);
  v24 = v6[20];
  *(float *)&v45 = (float)((float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * v6[21])
                         + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v6[25]))
                 + (float)(to.m_basis.m_el[1].mVec128.m128_f32[2] * v6[29]);
  v25 = v6[24];
  v26 = v6[28];
  v22.m128i_i32[0] = (int)v6[22];
  v43 = (float)((float)(to.m_basis.m_el[1].mVec128.m128_f32[0] * v24)
              + (float)(to.m_basis.m_el[1].mVec128.m128_f32[1] * v25))
      + (float)(to.m_basis.m_el[1].mVec128.m128_f32[2] * v26);
  *(float *)&v40 = (float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * *(float *)v22.m128i_i32)
                         + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v6[26]))
                 + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v6[30]);
  *(float *)&v49.m128i_i32[1] = (float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * v6[21])
                                      + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v6[25]))
                              + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v6[29]);
  *(float *)v50.m128i_i32 = v43;
  *(__int64 *)((char *)v50.m128i_i64 + 4) = v45;
  *(float *)v51.m128i_i32 = v46;
  *(float *)v49.m128i_i32 = (float)((float)(to.m_basis.m_el[0].mVec128.m128_f32[0] * v24)
                                  + (float)(to.m_basis.m_el[0].mVec128.m128_f32[1] * v25))
                          + (float)(to.m_basis.m_el[0].mVec128.m128_f32[2] * v26);
  *(__int64 *)((char *)v51.m128i_i64 + 4) = v44;
  v49.m128i_i64[1] = v40;
  to.m_basis.m_el[0] = (btVector3)_mm_load_si128(&v49);
  v50.m128i_i32[3] = 0;
  to.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v50);
  v51.m128i_i32[3] = 0;
  to.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v51);
  v27 = v5->m_collisionShape->m_shapeType - 21;
  to.m_origin = (btVector3)_mm_load_si128(&v42);
  if ( v27 > 8 )
    return 1.0;
  v28 = *(float *)v42.m128i_i32;
  v48 = _mm_load_si128(&v52);
  if ( *(float *)v52.m128i_i32 <= *(float *)v42.m128i_i32 )
    v29 = *(float *)v48.m128i_i32;
  else
    v29 = *(float *)v42.m128i_i32;
  v30 = *(float *)&v48.m128i_i32[1];
  v31 = *(float *)&v42.m128i_i32[1];
  if ( *(float *)&v48.m128i_i32[1] > *(float *)&v42.m128i_i32[1] )
    v30 = *(float *)&v42.m128i_i32[1];
  v32 = *(float *)&v48.m128i_i32[2];
  v33 = *(float *)&v42.m128i_i32[2];
  if ( *(float *)&v48.m128i_i32[2] > *(float *)&v42.m128i_i32[2] )
    v32 = *(float *)&v42.m128i_i32[2];
  if ( *(float *)&v48.m128i_i32[3] > 0.0 )
    v48.m128i_i32[3] = 0;
  v42 = _mm_load_si128(&v52);
  if ( v28 <= *(float *)v52.m128i_i32 )
    v28 = *(float *)v42.m128i_i32;
  v34 = *(float *)&v42.m128i_i32[1];
  if ( v31 > *(float *)&v42.m128i_i32[1] )
    v34 = v31;
  v35 = *(float *)&v42.m128i_i32[2];
  if ( v33 > *(float *)&v42.m128i_i32[2] )
    v35 = v33;
  if ( *(float *)&v42.m128i_i32[3] < 0.0 )
    v42.m128i_i32[3] = 0;
  ccdSphereRadius = v6[64];
  *(float *)v48.m128i_i32 = v29 - ccdSphereRadius;
  *(float *)&v48.m128i_i32[1] = v30 - ccdSphereRadius;
  *(float *)&v48.m128i_i32[2] = v32 - ccdSphereRadius;
  *(float *)v42.m128i_i32 = v28 + ccdSphereRadius;
  *(float *)&v42.m128i_i32[1] = v34 + ccdSphereRadius;
  *(float *)&v42.m128i_i32[2] = v35 + ccdSphereRadius;
  btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact_::_5_::LocalTriangleSphereCastCallback::LocalTriangleSphereCastCallback(
    &from,
    &to,
    &v55,
    ccdSphereRadius,
    v39);
  m_collisionShape = v5->m_collisionShape;
  m_hitFraction = v6[63];
  v55.m_hitFraction = m_hitFraction;
  if ( m_collisionShape )
  {
    ((void (__thiscall *)(btCollisionShape *, btConvexConcaveCollisionAlgorithm::calculateTimeOfImpact::__l5::LocalTriangleSphereCastCallback *, __m128i *, __m128i *))m_collisionShape->__vftable[1].~btCollisionShape)(
      m_collisionShape,
      &v55,
      &v48,
      &v42);
    m_hitFraction = v55.m_hitFraction;
  }
  if ( v6[63] <= m_hitFraction )
    return 1.0;
  v6[63] = m_hitFraction;
  return v55.m_hitFraction;
}
