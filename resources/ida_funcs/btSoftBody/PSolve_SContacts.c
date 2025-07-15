void __cdecl btSoftBody::PSolve_SContacts(btSoftBody *psb)
{
  btSoftBody::SContact *v1; // eax
  btSoftBody::Face *m_face; // edx
  float *v3; // esi
  float *v4; // edi
  float v5; // xmm0_4
  float *v6; // ebx
  float v7; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float *m_node; // ecx
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm3_4
  float v33; // xmm3_4
  bool v34; // zf
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  int v39; // [esp+ACh] [ebp-64h]
  int m_size; // [esp+B0h] [ebp-60h]
  float v41; // [esp+BCh] [ebp-54h]
  float v42; // [esp+C0h] [ebp-50h]
  float v43; // [esp+C4h] [ebp-4Ch]
  float v44; // [esp+C8h] [ebp-48h]
  float v45; // [esp+D0h] [ebp-40h]
  float v46; // [esp+D4h] [ebp-3Ch]
  float v47; // [esp+D8h] [ebp-38h]

  if ( psb->m_scontacts.m_size > 0 )
  {
    v39 = 0;
    m_size = psb->m_scontacts.m_size;
    do
    {
      v1 = &psb->m_scontacts.m_data[v39];
      m_face = v1->m_face;
      v3 = (float *)m_face->m_n[2];
      v4 = (float *)m_face->m_n[1];
      v5 = v1->m_weights.mVec128.m128_f32[2];
      v6 = (float *)m_face->m_n[0];
      v7 = v1->m_weights.mVec128.m128_f32[0];
      v8 = v3[5] * v5;
      v9 = v3[4] * v5;
      v10 = v3[6] * v5;
      v11 = v1->m_weights.mVec128.m128_f32[1];
      m_node = (float *)v1->m_node;
      v43 = (float)((float)(v6[5] * v7) + (float)(v4[5] * v11)) + v8;
      v13 = (float)((float)(v6[6] * v7) + (float)(v4[6] * v11)) + v10;
      v42 = (float)((float)(v7 * v6[4]) + (float)(v11 * v4[4])) + v9;
      v14 = v1->m_weights.mVec128.m128_f32[2];
      v15 = v3[9] * v14;
      v16 = v3[10] * v14;
      v17 = v1->m_weights.mVec128.m128_f32[1];
      v44 = v13;
      v18 = v1->m_normal.mVec128.m128_f32[0];
      v19 = (float)(v1->m_node->m_x.mVec128.m128_f32[2] - v1->m_node->m_q.mVec128.m128_f32[2])
          - (float)(v13 - (float)((float)((float)(v6[10] * v7) + (float)(v4[10] * v17)) + v16));
      v20 = (float)(v1->m_node->m_x.mVec128.m128_f32[1] - v1->m_node->m_q.mVec128.m128_f32[1])
          - (float)(v43 - (float)((float)((float)(v6[9] * v7) + (float)(v4[9] * v17)) + v15));
      v21 = (float)(v1->m_node->m_x.mVec128.m128_f32[0] - v1->m_node->m_q.mVec128.m128_f32[0])
          - (float)(v42
                  - (float)((float)((float)(v7 * v6[8]) + (float)(v4[8] * v17))
                          + (float)(v1->m_weights.mVec128.m128_f32[2] * v3[8])));
      v45 = 0.0;
      v46 = 0.0;
      v47 = 0.0;
      if ( (float)((float)((float)(v19 * v1->m_normal.mVec128.m128_f32[2])
                         + (float)(v20 * v1->m_normal.mVec128.m128_f32[1]))
                 + (float)(v18 * v21)) < 0.0 )
      {
        v22 = v1->m_margin
            - (float)((float)((float)((float)(m_node[5] * v1->m_normal.mVec128.m128_f32[1])
                                    + (float)(m_node[6] * v1->m_normal.mVec128.m128_f32[2]))
                            + (float)(v18 * m_node[4]))
                    - (float)((float)((float)(v1->m_normal.mVec128.m128_f32[1] * v43)
                                    + (float)(v1->m_normal.mVec128.m128_f32[2] * v44))
                            + (float)(v18 * v42)));
        v45 = v18 * v22;
        v46 = v1->m_normal.mVec128.m128_f32[1] * v22;
        v47 = v1->m_normal.mVec128.m128_f32[2] * v22;
      }
      v23 = v1->m_normal.mVec128.m128_f32[2];
      v41 = v1->m_normal.mVec128.m128_f32[1];
      v24 = (float)((float)(v41 * v20) + (float)(v23 * v19)) + (float)(v18 * v21);
      v25 = v19 - (float)(v23 * v24);
      v26 = m_node[4];
      v27 = v46 - (float)(v1->m_friction * (float)(v20 - (float)(v41 * v24)));
      v28 = v45 - (float)(v1->m_friction * (float)(v21 - (float)(v18 * v24)));
      v29 = v1->m_cfm[0];
      v30 = v47 - (float)(v1->m_friction * v25);
      m_node[6] = (float)(v29 * v30) + m_node[6];
      m_node[4] = v26 + (float)(v29 * v28);
      m_node[5] = (float)(v29 * v27) + m_node[5];
      v31 = v1->m_weights.mVec128.m128_f32[0] * v1->m_cfm[1];
      v6[4] = v6[4] - (float)(v28 * v31);
      v6[5] = v6[5] - (float)(v27 * v31);
      v6[6] = v6[6] - (float)(v30 * v31);
      v32 = v1->m_weights.mVec128.m128_f32[1] * v1->m_cfm[1];
      v4[4] = v4[4] - (float)(v28 * v32);
      v4[5] = v4[5] - (float)(v27 * v32);
      v4[6] = v4[6] - (float)(v30 * v32);
      v33 = v1->m_weights.mVec128.m128_f32[2] * v1->m_cfm[1];
      ++v39;
      v34 = m_size-- == 1;
      v35 = v27 * v33;
      v36 = v30 * v33;
      v37 = v3[4] - (float)(v28 * v33);
      v3[5] = v3[5] - v35;
      v38 = v3[6] - v36;
      v3[4] = v37;
      v3[6] = v38;
    }
    while ( !v34 );
  }
}
