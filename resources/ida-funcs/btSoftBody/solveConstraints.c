void __thiscall btSoftBody::solveConstraints(btSoftBody *this, int drift)
{
  int v2; // edx
  int v3; // eax
  bool v4; // zf
  btMatrix3x3 *v5; // esi
  int v6; // eax
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  btCollisionObject *v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // eax
  int i; // esi
  int v15; // ecx
  int v16; // edx
  float v17; // xmm4_4
  int v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // ecx
  int v22; // esi
  void (__cdecl *Solver)(btSoftBody *, float); // eax
  float v24; // xmm4_4
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  btSoftBody *v28; // ecx
  float v29; // xmm3_4
  int v30; // edx
  _DWORD *v31; // eax
  int v32; // edi
  int v33; // eax
  int v34; // esi
  void (__cdecl *v35)(btSoftBody *, float); // eax
  int v36; // edx
  float *v37; // eax
  float v38; // xmm2_4
  float v39; // xmm4_4
  float v40; // xmm0_4
  btSoftBody *v41; // ecx
  int v42; // [esp+24h] [ebp-5Ch]
  int v43; // [esp+24h] [ebp-5Ch]
  int v44; // [esp+28h] [ebp-58h]
  float j; // [esp+2Ch] [ebp-54h]
  float v46; // [esp+2Ch] [ebp-54h]
  float v47; // [esp+30h] [ebp-50h]
  float v48; // [esp+34h] [ebp-4Ch]
  float v49; // [esp+34h] [ebp-4Ch]
  float v50; // [esp+34h] [ebp-4Ch]
  float v51; // [esp+34h] [ebp-4Ch]
  float v52; // [esp+38h] [ebp-48h]
  float v53; // [esp+38h] [ebp-48h]
  float v54; // [esp+38h] [ebp-48h]
  float v55; // [esp+38h] [ebp-48h]
  _BYTE v56[48]; // [esp+50h] [ebp-30h] BYREF

  btSoftBody::applyClusters(this, drift, 0);
  if ( *(int *)(drift + 740) > 0 )
  {
    v2 = 0;
    v42 = *(_DWORD *)(drift + 740);
    do
    {
      v3 = v2 + *(_DWORD *)(drift + 748);
      v48 = *(float *)(*(_DWORD *)(v3 + 12) + 36) - *(float *)(*(_DWORD *)(v3 + 8) + 36);
      v52 = *(float *)(*(_DWORD *)(v3 + 12) + 40) - *(float *)(*(_DWORD *)(v3 + 8) + 40);
      *(float *)(v3 + 48) = *(float *)(*(_DWORD *)(v3 + 12) + 32) - *(float *)(*(_DWORD *)(v3 + 8) + 32);
      *(float *)(v3 + 52) = v48;
      *(float *)(v3 + 56) = v52;
      *(_DWORD *)(v3 + 60) = 0;
      v2 += 64;
      v4 = v42-- == 1;
      *(float *)(v3 + 32) = s_bm_current_air_resistance
                          / (float)((float)((float)((float)(*(float *)(v3 + 48) * *(float *)(v3 + 48))
                                                  + (float)(*(float *)(v3 + 52) * *(float *)(v3 + 52)))
                                          + (float)(*(float *)(v3 + 56) * *(float *)(v3 + 56)))
                                  * *(float *)(v3 + 24));
    }
    while ( !v4 );
  }
  if ( *(int *)(drift + 800) > 0 )
  {
    v43 = 0;
    v44 = *(_DWORD *)(drift + 800);
    do
    {
      v5 = (btMatrix3x3 *)(v43 + *(_DWORD *)(drift + 808));
      v6 = v5->m_el[2].mVec128.m128_i32[0];
      v7 = v5->m_el[1].mVec128.m128_f32[1];
      v8 = v5->m_el[1].mVec128.m128_f32[2];
      v47 = (float)((float)(*(float *)(v6 + 20) * v7) + (float)(*(float *)(v6 + 24) * v8))
          + (float)(v5->m_el[1].mVec128.m128_f32[0] * *(float *)(v6 + 16));
      v9 = v5->m_el[1].mVec128.m128_f32[0];
      v49 = (float)((float)(*(float *)(v6 + 36) * v7) + (float)(*(float *)(v6 + 40) * v8))
          + (float)(v9 * *(float *)(v6 + 32));
      v53 = (float)((float)(*(float *)(v6 + 52) * v7) + (float)(*(float *)(v6 + 56) * v8))
          + (float)(v9 * *(float *)(v6 + 48));
      v5[1] = *ImpulseMatrix(
                 (int)v56,
                 *(float *)(drift + 460),
                 COERCE_UNSIGNED_INT(*(float *)(v5->m_el[0].mVec128.m128_i32[0] + 96)),
                 COERCE_CONST_BTMATRIX3X3_(*(float *)(v6 + 352)),
                 (const btMatrix3x3 *)(v6 + 272));
      v10 = (btCollisionObject *)v5->m_el[0].mVec128.m128_i32[0];
      v11 = v5->m_el[2].mVec128.m128_i32[0];
      v5[2].m_el[0].mVec128.m128_f32[0] = v47;
      v5[2].m_el[0].mVec128.m128_f32[1] = v49;
      v5[2].m_el[0].mVec128.m128_f32[2] = v53;
      v5[2].m_el[0].mVec128.m128_i32[3] = 0;
      v5[2].m_el[1].mVec128.m128_f32[0] = v10->m_interpolationWorldTransform.m_basis.m_el[1].mVec128.m128_f32[0]
                                        * *(float *)(drift + 460);
      btCollisionObject::activate(v10, v11);
      v43 += 128;
      --v44;
    }
    while ( v44 );
  }
  if ( *(int *)(drift + 380) > 0 )
  {
    v12 = 0;
    v13 = *(_DWORD *)(drift + 404);
    do
    {
      for ( i = 0; i < v13; ++i )
      {
        ((void (__cdecl *)(int, _DWORD))(*(_DWORD *)(*(_DWORD *)(drift + 412) + 4 * i) == 0
                                       ? (unsigned int)btSoftBody::VSolve_Links
                                       : 0))(
          drift,
          1.0);
        v13 = *(_DWORD *)(drift + 404);
      }
      ++v12;
    }
    while ( v12 < *(_DWORD *)(drift + 380) );
    if ( *(int *)(drift + 720) > 0 )
    {
      v15 = 0;
      v16 = *(_DWORD *)(drift + 720);
      do
      {
        v17 = *(float *)(drift + 460);
        v18 = v15 + *(_DWORD *)(drift + 728);
        v50 = *(float *)(v18 + 36) + (float)(*(float *)(v18 + 52) * v17);
        v54 = *(float *)(v18 + 40) + (float)(*(float *)(v18 + 56) * v17);
        *(float *)(v18 + 16) = *(float *)(v18 + 32) + (float)(*(float *)(v18 + 48) * v17);
        *(float *)(v18 + 20) = v50;
        *(float *)(v18 + 24) = v54;
        v15 += 112;
        --v16;
        *(_DWORD *)(v18 + 28) = 0;
      }
      while ( v16 );
    }
  }
  v19 = *(_DWORD *)(drift + 384);
  if ( v19 > 0 )
  {
    v20 = 0;
    v21 = *(_DWORD *)(drift + 424);
    do
    {
      v22 = 0;
      for ( j = (float)v20 / (float)v19; v22 < v21; ++v22 )
      {
        Solver = btSoftBody::getSolver(*(btSoftBody::ePSolver::_ *)(*(_DWORD *)(drift + 432) + 4 * v22));
        ((void (__cdecl *)(int, _DWORD, _DWORD))Solver)(drift, 1.0, LODWORD(j));
        v21 = *(_DWORD *)(drift + 424);
      }
      v19 = *(_DWORD *)(drift + 384);
      ++v20;
    }
    while ( v20 < v19 );
    v24 = (float)(s_bm_current_air_resistance - *(float *)(drift + 304)) * *(float *)(drift + 464);
    if ( *(int *)(drift + 720) > 0 )
    {
      v25 = 0;
      v26 = *(_DWORD *)(drift + 720);
      do
      {
        v27 = v25 + *(_DWORD *)(drift + 728);
        v51 = (float)(*(float *)(v27 + 20) - *(float *)(v27 + 36)) * v24;
        v55 = (float)(*(float *)(v27 + 24) - *(float *)(v27 + 40)) * v24;
        *(float *)(v27 + 48) = (float)(*(float *)(v27 + 16) - *(float *)(v27 + 32)) * v24;
        *(float *)(v27 + 52) = v51;
        *(float *)(v27 + 56) = v55;
        *(_DWORD *)(v27 + 60) = 0;
        *(_DWORD *)(v27 + 64) = 0;
        *(_DWORD *)(v27 + 68) = 0;
        *(_DWORD *)(v27 + 72) = 0;
        v25 += 112;
        --v26;
        *(_DWORD *)(v27 + 76) = 0;
      }
      while ( v26 );
    }
  }
  v28 = 0;
  if ( *(int *)(drift + 388) > 0 )
  {
    v29 = *(float *)(drift + 464) * *(float *)(drift + 300);
    v46 = v29;
    if ( *(int *)(drift + 720) > 0 )
    {
      v30 = *(_DWORD *)(drift + 720);
      do
      {
        v31 = (btSoftBody_vtbl **)((char *)&v28->__vftable + *(_DWORD *)(drift + 728));
        v31[8] = v31[4];
        v31[9] = v31[5];
        v31[10] = v31[6];
        v28 = (btSoftBody *)((char *)v28 + 112);
        --v30;
        v31[11] = v31[7];
      }
      while ( v30 );
    }
    v32 = 0;
    if ( *(int *)(drift + 388) > 0 )
    {
      v33 = *(_DWORD *)(drift + 444);
      do
      {
        v34 = 0;
        if ( v33 > 0 )
        {
          do
          {
            v35 = btSoftBody::getSolver(*(btSoftBody::ePSolver::_ *)(*(_DWORD *)(drift + 452) + 4 * v34));
            ((void (__cdecl *)(int, _DWORD, _DWORD))v35)(drift, 1.0, 0.0);
            v33 = *(_DWORD *)(drift + 444);
            ++v34;
          }
          while ( v34 < v33 );
          v29 = v46;
        }
        ++v32;
      }
      while ( v32 < *(_DWORD *)(drift + 388) );
    }
    if ( *(int *)(drift + 720) > 0 )
    {
      v28 = 0;
      v36 = *(_DWORD *)(drift + 720);
      do
      {
        v37 = (float *)((char *)v28 + *(_DWORD *)(drift + 728));
        v38 = v37[6] - v37[10];
        v39 = v37[12] + (float)((float)(v37[4] - v37[8]) * v29);
        v37[13] = v37[13] + (float)((float)(v37[5] - v37[9]) * v29);
        v28 = (btSoftBody *)((char *)v28 + 112);
        --v36;
        v40 = v37[14] + (float)(v38 * v29);
        v37[12] = v39;
        v37[14] = v40;
      }
      while ( v36 );
    }
  }
  btSoftBody::dampClusters(v28, drift);
  btSoftBody::applyClusters(v41, drift, 1);
}
