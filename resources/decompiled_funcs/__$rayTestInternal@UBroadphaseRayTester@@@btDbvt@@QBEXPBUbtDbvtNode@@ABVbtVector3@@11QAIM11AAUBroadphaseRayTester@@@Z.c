void __thiscall btDbvt::rayTestInternal<BroadphaseRayTester>(
        const btDbvtNode *root,
        const btDbvtNode *rayFrom,
        const btVector3 *rayDirectionInverse,
        const btVector3 *signs,
        unsigned int *lambda_max,
        float aabbMin,
        const btVector3 *aabbMax,
        const btVector3 *policy,
        BroadphaseRayTester *depth)
{
  int v9; // ebx
  const btDbvtNode **v10; // eax
  const btDbvtNode **v11; // edi
  int v12; // ecx
  const btDbvtNode *v13; // esi
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  unsigned int v17; // eax
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm5_4
  float v24; // xmm4_4
  unsigned int v25; // eax
  float v26; // xmm3_4
  float v27; // xmm1_4
  int v28; // ebx
  int v29; // eax
  int v30; // edx
  _DWORD *v31; // eax
  _DWORD *v32; // ebx
  _DWORD *v33; // eax
  int v34; // ecx
  const btDbvtNode **v35; // eax
  int v36; // ebx
  int v37; // [esp+13Ch] [ebp-70h]
  int v38; // [esp+140h] [ebp-6Ch]
  int v39; // [esp+144h] [ebp-68h]
  int v40; // [esp+144h] [ebp-68h]
  __m128i v41; // [esp+14Ch] [ebp-60h] BYREF
  __m128i v42; // [esp+15Ch] [ebp-50h] BYREF
  int v43; // [esp+17Ch] [ebp-30h]
  int v44; // [esp+180h] [ebp-2Ch]
  __m128i v45; // [esp+18Ch] [ebp-20h]
  __m128i v46; // [esp+19Ch] [ebp-10h]

  v9 = 1;
  ++gNumAlignedAllocs;
  v39 = 126;
  v10 = (const btDbvtNode **)sAlignedAllocFunc(0x200u, 16);
  v11 = v10;
  v44 = 128;
  v12 = 128;
  do
  {
    if ( v10 )
      *v10 = 0;
    ++v10;
    --v12;
  }
  while ( v12 );
  v43 = 128;
  *v11 = rayFrom;
  v41.m128i_i32[3] = 0;
  v42.m128i_i32[3] = 0;
  do
  {
    v13 = v11[v9 - 1];
    *(float *)v41.m128i_i32 = v13->volume.mi.mVec128.m128_f32[0] - policy->mVec128.m128_f32[0];
    *(float *)&v41.m128i_i32[1] = v13->volume.mi.mVec128.m128_f32[1] - policy->mVec128.m128_f32[1];
    v14 = rayDirectionInverse->mVec128.m128_f32[0];
    *(float *)&v41.m128i_i32[2] = v13->volume.mi.mVec128.m128_f32[2] - policy->mVec128.m128_f32[2];
    v45 = _mm_load_si128(&v41);
    v15 = signs->mVec128.m128_f32[0];
    v16 = signs->mVec128.m128_f32[1];
    *(float *)v42.m128i_i32 = v13->volume.mx.mVec128.m128_f32[0] - aabbMax->mVec128.m128_f32[0];
    *(float *)&v42.m128i_i32[1] = v13->volume.mx.mVec128.m128_f32[1] - aabbMax->mVec128.m128_f32[1];
    v37 = v9 - 1;
    v17 = 16 * *lambda_max;
    *(float *)&v42.m128i_i32[2] = v13->volume.mx.mVec128.m128_f32[2] - aabbMax->mVec128.m128_f32[2];
    v46 = _mm_load_si128(&v42);
    v18 = rayDirectionInverse->mVec128.m128_f32[1];
    v19 = (float)(*(float *)&v45.m128i_i32[v17 / 4] - v14) * v15;
    v20 = (float)(*(float *)&v46.m128i_i32[v17 / 0xFFFFFFFC] - v14) * v15;
    v21 = (float)(*(float *)&v46.m128i_i32[-4 * lambda_max[1] + 1] - v18) * v16;
    v22 = (float)(*(float *)&v45.m128i_i32[4 * lambda_max[1] + 1] - v18) * v16;
    if ( v19 > v21 || v22 > v20 )
      goto LABEL_43;
    if ( v22 > v19 )
      v19 = (float)(*(float *)&v45.m128i_i32[4 * lambda_max[1] + 1] - v18) * v16;
    if ( v20 > v21 )
      v20 = (float)(*(float *)&v46.m128i_i32[-4 * lambda_max[1] + 1] - v18) * v16;
    v23 = signs->mVec128.m128_f32[2];
    v24 = rayDirectionInverse->mVec128.m128_f32[2];
    v25 = 16 * lambda_max[2];
    v26 = (float)(*(float *)&v46.m128i_i32[v25 / 0xFFFFFFFC + 2] - v24) * v23;
    v27 = (float)(*(float *)&v45.m128i_i32[v25 / 4 + 2] - v24) * v23;
    if ( v19 > v26 || v27 > v20 )
      goto LABEL_43;
    if ( v27 > v19 )
      v19 = (float)(*(float *)&v45.m128i_i32[v25 / 4 + 2] - v24) * v23;
    if ( v20 > v26 )
      v20 = (float)(*(float *)&v46.m128i_i32[v25 / 0xFFFFFFFC + 2] - v24) * v23;
    if ( aabbMin <= v19 || v20 <= 0.0 )
      goto LABEL_43;
    if ( !v13->childs[1] )
    {
      depth->m_rayCallback->process(depth->m_rayCallback, (const btBroadphaseProxy *)v13->dataAsInt);
LABEL_43:
      --v9;
      continue;
    }
    v28 = v9 - 1;
    if ( v37 > v39 )
    {
      v29 = v43;
      v30 = 2 * v43;
      v40 = 2 * v43;
      if ( 2 * v43 > v43 )
      {
        if ( v44 < v30 )
        {
          if ( v30 )
          {
            ++gNumAlignedAllocs;
            v31 = sAlignedAllocFunc(8 * v43, 16);
            v30 = v40;
            v32 = v31;
          }
          else
          {
            v32 = 0;
          }
          if ( v43 > 0 )
          {
            v33 = v32;
            v38 = v43;
            do
            {
              if ( v33 )
                *v33 = *(_DWORD *)((char *)v33 + (char *)v11 - (char *)v32);
              ++v33;
              --v38;
            }
            while ( v38 );
          }
          if ( v11 )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v11);
            v30 = v40;
          }
          v29 = v43;
          v11 = (const btDbvtNode **)v32;
          v28 = v37;
          v44 = v30;
        }
        if ( v29 < v30 )
        {
          v34 = v30 - v43;
          v35 = &v11[v29];
          do
          {
            if ( v35 )
              *v35 = 0;
            ++v35;
            --v34;
          }
          while ( v34 );
        }
      }
      v43 = v30;
      v39 = v30 - 2;
    }
    v11[v28] = v13->childs[0];
    v36 = v28 + 1;
    v11[v36] = v13->childs[1];
    v9 = v36 + 1;
  }
  while ( v9 );
  if ( v11 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v11);
  }
}
