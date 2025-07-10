void __thiscall btSoftBody::solveConstraints(btSoftBody *this, btSoftBody *thisa)
{
  int m_size; // edi
  const vostok::math::float4x4 *v3; // xmm3_4
  int v4; // esi
  btSoftBody::Link *m_data; // eax
  float *v6; // edx
  float *v7; // ecx
  btVector3 *v8; // eax
  int v9; // eax
  btMatrix3x3 *v10; // esi
  float *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  int v19; // ecx
  int v20; // esi
  int v21; // eax
  int v22; // edi
  int v23; // eax
  int v24; // esi
  int v25; // edx
  int v26; // ecx
  btSoftBody::Node *v27; // eax
  float sdt; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  btVector3 *v31; // eax
  int piterations; // ecx
  int v33; // edi
  int v34; // eax
  int v35; // esi
  void (__cdecl *v36)(btSoftBody *, float); // eax
  int v37; // edx
  float v38; // xmm3_4
  btSoftBody::Node *v39; // eax
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  _QWORD *v43; // eax
  __int64 v44; // xmm0_8
  int v45; // esi
  float v46; // xmm3_4
  int v47; // edx
  btSoftBody::Node *v48; // eax
  btSoftBody::Feature v49; // xmm0_8
  int v50; // edi
  int v51; // eax
  int v52; // esi
  void (__cdecl *v53)(btSoftBody *, float); // eax
  int v54; // edx
  btSoftBody::Node *v55; // eax
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm4_4
  float v59; // xmm2_4
  float *v60; // eax
  float v61; // xmm4_4
  float v62; // xmm0_4
  btSoftBody *v63; // ecx
  float dt; // [esp+ECh] [ebp-7Ch]
  unsigned int ima; // [esp+F0h] [ebp-78h]
  unsigned int imb; // [esp+F4h] [ebp-74h]
  int v67; // [esp+110h] [ebp-58h]
  int v68; // [esp+114h] [ebp-54h]
  float v69; // [esp+114h] [ebp-54h]
  btVector3 r; // [esp+118h] [ebp-50h] BYREF
  __int64 v71; // [esp+128h] [ebp-40h]
  __int64 v72; // [esp+130h] [ebp-38h]
  char v73[48]; // [esp+138h] [ebp-30h] BYREF

  btSoftBody::applyClusters(this, thisa, 0);
  m_size = thisa->m_links.m_size;
  v3 = clear_value;
  if ( m_size > 0 )
  {
    r.mVec128.m128_i32[3] = 0;
    v4 = 0;
    do
    {
      m_data = thisa->m_links.m_data;
      v6 = (float *)m_data[v4].m_n[1];
      v7 = (float *)m_data[v4].m_n[0];
      v8 = (btVector3 *)&m_data[v4];
      r.mVec128.m128_f32[0] = v6[8] - v7[8];
      r.mVec128.m128_f32[1] = v6[9] - v7[9];
      r.mVec128.m128_f32[2] = v6[10] - v7[10];
      v8[3] = (btVector3)r.mVec128;
      ++v4;
      --m_size;
      v8[2].mVec128.m128_f32[0] = *(float *)&v3
                                / (float)((float)((float)((float)(v8[3].mVec128.m128_f32[0] * v8[3].mVec128.m128_f32[0])
                                                        + (float)(v8[3].mVec128.m128_f32[1] * v8[3].mVec128.m128_f32[1]))
                                                + (float)(v8[3].mVec128.m128_f32[2] * v8[3].mVec128.m128_f32[2]))
                                        * v8[1].mVec128.m128_f32[2]);
    }
    while ( m_size );
  }
  v9 = thisa->m_anchors.m_size;
  if ( v9 > 0 )
  {
    r.mVec128.m128_i32[3] = 0;
    v67 = 0;
    v68 = v9;
    do
    {
      v10 = (btMatrix3x3 *)&thisa->m_anchors.m_data[v67];
      v11 = (float *)v10->m_el[2].mVec128.m128_i32[0];
      v12 = v10->m_el[1].mVec128.m128_f32[1];
      v13 = v10->m_el[1].mVec128.m128_f32[2];
      imb = *((unsigned int *)v11 + 88);
      v14 = v10->m_el[1].mVec128.m128_f32[0];
      v15 = v11[10];
      r.mVec128.m128_f32[0] = (float)((float)(v11[5] * v12) + (float)(v11[6] * v13)) + (float)(v14 * v11[4]);
      v16 = (float)(v11[9] * v12) + (float)(v15 * v13);
      v17 = v14 * v11[8];
      v18 = v14 * v11[12];
      r.mVec128.m128_f32[1] = v16 + v17;
      ima = *(unsigned int *)(v10->m_el[0].mVec128.m128_i32[0] + 96);
      dt = thisa->m_sst.sdt;
      r.mVec128.m128_f32[2] = (float)((float)(v11[13] * v12) + (float)(v11[14] * v13)) + v18;
      v10[1] = *ImpulseMatrix_0(&r, (int)v73, dt, ima, imb);
      v19 = v10->m_el[0].mVec128.m128_i32[0];
      v10[2].m_el[0] = (btVector3)r.mVec128;
      v10[2].m_el[1].mVec128.m128_f32[0] = *(float *)(v19 + 96) * thisa->m_sst.sdt;
      v20 = v10->m_el[2].mVec128.m128_i32[0];
      if ( (*(_BYTE *)(v20 + 216) & 3) == 0 )
      {
        v21 = *(_DWORD *)(v20 + 228);
        if ( v21 != 4 && v21 != 5 )
          *(_DWORD *)(v20 + 228) = 1;
        *(_DWORD *)(v20 + 232) = 0;
      }
      ++v67;
      --v68;
    }
    while ( v68 );
    v3 = clear_value;
  }
  if ( thisa->m_cfg.viterations > 0 )
  {
    v22 = 0;
    v23 = thisa->m_cfg.m_vsequence.m_size;
    do
    {
      v24 = 0;
      if ( v23 > 0 )
      {
        do
        {
          ((void (__cdecl *)(btSoftBody *, _DWORD))(thisa->m_cfg.m_vsequence.m_data[v24] == Linear
                                                  ? (unsigned int)btSoftBody::VSolve_Links
                                                  : 0))(
            thisa,
            1.0);
          v23 = thisa->m_cfg.m_vsequence.m_size;
          ++v24;
        }
        while ( v24 < v23 );
        v3 = clear_value;
      }
      ++v22;
    }
    while ( v22 < thisa->m_cfg.viterations );
    v25 = thisa->m_nodes.m_size;
    if ( v25 > 0 )
    {
      r.mVec128.m128_i32[3] = 0;
      v26 = 0;
      do
      {
        v27 = thisa->m_nodes.m_data;
        sdt = thisa->m_sst.sdt;
        v29 = v27[v26].m_v.mVec128.m128_f32[1];
        v30 = v27[v26].m_v.mVec128.m128_f32[2];
        v31 = (btVector3 *)&v27[v26];
        r.mVec128.m128_f32[0] = (float)(sdt * v31[3].mVec128.m128_f32[0]) + v31[2].mVec128.m128_f32[0];
        r.mVec128.m128_f32[1] = v31[2].mVec128.m128_f32[1] + (float)(v29 * sdt);
        r.mVec128.m128_f32[2] = v31[2].mVec128.m128_f32[2] + (float)(v30 * sdt);
        v31[1] = (btVector3)r.mVec128;
        ++v26;
        --v25;
      }
      while ( v25 );
    }
  }
  piterations = thisa->m_cfg.piterations;
  if ( piterations > 0 )
  {
    v33 = 0;
    v34 = thisa->m_cfg.m_psequence.m_size;
    do
    {
      v35 = 0;
      if ( v34 > 0 )
      {
        do
        {
          switch ( thisa->m_cfg.m_psequence.m_data[v35] )
          {
            case Linear:
              v36 = btSoftBody::PSolve_Links;
              break;
            case Anchors:
              v36 = btSoftBody::PSolve_Anchors;
              break;
            case RContacts:
              v36 = btSoftBody::PSolve_RContacts;
              break;
            case SContacts:
              v36 = (void (__cdecl *)(btSoftBody *, float))btSoftBody::PSolve_SContacts;
              break;
            default:
              v36 = 0;
              break;
          }
          v36(thisa, 1.0);
          v34 = thisa->m_cfg.m_psequence.m_size;
          ++v35;
        }
        while ( v35 < v34 );
        v3 = clear_value;
      }
      piterations = thisa->m_cfg.piterations;
      ++v33;
    }
    while ( v33 < piterations );
    v37 = thisa->m_nodes.m_size;
    v38 = (float)(*(float *)&v3 - thisa->m_cfg.kDP) * thisa->m_sst.isdt;
    if ( v37 > 0 )
    {
      HIDWORD(v72) = 0;
      memset(&r, 0, sizeof(r));
      piterations = 0;
      do
      {
        v39 = thisa->m_nodes.m_data;
        v40 = *(float *)((char *)v39->m_x.mVec128.m128_f32 + piterations)
            - *(float *)((char *)v39->m_q.mVec128.m128_f32 + piterations);
        v41 = *(float *)((char *)&v39->m_x.mVec128.m128_f32[1] + piterations)
            - *(float *)((char *)&v39->m_q.mVec128.m128_f32[1] + piterations);
        v42 = *(float *)((char *)&v39->m_x.mVec128.m128_f32[2] + piterations)
            - *(float *)((char *)&v39->m_q.mVec128.m128_f32[2] + piterations);
        v43 = (_QWORD *)((char *)v39 + piterations);
        *(float *)&v71 = v40 * v38;
        *((float *)&v71 + 1) = v41 * v38;
        v43[6] = v71;
        *(float *)&v72 = v42 * v38;
        v44 = v72;
        piterations += 112;
        --v37;
        v43[8] = 0;
        v43[7] = v44;
        v43[9] = 0;
      }
      while ( v37 );
    }
  }
  if ( thisa->m_cfg.diterations > 0 )
  {
    v45 = thisa->m_nodes.m_size;
    v46 = thisa->m_sst.isdt * thisa->m_cfg.kVCF;
    v69 = v46;
    if ( v45 > 0 )
    {
      v47 = 0;
      do
      {
        v48 = &thisa->m_nodes.m_data[v47];
        v49 = (btSoftBody::Feature)v48->m_x.mVec128.m128_u64[0];
        piterations = (int)&v48->m_x;
        v48 = (btSoftBody::Node *)((char *)v48 + 32);
        v48->btSoftBody::Feature = v49;
        ++v47;
        --v45;
        *((_QWORD *)&v48->btSoftBody::Feature + 1) = *(_QWORD *)(piterations + 8);
      }
      while ( v45 );
    }
    v50 = 0;
    if ( thisa->m_cfg.diterations > 0 )
    {
      v51 = thisa->m_cfg.m_dsequence.m_size;
      do
      {
        v52 = 0;
        if ( v51 > 0 )
        {
          do
          {
            switch ( thisa->m_cfg.m_dsequence.m_data[v52] )
            {
              case Linear:
                v53 = btSoftBody::PSolve_Links;
                break;
              case Anchors:
                v53 = btSoftBody::PSolve_Anchors;
                break;
              case RContacts:
                v53 = btSoftBody::PSolve_RContacts;
                break;
              case SContacts:
                v53 = (void (__cdecl *)(btSoftBody *, float))btSoftBody::PSolve_SContacts;
                break;
              default:
                v53 = 0;
                break;
            }
            v53(thisa, 1.0);
            v51 = thisa->m_cfg.m_dsequence.m_size;
            ++v52;
          }
          while ( v52 < v51 );
          v46 = v69;
        }
        ++v50;
      }
      while ( v50 < thisa->m_cfg.diterations );
    }
    v54 = thisa->m_nodes.m_size;
    if ( v54 > 0 )
    {
      piterations = 0;
      do
      {
        v55 = thisa->m_nodes.m_data;
        v56 = *(float *)((char *)v55->m_x.mVec128.m128_f32 + piterations)
            - *(float *)((char *)v55->m_q.mVec128.m128_f32 + piterations);
        v57 = *(float *)((char *)&v55->m_x.mVec128.m128_f32[1] + piterations)
            - *(float *)((char *)&v55->m_q.mVec128.m128_f32[1] + piterations);
        v58 = *(float *)((char *)v55->m_v.mVec128.m128_f32 + piterations);
        v59 = *(float *)((char *)&v55->m_x.mVec128.m128_f32[2] + piterations)
            - *(float *)((char *)&v55->m_q.mVec128.m128_f32[2] + piterations);
        v60 = (float *)((char *)v55 + piterations);
        v61 = v58 + (float)(v56 * v46);
        v60[13] = v60[13] + (float)(v57 * v46);
        piterations += 112;
        --v54;
        v62 = v60[14] + (float)(v59 * v46);
        v60[12] = v61;
        v60[14] = v62;
      }
      while ( v54 );
    }
  }
  btSoftBody::dampClusters((btSoftBody *)piterations, (int)thisa);
  btSoftBody::applyClusters(v63, thisa, 1);
}
