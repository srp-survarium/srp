void __usercall btDbvt::rayTest<btSoftBody::RayFromToCaster>(
        const btVector3 *rayTo@<eax>,
        const btDbvtNode *root,
        const btVector3 *rayFrom,
        btSoftBody::RayFromToCaster *policy)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  BOOL v11; // esi
  int v12; // edi
  char *v13; // eax
  char *v14; // ebx
  int v15; // ecx
  int v16; // ecx
  __int64 *v17; // esi
  float v18; // xmm1_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  int v27; // edx
  _DWORD *v28; // eax
  _DWORD *v29; // edi
  _DWORD *v30; // eax
  char *v31; // eax
  int v32; // ecx
  int v33; // edi
  btSoftBody::Face *v34; // ebx
  float v35; // xmm0_4
  btSoftBody::RayFromToCaster *v36; // eax
  float v37; // [esp+2BCh] [ebp-80h]
  int v38; // [esp+2BCh] [ebp-80h]
  float v39; // [esp+2C0h] [ebp-7Ch]
  int v40; // [esp+2C0h] [ebp-7Ch]
  float v41; // [esp+2C4h] [ebp-78h]
  int v42; // [esp+2C4h] [ebp-78h]
  int v43; // [esp+2C4h] [ebp-78h]
  float v44; // [esp+2C8h] [ebp-74h]
  float *v45; // [esp+2D0h] [ebp-6Ch]
  float *v46; // [esp+2D4h] [ebp-68h]
  float v47; // [esp+2D8h] [ebp-64h]
  float m_mint; // [esp+2DCh] [ebp-60h]
  BOOL v49; // [esp+2E0h] [ebp-5Ch]
  BOOL v50; // [esp+2E8h] [ebp-54h]
  float v51; // [esp+2F0h] [ebp-4Ch]
  float v52; // [esp+2F4h] [ebp-48h]
  int v53; // [esp+30Ch] [ebp-30h]
  int v54; // [esp+310h] [ebp-2Ch]
  char *v55; // [esp+314h] [ebp-28h]
  __int64 v56; // [esp+31Ch] [ebp-20h] BYREF
  __int64 v57; // [esp+324h] [ebp-18h]
  __int64 v58; // [esp+32Ch] [ebp-10h] BYREF
  __int64 v59; // [esp+334h] [ebp-8h]

  if ( root )
  {
    v4 = rayTo->mVec128.m128_f32[2] - rayFrom->mVec128.m128_f32[2];
    v37 = rayTo->mVec128.m128_f32[1] - rayFrom->mVec128.m128_f32[1];
    v39 = rayTo->mVec128.m128_f32[0] - rayFrom->mVec128.m128_f32[0];
    v44 = v4;
    v41 = 1.0 / sqrtf((float)((float)(v37 * v37) + (float)(v4 * v4)) + (float)(v39 * v39));
    v5 = v39 * v41;
    v6 = v37 * v41;
    v7 = v4 * v41;
    if ( (float)(v39 * v41) == 0.0 )
      v8 = 9.9999998e17;
    else
      v8 = *(float *)&clear_value / v5;
    if ( v6 == 0.0 )
      v9 = 9.9999998e17;
    else
      v9 = *(float *)&clear_value / v6;
    v51 = v9;
    if ( v7 == 0.0 )
      v10 = 9.9999998e17;
    else
      v10 = *(float *)&clear_value / v7;
    v52 = v10;
    v49 = v8 < 0.0;
    v11 = v9 < 0.0;
    v50 = v10 < 0.0;
    ++gNumAlignedAllocs;
    v47 = (float)((float)(v37 * v6) + (float)(v44 * v7)) + (float)(v39 * v5);
    v12 = 1;
    v42 = 126;
    v13 = (char *)sAlignedAllocFunc(0x200u, 16);
    v14 = v13;
    v55 = v13;
    v54 = 128;
    v15 = 128;
    do
    {
      if ( v13 )
        *(_DWORD *)v13 = 0;
      v13 += 4;
      --v15;
    }
    while ( v15 );
    *(_DWORD *)v14 = root;
    v45 = (float *)&v56 + 4 * v11 + 1;
    v16 = 128;
    v53 = 128;
    v46 = (float *)&v58 - 4 * v11 + 1;
    do
    {
      v17 = *(__int64 **)&v14[4 * v12 - 4];
      v18 = rayFrom->mVec128.m128_f32[0];
      v19 = rayFrom->mVec128.m128_f32[1];
      v56 = *v17;
      --v12;
      v57 = v17[1];
      v58 = v17[2];
      v59 = v17[3];
      v20 = (float)(*((float *)&v56 + 4 * v49) - v18) * v8;
      v21 = (float)(*((float *)&v58 - 4 * v49) - v18) * v8;
      v22 = (float)(*v46 - v19) * v51;
      v38 = v12;
      v23 = (float)(*v45 - v19) * v51;
      if ( v20 <= v22 && v23 <= v21 )
      {
        if ( v23 > v20 )
          v20 = (float)(*v45 - v19) * v51;
        if ( v21 > v22 )
          v21 = (float)(*v46 - v19) * v51;
        v24 = rayFrom->mVec128.m128_f32[2];
        v25 = (float)(*((float *)&v59 - 4 * v50) - v24) * v52;
        v26 = (float)(*((float *)&v57 + 4 * v50) - v24) * v52;
        if ( v20 <= v25 && v26 <= v21 )
        {
          if ( v26 > v20 )
            v20 = (float)(*((float *)&v57 + 4 * v50) - v24) * v52;
          if ( v21 > v25 )
            v21 = (float)(*((float *)&v59 - 4 * v50) - v24) * v52;
          if ( v47 > v20 && v21 > 0.0 )
          {
            if ( *((_DWORD *)v17 + 10) )
            {
              if ( v12 > v42 )
              {
                v27 = 2 * v16;
                v43 = 2 * v16;
                if ( 2 * v16 > v16 )
                {
                  if ( v54 < v27 )
                  {
                    if ( v27 )
                    {
                      ++gNumAlignedAllocs;
                      v28 = sAlignedAllocFunc(8 * v16, 16);
                      v27 = v43;
                      v29 = v28;
                    }
                    else
                    {
                      v29 = 0;
                    }
                    if ( v53 > 0 )
                    {
                      v30 = v29;
                      v40 = v53;
                      do
                      {
                        if ( v30 )
                          *v30 = *(_DWORD *)((char *)v30 + v14 - (char *)v29);
                        ++v30;
                        --v40;
                      }
                      while ( v40 );
                    }
                    if ( v14 )
                    {
                      ++gNumAlignedFree;
                      sAlignedFreeFunc(v14);
                      v27 = v43;
                    }
                    v16 = v53;
                    v55 = (char *)v29;
                    v14 = (char *)v29;
                    v12 = v38;
                    v54 = v27;
                  }
                  if ( v16 < v27 )
                  {
                    v31 = &v14[4 * v16];
                    v32 = v27 - v53;
                    do
                    {
                      if ( v31 )
                        *(_DWORD *)v31 = 0;
                      v31 += 4;
                      --v32;
                    }
                    while ( v32 );
                    v12 = v38;
                  }
                }
                v53 = v27;
                v16 = v27;
                v42 = v27 - 2;
              }
              *(_DWORD *)&v14[4 * v12] = *((_DWORD *)v17 + 9);
              v33 = v12 + 1;
              *(_DWORD *)&v14[4 * v33] = *((_DWORD *)v17 + 10);
              v12 = v33 + 1;
            }
            else
            {
              v34 = (btSoftBody::Face *)*((_DWORD *)v17 + 9);
              m_mint = policy->m_mint;
              v35 = btSoftBody::RayFromToCaster::rayFromToTriangle(
                      &policy->m_rayFrom,
                      &v34->m_n[0]->m_x,
                      &v34->m_n[1]->m_x,
                      &v34->m_n[2]->m_x,
                      &policy->m_rayNormalizedDirection,
                      (const btVector3 *)LODWORD(m_mint));
              if ( v35 <= 0.0 || m_mint <= v35 )
              {
                v36 = policy;
              }
              else
              {
                v36 = policy;
                policy->m_mint = v35;
                policy->m_face = v34;
              }
              ++v36->m_tests;
              v14 = v55;
              v16 = v53;
            }
          }
        }
      }
    }
    while ( v12 );
    if ( v14 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v14);
    }
  }
}
