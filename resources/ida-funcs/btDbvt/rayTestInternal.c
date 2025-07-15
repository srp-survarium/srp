void __thiscall btDbvt::rayTestInternal<BroadphaseRayTester>(
        const btDbvtNode *root,
        const btVector3 *rayFrom,
        const btVector3 *rayDirectionInverse,
        const btVector3 *signs,
        btAlignedObjectArray<GrahamVector2> *lambda_max,
        float aabbMin,
        const btVector3 *aabbMax,
        const btVector3 *policy,
        BroadphaseRayTester *depth)
{
  _DWORD *v9; // eax
  _DWORD *v10; // edx
  int v11; // esi
  int v12; // ebx
  float v13; // xmm0_4
  btAlignedObjectArray<GrahamVector2> *v14; // ecx
  float v15; // xmm0_4
  int v16; // eax
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  unsigned int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  int v30; // edi
  int v31; // edx
  int v32; // esi
  _DWORD *v33; // eax
  _DWORD *v34; // eax
  char *v35; // ecx
  _DWORD *v36; // ecx
  int v37; // eax
  _DWORD *v38; // eax
  int v39; // edi
  int v40; // [esp+14h] [ebp-6Ch]
  _DWORD *v41; // [esp+18h] [ebp-68h]
  int v42; // [esp+1Ch] [ebp-64h]
  int v43; // [esp+1Ch] [ebp-64h]
  float v44; // [esp+24h] [ebp-5Ch]
  float v45; // [esp+28h] [ebp-58h]
  float v46; // [esp+30h] [ebp-50h]
  float v47; // [esp+38h] [ebp-48h]
  char v48[4]; // [esp+4Ch] [ebp-34h] BYREF
  int v49; // [esp+50h] [ebp-30h]
  int v50; // [esp+54h] [ebp-2Ch]
  void *ptr; // [esp+58h] [ebp-28h]
  char v52; // [esp+5Ch] [ebp-24h]
  float v53; // [esp+60h] [ebp-20h]
  float v54; // [esp+64h] [ebp-1Ch]
  float v55[2]; // [esp+68h] [ebp-18h]
  float v56; // [esp+70h] [ebp-10h]
  float v57; // [esp+74h] [ebp-Ch]
  float v58[2]; // [esp+78h] [ebp-8h]

  v40 = 1;
  v42 = 126;
  v9 = btAlignedAllocInternal(0x200u);
  v52 = 1;
  ptr = v9;
  v50 = 128;
  v10 = v9;
  v11 = 128;
  do
  {
    if ( v10 )
      *v10 = 0;
    ++v10;
    --v11;
  }
  while ( v11 );
  v49 = 128;
  *v9 = rayFrom;
  do
  {
    --v40;
    v12 = *((_DWORD *)ptr + v40);
    v44 = *(float *)(v12 + 4) - policy->mVec128.m128_f32[1];
    v45 = *(float *)(v12 + 8) - policy->mVec128.m128_f32[2];
    v13 = *(float *)(v12 + 16) - aabbMax->mVec128.m128_f32[0];
    v14 = lambda_max;
    v53 = *(float *)v12 - policy->mVec128.m128_f32[0];
    v54 = v44;
    v55[0] = v45;
    v46 = v13;
    v15 = *(float *)(v12 + 20) - aabbMax->mVec128.m128_f32[1];
    v55[1] = 0.0;
    v16 = *(_DWORD *)&lambda_max->m_allocator;
    v47 = *(float *)(v12 + 24) - aabbMax->mVec128.m128_f32[2];
    v56 = v46;
    v57 = v15;
    v58[0] = v47;
    v58[1] = 0.0;
    v17 = rayDirectionInverse->mVec128.m128_f32[1];
    v18 = signs->mVec128.m128_f32[1];
    v16 *= 16;
    v19 = *(float *)((char *)&v53 + v16);
    v20 = *(float *)((char *)&v56 - v16);
    v21 = 16 * lambda_max->m_size;
    v22 = (float)(v19 - rayDirectionInverse->mVec128.m128_f32[0]) * signs->mVec128.m128_f32[0];
    v23 = (float)(v20 - rayDirectionInverse->mVec128.m128_f32[0]) * signs->mVec128.m128_f32[0];
    v24 = (float)(v58[v21 / 0xFFFFFFFC - 1] - v17) * v18;
    v25 = (float)(v55[v21 / 4 - 1] - v17) * v18;
    if ( v22 <= v24 && v25 <= v23 )
    {
      if ( v25 > v22 )
        v22 = (float)(v55[v21 / 4 - 1] - v17) * v18;
      if ( v23 > v24 )
        v23 = (float)(v58[v21 / 0xFFFFFFFC - 1] - v17) * v18;
      v26 = rayDirectionInverse->mVec128.m128_f32[2];
      v27 = signs->mVec128.m128_f32[2];
      v14 = (btAlignedObjectArray<GrahamVector2> *)(16 * lambda_max->m_capacity);
      v28 = (float)(*(float *)((char *)v58 - (char *)v14) - v26) * v27;
      v29 = (float)(*(float *)((char *)v55 + (_DWORD)v14) - v26) * v27;
      if ( v22 <= v28 && v29 <= v23 )
      {
        if ( v29 > v22 )
          v22 = (float)(*(float *)((char *)v55 + (_DWORD)v14) - v26) * v27;
        if ( v23 > v28 )
          v23 = (float)(*(float *)((char *)v58 - (char *)v14) - v26) * v27;
        if ( aabbMin > v22 && v23 > 0.0 )
        {
          if ( *(_DWORD *)(v12 + 40) )
          {
            v30 = v40;
            if ( v40 > v42 )
            {
              v31 = v49;
              v32 = 2 * v49;
              if ( 2 * v49 > v49 )
              {
                if ( v50 < v32 )
                {
                  if ( v32 )
                  {
                    v33 = btAlignedAllocInternal(8 * v49);
                    v31 = v49;
                    v41 = v33;
                  }
                  else
                  {
                    v41 = 0;
                  }
                  if ( v31 > 0 )
                  {
                    v34 = v41;
                    v35 = (char *)((_BYTE *)ptr - (_BYTE *)v41);
                    v43 = v31;
                    do
                    {
                      if ( v34 )
                        *v34 = *(_DWORD *)((char *)v34 + (_DWORD)v35);
                      ++v34;
                      --v43;
                    }
                    while ( v43 );
                  }
                  if ( ptr )
                  {
                    btAlignedFreeInternal(ptr);
                    v31 = v49;
                  }
                  v30 = v40;
                  v52 = 1;
                  ptr = v41;
                  v50 = v32;
                }
                if ( v31 < v32 )
                {
                  v36 = (char *)ptr + 4 * v31;
                  v37 = v32 - v31;
                  do
                  {
                    if ( v36 )
                      *v36 = 0;
                    ++v36;
                    --v37;
                  }
                  while ( v37 );
                }
              }
              v49 = v32;
              v42 = v32 - 2;
            }
            v38 = ptr;
            *((_DWORD *)ptr + v30) = *(_DWORD *)(v12 + 36);
            v14 = *(btAlignedObjectArray<GrahamVector2> **)(v12 + 40);
            v39 = v30 + 1;
            v38[v39] = v14;
            v40 = v39 + 1;
          }
          else
          {
            depth->m_rayCallback->process(depth->m_rayCallback, *(const btBroadphaseProxy **)(v12 + 36));
          }
        }
      }
    }
  }
  while ( v40 );
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v14, (int)v48);
}
