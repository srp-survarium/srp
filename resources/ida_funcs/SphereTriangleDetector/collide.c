bool __userpurge SphereTriangleDetector::collide@<al>(
        SphereTriangleDetector *this@<ecx>,
        int a2@<edi>,
        const btVector3 *a3@<esi>,
        const btVector3 *sphereCenter,
        btVector3 *point,
        btVector3 *resultNormal,
        float *depth,
        float *timeOfImpact,
        float contactBreakingThreshold)
{
  float *v9; // esi
  float v10; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float *v17; // esi
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm7_4
  unsigned int v25; // xmm0_4
  const btVector3 *v26; // ebx
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  int v34; // ebx
  float v35; // xmm0_4
  float v36; // xmm1_4
  float _X; // xmm0_4
  long double v38; // st7
  bool result; // al
  char v41; // [esp+37Dh] [ebp-6Dh]
  float v42; // [esp+37Eh] [ebp-6Ch]
  float v43; // [esp+382h] [ebp-68h]
  float v44; // [esp+382h] [ebp-68h]
  float v45; // [esp+382h] [ebp-68h]
  float v46; // [esp+386h] [ebp-64h]
  float v47; // [esp+38Ah] [ebp-60h]
  float v48; // [esp+38Ah] [ebp-60h]
  float v49; // [esp+38Ah] [ebp-60h]
  float v50; // [esp+38Eh] [ebp-5Ch]
  float v51; // [esp+38Eh] [ebp-5Ch]
  float v52; // [esp+392h] [ebp-58h]
  float v53; // [esp+392h] [ebp-58h]
  __m128i v54; // [esp+39Ah] [ebp-50h] BYREF
  btVector3 v55; // [esp+3AAh] [ebp-40h] BYREF
  btVector3 p; // [esp+3BAh] [ebp-30h] BYREF
  btVector3 to; // [esp+3CAh] [ebp-20h] BYREF
  btVector3 nearest; // [esp+3DAh] [ebp-10h] BYREF

  v46 = *(float *)(*(_DWORD *)(a2 + 4) + 32) * *(float *)(*(_DWORD *)(a2 + 4) + 16);
  v9 = *(float **)(a2 + 8);
  v10 = v9[20];
  v11 = v9[28];
  v12 = v9[21];
  v13 = v9[22];
  v14 = v9[24];
  v15 = v9[30];
  v16 = v9[25];
  v17 = v9 + 20;
  v42 = v46 + *(float *)&timeOfImpact;
  v18 = v17[9] - v12;
  v19 = v15 - v13;
  v20 = v14 - v10;
  v21 = v11 - v10;
  v47 = v10;
  v22 = v16 - v12;
  v23 = v17[6] - v13;
  v24 = v23 * v18;
  *(float *)&v25 = (float)(v18 * v20) - (float)(v22 * v21);
  v54.m128i_i64[1] = v25;
  *(float *)v54.m128i_i32 = (float)(v19 * v22) - v24;
  *(float *)&v54.m128i_i32[1] = (float)(v23 * v21) - (float)(v19 * v20);
  v26 = sphereCenter;
  v43 = 1.0
      / sqrtf(
          (float)((float)(*(float *)&v25 * *(float *)&v25)
                + (float)(*(float *)&v54.m128i_i32[1] * *(float *)&v54.m128i_i32[1]))
        + (float)(*(float *)v54.m128i_i32 * *(float *)v54.m128i_i32));
  v27 = *(float *)v54.m128i_i32 * v43;
  v28 = *(float *)&v54.m128i_i32[1] * v43;
  v29 = *(float *)&v25 * v43;
  v50 = sphereCenter->mVec128.m128_f32[0];
  v30 = sphereCenter->mVec128.m128_f32[0] - v47;
  v52 = sphereCenter->mVec128.m128_f32[2];
  v31 = v52 - v17[2];
  v48 = sphereCenter->mVec128.m128_f32[1];
  v32 = v48 - v17[1];
  v54.m128i_i64[0] = __PAIR64__(*(float *)&v54.m128i_i32[1] * v43, *(float *)v54.m128i_i32 * v43);
  *(float *)&v54.m128i_i32[2] = v29;
  v33 = (float)((float)(v31 * v29) + (float)(v32 * v28)) + (float)(v30 * v27);
  v44 = v33;
  if ( v33 < 0.0 )
  {
    v33 = v33 * -1.0;
    v44 = v33;
    *(float *)v54.m128i_i32 = v27 * -1.0;
    *(float *)&v54.m128i_i32[1] = v28 * -1.0;
    *(float *)&v54.m128i_i32[2] = v29 * -1.0;
  }
  v41 = 0;
  if ( v42 <= v33 )
    return 0;
  p.mVec128 = sphereCenter->mVec128;
  v55.mVec128 = (__m128)_mm_load_si128(&v54);
  if ( SphereTriangleDetector::pointInTriangle(&v55, &p, (SphereTriangleDetector *)v17, a3) )
  {
    p.mVec128.m128_f32[0] = v50 - (float)(*(float *)v54.m128i_i32 * v44);
    p.mVec128.m128_f32[1] = v48 - (float)(*(float *)&v54.m128i_i32[1] * v44);
    p.mVec128.m128_f32[2] = v52 - (float)(*(float *)&v54.m128i_i32[2] * v44);
    p.mVec128.m128_i32[3] = 0;
    v55.mVec128 = (__m128)_mm_load_si128((const __m128i *)&p);
  }
  else
  {
    v34 = 0;
    if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 8) + 92))(*(_DWORD *)(a2 + 8)) <= 0 )
      return 0;
    do
    {
      (*(void (__thiscall **)(_DWORD, int, btVector3 *, btVector3 *))(**(_DWORD **)(a2 + 8) + 96))(
        *(_DWORD *)(a2 + 8),
        v34,
        &p,
        &to);
      if ( (float)(v42 * v42) > SegmentSqrDistance(&to, sphereCenter, &nearest, &p) )
      {
        v41 = 1;
        v55.mVec128 = (__m128)_mm_load_si128((const __m128i *)&nearest);
      }
      ++v34;
    }
    while ( v34 < (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 8) + 92))(*(_DWORD *)(a2 + 8)) );
    if ( !v41 )
      return 0;
    v26 = sphereCenter;
  }
  v35 = v26->mVec128.m128_f32[2];
  v36 = v26->mVec128.m128_f32[0] - v55.mVec128.m128_f32[0];
  p.mVec128.m128_f32[1] = v26->mVec128.m128_f32[1] - v55.mVec128.m128_f32[1];
  p.mVec128.m128_i32[3] = 0;
  p.mVec128.m128_f32[2] = v35 - v55.mVec128.m128_f32[2];
  p.mVec128.m128_f32[0] = v36;
  _X = (float)((float)(p.mVec128.m128_f32[2] * p.mVec128.m128_f32[2])
             + (float)(p.mVec128.m128_f32[1] * p.mVec128.m128_f32[1]))
     + (float)(v36 * v36);
  if ( (float)(v42 * v42) <= _X )
    return 0;
  if ( _X <= 0.00000011920929 )
  {
    *(__m128i *)resultNormal = v54;
    *point = (btVector3)v55.mVec128;
    *depth = -v46;
    return 1;
  }
  else
  {
    *resultNormal = (btVector3)p.mVec128;
    v51 = resultNormal->mVec128.m128_f32[0];
    v49 = resultNormal->mVec128.m128_f32[1];
    v45 = resultNormal->mVec128.m128_f32[2];
    v53 = 1.0 / sqrtf((float)((float)(v51 * v51) + (float)(v49 * v49)) + (float)(v45 * v45));
    resultNormal->mVec128.m128_f32[0] = v51 * v53;
    resultNormal->mVec128.m128_f32[1] = v49 * v53;
    resultNormal->mVec128.m128_f32[2] = v45 * v53;
    *point = (btVector3)v55.mVec128;
    v38 = sqrtf(_X);
    result = 1;
    *depth = -(v46 - v38);
  }
  return result;
}
