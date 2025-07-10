void __userpurge btQuantizedBvh::walkStacklessQuantizedTreeAgainstRay(
        btQuantizedBvh *this@<ecx>,
        int a2@<edi>,
        btNodeOverlapCallback *nodeCallback,
        const btVector3 *raySource,
        const btVector3 *rayTarget,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        int startNodeIndex,
        int endNodeIndex)
{
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  unsigned __int16 *v13; // esi
  long double v14; // st7
  const vostok::math::float4x4 *v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm6_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  unsigned int v23; // xmm1_4
  unsigned int v24; // xmm6_4
  float v25; // xmm4_4
  unsigned int v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  unsigned __int16 v33; // bx
  float v34; // xmm3_4
  unsigned __int16 v35; // ax
  float v36; // xmm2_4
  float v37; // xmm1_4
  unsigned __int16 v38; // cx
  int v39; // eax
  int v40; // eax
  int v41; // ecx
  float v42; // xmm5_4
  int v43; // edx
  float v44; // xmm6_4
  int v45; // eax
  float v46; // xmm1_4
  float v47; // xmm4_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  float v50; // xmm0_4
  float v51; // xmm3_4
  float v52; // xmm6_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  __m128 si128; // xmm4
  float v56; // xmm0_4
  unsigned int v57; // xmm3_4
  float v58; // xmm1_4
  float v59; // xmm1_4
  __m128i v60; // xmm2
  float v61; // xmm0_4
  float v62; // xmm2_4
  float v63; // xmm4_4
  float v64; // xmm1_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  float v67; // xmm3_4
  float v68; // xmm1_4
  unsigned __int8 v69; // al
  int v70; // eax
  bool v71; // [esp+509h] [ebp-99h]
  int v72; // [esp+50Ah] [ebp-98h]
  float v73; // [esp+50Eh] [ebp-94h]
  int v74; // [esp+50Eh] [ebp-94h]
  unsigned __int16 v75; // [esp+512h] [ebp-90h]
  unsigned __int16 v76; // [esp+514h] [ebp-8Eh]
  unsigned __int16 v77; // [esp+516h] [ebp-8Ch]
  unsigned __int16 v78; // [esp+51Ah] [ebp-88h]
  unsigned __int16 v79; // [esp+51Ch] [ebp-86h]
  unsigned __int16 v80; // [esp+51Eh] [ebp-84h]
  float v81; // [esp+522h] [ebp-80h]
  float v82; // [esp+526h] [ebp-7Ch]
  float v83; // [esp+526h] [ebp-7Ch]
  float v84; // [esp+52Ah] [ebp-78h]
  __m128i mVec128; // [esp+532h] [ebp-70h] BYREF
  float v86; // [esp+54Eh] [ebp-54h]
  btVector3 v87; // [esp+552h] [ebp-50h]
  __m128i v88; // [esp+562h] [ebp-40h]
  int v89; // [esp+57Eh] [ebp-24h]
  __m128 v90; // [esp+582h] [ebp-20h] BYREF
  BOOL v91; // [esp+592h] [ebp-10h]
  BOOL v92; // [esp+596h] [ebp-Ch]
  BOOL v93; // [esp+59Ah] [ebp-8h]
  float v94; // [esp+59Eh] [ebp-4h]

  v9 = rayTarget->mVec128.m128_f32[1];
  v10 = rayTarget->mVec128.m128_f32[2];
  v11 = rayTarget->mVec128.m128_f32[0];
  v72 = 0;
  v89 = 0;
  v12 = v10 - raySource->mVec128.m128_f32[2];
  v82 = v9 - raySource->mVec128.m128_f32[1];
  v13 = *(unsigned __int16 **)(a2 + 148);
  v94 = v11 - raySource->mVec128.m128_f32[0];
  v14 = sqrtf((float)((float)(v82 * v82) + (float)(v12 * v12)) + (float)(v94 * v94));
  v15 = clear_value;
  v73 = 1.0 / v14;
  v16 = v82 * v73;
  v17 = v12 * v73;
  v86 = (float)((float)((float)(v12 * v73) * v12) + (float)((float)(v82 * v73) * v82))
      + (float)(v94 * (float)(v94 * v73));
  if ( (float)(v94 * v73) == 0.0 )
    v81 = 9.9999998e17;
  else
    v81 = *(float *)&clear_value / (float)(v94 * v73);
  if ( v16 == 0.0 )
    v83 = 9.9999998e17;
  else
    v83 = *(float *)&clear_value / v16;
  if ( v17 == 0.0 )
    v84 = 9.9999998e17;
  else
    v84 = *(float *)&clear_value / v17;
  v91 = v81 < 0.0;
  v92 = v83 < 0.0;
  v93 = v84 < 0.0;
  v87.mVec128 = raySource->mVec128;
  v18 = v87.mVec128.m128_f32[0];
  mVec128 = (__m128i)raySource->mVec128;
  if ( v87.mVec128.m128_f32[0] > v11 )
    v18 = v11;
  v19 = v87.mVec128.m128_f32[1];
  if ( v87.mVec128.m128_f32[1] > rayTarget->mVec128.m128_f32[1] )
    v19 = rayTarget->mVec128.m128_f32[1];
  if ( v87.mVec128.m128_f32[2] > rayTarget->mVec128.m128_f32[2] )
    v87.mVec128.m128_i32[2] = rayTarget->mVec128.m128_i32[2];
  if ( v87.mVec128.m128_f32[3] > rayTarget->mVec128.m128_f32[3] )
    v87.mVec128.m128_i32[3] = rayTarget->mVec128.m128_i32[3];
  v20 = *(float *)mVec128.m128i_i32;
  if ( v11 > *(float *)mVec128.m128i_i32 )
    v20 = v11;
  v21 = *(float *)&mVec128.m128i_i32[1];
  if ( rayTarget->mVec128.m128_f32[1] > *(float *)&mVec128.m128i_i32[1] )
    v21 = rayTarget->mVec128.m128_f32[1];
  v22 = *(float *)&mVec128.m128i_i32[2];
  if ( rayTarget->mVec128.m128_f32[2] > *(float *)&mVec128.m128i_i32[2] )
    v22 = rayTarget->mVec128.m128_f32[2];
  if ( rayTarget->mVec128.m128_f32[3] > *(float *)&mVec128.m128i_i32[3] )
    mVec128.m128i_i32[3] = rayTarget->mVec128.m128_i32[3];
  *(float *)&v23 = aabbMin->mVec128.m128_f32[0] + v18;
  *(float *)&v24 = aabbMin->mVec128.m128_f32[1] + v19;
  v25 = aabbMin->mVec128.m128_f32[2] + v87.mVec128.m128_f32[2];
  *(float *)&v26 = v21 + aabbMax->mVec128.m128_f32[1];
  *(float *)&mVec128.m128i_i32[2] = v22 + aabbMax->mVec128.m128_f32[2];
  v87.mVec128.m128_u64[0] = __PAIR64__(v24, v23);
  v87.mVec128.m128_f32[2] = v25;
  v27 = aabbMax->mVec128.m128_f32[0];
  v90.m128_u64[0] = __PAIR64__(v24, v23);
  v90.m128_u64[1] = v87.mVec128.m128_u64[1];
  v28 = *(float *)(a2 + 16);
  v29 = v27 + v20;
  mVec128.m128i_i64[0] = __PAIR64__(v26, LODWORD(v29));
  if ( v28 <= *(float *)&v23 )
    v30 = v90.m128_f32[0];
  else
    v30 = v28;
  v31 = v90.m128_f32[1];
  if ( *(float *)(a2 + 20) > v90.m128_f32[1] )
    v31 = *(float *)(a2 + 20);
  v32 = v90.m128_f32[2];
  if ( *(float *)(a2 + 24) > v90.m128_f32[2] )
    v32 = *(float *)(a2 + 24);
  if ( v30 > *(float *)(a2 + 32) )
    v30 = *(float *)(a2 + 32);
  if ( v31 > *(float *)(a2 + 36) )
    v31 = *(float *)(a2 + 36);
  if ( v32 > *(float *)(a2 + 40) )
    v32 = *(float *)(a2 + 40);
  v78 = (int)(float)((float)(v30 - *(float *)(a2 + 16)) * *(float *)(a2 + 48)) & 0xFFFE;
  v33 = (int)(float)(*(float *)(a2 + 52) * (float)(v31 - *(float *)(a2 + 20))) & 0xFFFE;
  v34 = *(float *)(a2 + 16);
  v35 = (int)(float)(*(float *)(a2 + 56) * (float)(v32 - *(float *)(a2 + 24))) & 0xFFFE;
  v90 = (__m128)mVec128;
  v79 = v33;
  v80 = v35;
  if ( v34 <= v29 )
    v34 = v90.m128_f32[0];
  v36 = v90.m128_f32[1];
  if ( *(float *)(a2 + 20) > v90.m128_f32[1] )
    v36 = *(float *)(a2 + 20);
  v37 = v90.m128_f32[2];
  if ( *(float *)(a2 + 24) > v90.m128_f32[2] )
    v37 = *(float *)(a2 + 24);
  if ( v34 > *(float *)(a2 + 32) )
    v34 = *(float *)(a2 + 32);
  if ( v36 > *(float *)(a2 + 36) )
    v36 = *(float *)(a2 + 36);
  if ( v37 > *(float *)(a2 + 40) )
    v37 = *(float *)(a2 + 40);
  v75 = (int)(float)((float)(*(float *)(a2 + 48) * (float)(v34 - *(float *)(a2 + 16))) + *(float *)&clear_value) | 1;
  v76 = (int)(float)((float)(*(float *)(a2 + 52) * (float)(v36 - *(float *)(a2 + 20))) + *(float *)&clear_value) | 1;
  v77 = (int)(float)((float)(*(float *)(a2 + 56) * (float)(v37 - *(float *)(a2 + 24))) + *(float *)&clear_value) | 1;
  if ( startNodeIndex > 0 )
  {
    while ( 1 )
    {
      ++v89;
      v38 = v13[2];
      v74 = 0;
      v39 = v75 >= *v13 && v77 >= v38 && v76 >= v13[1] && v13[3] >= v78 && v13[4] >= v33 && v13[5] >= v35;
      v71 = *((_DWORD *)v13 + 3) >= 0;
      if ( (v39 | -v39) < 0 )
      {
        v40 = v38;
        v41 = v13[3];
        v42 = (float)v13[1];
        v43 = v13[4];
        v44 = (float)v40;
        v45 = v13[5];
        v46 = *(float *)&v15 / *(float *)(a2 + 48);
        v47 = *(float *)(a2 + 20);
        v90.m128_f32[0] = *(float *)(a2 + 16) + (float)((float)*v13 * v46);
        v48 = *(float *)&v15 / *(float *)(a2 + 52);
        v90.m128_f32[1] = v47 + (float)(v42 * v48);
        v49 = (float)v43 * v48;
        v50 = v90.m128_f32[0] - aabbMax->mVec128.m128_f32[0];
        v51 = *(float *)&v15 / *(float *)(a2 + 56);
        v52 = v44 * v51;
        v53 = (float)v45 * v51;
        v54 = *(float *)(a2 + 20);
        v90.m128_u64[1] = COERCE_UNSIGNED_INT(*(float *)(a2 + 24) + v52);
        si128 = (__m128)_mm_load_si128((const __m128i *)&v90);
        v87.mVec128 = si128;
        v87.mVec128.m128_f32[0] = v50;
        v87.mVec128.m128_f32[1] = si128.m128_f32[1] - aabbMax->mVec128.m128_f32[1];
        v56 = si128.m128_f32[2] - aabbMax->mVec128.m128_f32[2];
        *(float *)&mVec128.m128i_i32[1] = v54 + v49;
        *(float *)&v57 = *(float *)(a2 + 24) + v53;
        si128.m128_f32[0] = (float)v41 * v46;
        v58 = *(float *)(a2 + 16);
        v87.mVec128.m128_f32[2] = v56;
        *(float *)mVec128.m128i_i32 = v58 + si128.m128_f32[0];
        v59 = (float)(v58 + si128.m128_f32[0]) - aabbMin->mVec128.m128_f32[0];
        mVec128.m128i_i64[1] = v57;
        v60 = _mm_load_si128(&mVec128);
        v88 = v60;
        *(float *)&v88.m128i_i32[1] = *(float *)&v60.m128i_i32[1] - aabbMin->mVec128.m128_f32[1];
        *(float *)&v88.m128i_i32[2] = *(float *)&v60.m128i_i32[2] - aabbMin->mVec128.m128_f32[2];
        *(float *)v88.m128i_i32 = v59;
        v61 = (float)(v87.mVec128.m128_f32[4 * v91] - raySource->mVec128.m128_f32[0]) * v81;
        v62 = (float)(*(float *)&v88.m128i_i32[-4 * v91] - raySource->mVec128.m128_f32[0]) * v81;
        v63 = raySource->mVec128.m128_f32[1];
        v64 = (float)(*(float *)&v88.m128i_i32[-4 * v92 + 1] - v63) * v83;
        v65 = (float)(v87.mVec128.m128_f32[4 * v92 + 1] - v63) * v83;
        if ( v61 > v64 || v65 > v62 )
          goto LABEL_70;
        if ( v65 > v61 )
          v61 = (float)(v87.mVec128.m128_f32[4 * v92 + 1] - v63) * v83;
        if ( v62 > v64 )
          v62 = (float)(*(float *)&v88.m128i_i32[-4 * v92 + 1] - v63) * v83;
        v66 = raySource->mVec128.m128_f32[2];
        v67 = (float)(*(float *)&v88.m128i_i32[-4 * v93 + 2] - v66) * v84;
        v68 = (float)(v87.mVec128.m128_f32[4 * v93 + 2] - v66) * v84;
        if ( v61 > v67 || v68 > v62 )
          goto LABEL_70;
        if ( v68 > v61 )
          v61 = (float)(v87.mVec128.m128_f32[4 * v93 + 2] - v66) * v84;
        if ( v62 > v67 )
          v62 = (float)(*(float *)&v88.m128i_i32[-4 * v93 + 2] - v66) * v84;
        if ( v86 <= v61 || v62 <= 0.0 )
LABEL_70:
          v69 = 0;
        else
          v69 = 1;
        v74 = v69;
      }
      if ( !v71 )
        goto LABEL_75;
      if ( v74 )
        break;
LABEL_76:
      if ( !v71 )
      {
        v70 = -*((_DWORD *)v13 + 3);
        v13 -= 8 * *((_DWORD *)v13 + 3);
        v72 += v70;
        goto LABEL_79;
      }
LABEL_78:
      v13 += 8;
      ++v72;
LABEL_79:
      if ( v72 >= startNodeIndex )
        goto LABEL_80;
      v33 = v79;
      v35 = v80;
    }
    nodeCallback->processNode(
      nodeCallback,
      *((int *)v13 + 3) >> 21,
      ((unsigned int)&loc_1FFFFE + 1) & *((_DWORD *)v13 + 3));
    v15 = clear_value;
LABEL_75:
    if ( v74 )
      goto LABEL_78;
    goto LABEL_76;
  }
LABEL_80:
  if ( maxIterations < v89 )
    maxIterations = v89;
}
