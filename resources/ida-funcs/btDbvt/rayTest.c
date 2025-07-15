void __usercall btDbvt::rayTest<btSoftBody::RayFromToCaster>(
        const btVector3 *rayTo@<eax>,
        const btDbvtNode *root,
        const btVector3 *rayFrom,
        btSoftBody::RayFromToCaster *policy)
{
  float v4; // xmm5_4
  float v5; // xmm6_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  char *v13; // eax
  char *v14; // edx
  char *v15; // esi
  int v16; // edi
  float *v17; // ecx
  int *v18; // ebx
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  int v23; // ecx
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  int v30; // edi
  int v31; // esi
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  int v34; // eax
  int v35; // edi
  btSoftBody::Face *v36; // ebx
  float v37; // xmm0_4
  btSoftBody::RayFromToCaster *v38; // eax
  int v39; // [esp+0h] [ebp-94h]
  int v40; // [esp+14h] [ebp-80h]
  _DWORD *v41; // [esp+18h] [ebp-7Ch]
  float m_mint; // [esp+18h] [ebp-7Ch]
  int v43; // [esp+1Ch] [ebp-78h]
  int v44; // [esp+1Ch] [ebp-78h]
  float *v45; // [esp+28h] [ebp-6Ch]
  float *v46; // [esp+2Ch] [ebp-68h]
  float v47; // [esp+30h] [ebp-64h]
  BOOL v48; // [esp+38h] [ebp-5Ch]
  BOOL v49; // [esp+3Ch] [ebp-58h]
  BOOL v50; // [esp+40h] [ebp-54h]
  float v51; // [esp+44h] [ebp-50h]
  float v52; // [esp+48h] [ebp-4Ch]
  char v53[4]; // [esp+54h] [ebp-40h] BYREF
  int v54; // [esp+58h] [ebp-3Ch]
  int v55; // [esp+5Ch] [ebp-38h]
  void *ptr; // [esp+60h] [ebp-34h]
  char v57; // [esp+64h] [ebp-30h]
  int v58; // [esp+74h] [ebp-20h]
  int v59; // [esp+78h] [ebp-1Ch] BYREF
  _DWORD v60[2]; // [esp+7Ch] [ebp-18h]
  int v61; // [esp+84h] [ebp-10h] BYREF
  int v62; // [esp+88h] [ebp-Ch] BYREF
  _DWORD v63[2]; // [esp+8Ch] [ebp-8h]

  if ( root )
  {
    v4 = rayTo->mVec128.m128_f32[1] - rayFrom->mVec128.m128_f32[1];
    v5 = rayTo->mVec128.m128_f32[2] - rayFrom->mVec128.m128_f32[2];
    v6 = rayTo->mVec128.m128_f32[0] - rayFrom->mVec128.m128_f32[0];
    v7 = s_bm_current_air_resistance / fsqrt((float)((float)(v4 * v4) + (float)(v5 * v5)) + (float)(v6 * v6));
    v8 = v6 * v7;
    v9 = v4 * v7;
    *(float *)&v54 = v4 * v7;
    *(float *)&v55 = v5 * v7;
    if ( (float)(v6 * v7) == 0.0 )
      v10 = FLOAT_9_9999998e17;
    else
      v10 = s_bm_current_air_resistance / v8;
    v51 = v10;
    if ( v9 == 0.0 )
      v11 = FLOAT_9_9999998e17;
    else
      v11 = s_bm_current_air_resistance / v9;
    v52 = v11;
    if ( *(float *)&v55 == 0.0 )
      v12 = FLOAT_9_9999998e17;
    else
      v12 = s_bm_current_air_resistance / *(float *)&v55;
    v48 = v51 < 0.0;
    v49 = v11 < 0.0;
    v50 = v12 < 0.0;
    v47 = (float)((float)(v4 * *(float *)&v54) + (float)(v5 * *(float *)&v55)) + (float)(v6 * v8);
    v40 = 1;
    v43 = 126;
    v13 = (char *)btAlignedAllocInternal(0x200u);
    v14 = v13;
    v57 = 1;
    ptr = v13;
    v55 = 128;
    v15 = v13;
    v16 = 128;
    do
    {
      if ( v15 )
        *(_DWORD *)v15 = 0;
      v15 += 4;
      --v16;
    }
    while ( v16 );
    *(_DWORD *)v13 = root;
    v54 = 128;
    v17 = (float *)(&v61 - 4 * v48);
    v45 = (float *)&v60[4 * v49 - 1];
    v46 = (float *)&v63[-4 * v49 - 1];
    while ( 1 )
    {
      --v40;
      v18 = *(int **)&v14[4 * v40];
      v58 = *v18;
      v59 = v18[1];
      v60[0] = v18[2];
      v19 = rayFrom->mVec128.m128_f32[0];
      v60[1] = v18[3];
      v20 = rayFrom->mVec128.m128_f32[1];
      v61 = v18[4];
      v62 = v18[5];
      v63[0] = v18[6];
      v63[1] = v18[7];
      v21 = (float)(*((float *)&v58 + 4 * v48) - v19) * v51;
      v22 = *v17 - v19;
      v23 = (int)&v63[-4 * v49 - 1];
      v24 = v22 * v51;
      v25 = (float)(*v46 - v20) * v52;
      v26 = (float)(*v45 - v20) * v52;
      if ( v21 <= v25 && v26 <= v24 )
      {
        if ( v26 > v21 )
          v21 = (float)(*v45 - v20) * v52;
        if ( v24 > v25 )
          v24 = (float)(*v46 - v20) * v52;
        v27 = rayFrom->mVec128.m128_f32[2];
        v23 = 16 * v50;
        v28 = (float)(*(float *)&v63[-4 * v50] - v27) * v12;
        v29 = (float)(*(float *)&v60[4 * v50] - v27) * v12;
        if ( v21 <= v28 && v29 <= v24 )
        {
          if ( v29 > v21 )
            v21 = (float)(*(float *)&v60[4 * v50] - v27) * v12;
          if ( v24 > v28 )
            v24 = (float)(*(float *)&v63[-4 * v50] - v27) * v12;
          if ( v47 > v21 && v24 > 0.0 )
          {
            if ( v18[10] )
            {
              v30 = v40;
              if ( v40 > v43 )
              {
                v23 = v54;
                v31 = 2 * v54;
                if ( 2 * v54 > v54 )
                {
                  if ( v55 < v31 )
                  {
                    if ( v31 )
                    {
                      v32 = btAlignedAllocInternal(8 * v54);
                      v14 = (char *)ptr;
                      v23 = v54;
                      v41 = v32;
                    }
                    else
                    {
                      v41 = 0;
                    }
                    if ( v23 > 0 )
                    {
                      v33 = v41;
                      v44 = v23;
                      do
                      {
                        if ( v33 )
                          *v33 = *(_DWORD *)((char *)v33 + v14 - (char *)v41);
                        ++v33;
                        --v44;
                      }
                      while ( v44 );
                    }
                    if ( v14 )
                    {
                      btAlignedFreeInternal(v14);
                      v23 = v54;
                    }
                    v30 = v40;
                    v57 = 1;
                    ptr = v41;
                    v55 = v31;
                    v14 = (char *)v41;
                  }
                  if ( v23 < v31 )
                  {
                    v34 = v31 - v54;
                    v23 = (int)&v14[4 * v23];
                    do
                    {
                      if ( v23 )
                        *(_DWORD *)v23 = 0;
                      v23 += 4;
                      --v34;
                    }
                    while ( v34 );
                  }
                }
                v54 = v31;
                v43 = v31 - 2;
              }
              *(_DWORD *)&v14[4 * v30] = v18[9];
              v35 = v30 + 1;
              *(_DWORD *)&v14[4 * v35] = v18[10];
              v40 = v35 + 1;
            }
            else
            {
              v36 = (btSoftBody::Face *)v18[9];
              m_mint = policy->m_mint;
              v37 = btSoftBody::RayFromToCaster::rayFromToTriangle(
                      &policy->m_rayFrom,
                      &policy->m_rayNormalizedDirection,
                      &v36->m_n[1]->m_x,
                      &v36->m_n[2]->m_x,
                      &v36->m_n[0]->m_x,
                      (const btVector3 *)LODWORD(m_mint));
              v23 = v39;
              if ( v37 <= 0.0 || m_mint <= v37 )
              {
                v38 = policy;
              }
              else
              {
                v38 = policy;
                policy->m_mint = v37;
                policy->m_face = v36;
              }
              ++v38->m_tests;
              v14 = (char *)ptr;
            }
          }
        }
      }
      if ( !v40 )
        break;
      v17 = (float *)(&v61 - 4 * v48);
    }
    btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
      (btAlignedObjectArray<GrahamVector2> *)v23,
      (int)v53);
  }
}
