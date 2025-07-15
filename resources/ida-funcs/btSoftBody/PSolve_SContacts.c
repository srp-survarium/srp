void __cdecl btSoftBody::PSolve_SContacts(btSoftBody *psb)
{
  btSoftBody::SContact *v1; // eax
  btSoftBody::Face *m_face; // edx
  float *v3; // esi
  float *v4; // edi
  float v5; // xmm1_4
  float v6; // xmm2_4
  float *v7; // ebx
  float v8; // xmm7_4
  float *m_node; // ecx
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm7_4
  float m_friction; // xmm5_4
  float v22; // xmm2_4
  float v23; // xmm7_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  bool v32; // zf
  int v33; // [esp+18h] [ebp-68h]
  int m_size; // [esp+1Ch] [ebp-64h]
  float v35; // [esp+20h] [ebp-60h]
  float v36; // [esp+24h] [ebp-5Ch]
  float v37; // [esp+28h] [ebp-58h]
  float v38; // [esp+30h] [ebp-50h]
  float v39; // [esp+34h] [ebp-4Ch]
  float v40; // [esp+38h] [ebp-48h]
  float v41; // [esp+50h] [ebp-30h]
  float v42; // [esp+54h] [ebp-2Ch]
  float v43; // [esp+68h] [ebp-18h]

  if ( psb->m_scontacts.m_size > 0 )
  {
    v33 = 0;
    m_size = psb->m_scontacts.m_size;
    do
    {
      v1 = &psb->m_scontacts.m_data[v33];
      m_face = v1->m_face;
      v3 = (float *)m_face->m_n[2];
      v4 = (float *)m_face->m_n[1];
      v5 = v1->m_weights.mVec128.m128_f32[2];
      v6 = v1->m_weights.mVec128.m128_f32[1];
      v7 = (float *)m_face->m_n[0];
      v8 = v1->m_weights.mVec128.m128_f32[0];
      m_node = (float *)v1->m_node;
      v36 = (float)((float)(v7[5] * v8) + (float)(v4[5] * v6)) + (float)(v3[5] * v5);
      v37 = (float)((float)(v7[6] * v8) + (float)(v4[6] * v6)) + (float)(v3[6] * v5);
      v10 = v3[10] * v5;
      v43 = v4[10] * v6;
      v35 = (float)((float)(v8 * v7[4]) + (float)(v6 * v4[4])) + (float)(v3[4] * v5);
      v11 = v35 - (float)((float)((float)(v8 * v7[8]) + (float)(v4[8] * v6)) + (float)(v5 * v3[8]));
      v12 = (float)(m_node[5] - m_node[9])
          - (float)(v36 - (float)((float)((float)(v7[9] * v8) + (float)(v4[9] * v6)) + (float)(v3[9] * v5)));
      v13 = (float)(m_node[4] - m_node[8]) - v11;
      v14 = v1->m_normal.mVec128.m128_f32[0];
      v41 = v13;
      v15 = (float)(v1->m_node->m_x.mVec128.m128_f32[2] - v1->m_node->m_q.mVec128.m128_f32[2])
          - (float)(v37 - (float)((float)((float)(v7[10] * v8) + v43) + v10));
      v42 = v12;
      v38 = 0.0;
      v39 = 0.0;
      v40 = 0.0;
      if ( (float)((float)((float)(v15 * v1->m_normal.mVec128.m128_f32[2])
                         + (float)(v12 * v1->m_normal.mVec128.m128_f32[1]))
                 + (float)(v14 * v41)) < 0.0 )
      {
        v16 = v1->m_margin
            - (float)((float)((float)((float)(m_node[5] * v1->m_normal.mVec128.m128_f32[1])
                                    + (float)(m_node[6] * v1->m_normal.mVec128.m128_f32[2]))
                            + (float)(v14 * m_node[4]))
                    - (float)((float)((float)(v1->m_normal.mVec128.m128_f32[1] * v36)
                                    + (float)(v1->m_normal.mVec128.m128_f32[2] * v37))
                            + (float)(v14 * v35)));
        v38 = v14 * v16;
        v39 = v1->m_normal.mVec128.m128_f32[1] * v16;
        v40 = v1->m_normal.mVec128.m128_f32[2] * v16;
      }
      v17 = (float)((float)(v1->m_normal.mVec128.m128_f32[1] * v42) + (float)(v1->m_normal.mVec128.m128_f32[2] * v15))
          + (float)(v14 * v41);
      v18 = v15 - (float)(v1->m_normal.mVec128.m128_f32[2] * v17);
      v19 = v41 - (float)(v14 * v17);
      v20 = v1->m_normal.mVec128.m128_f32[1] * v17;
      m_friction = v1->m_friction;
      v22 = v42 - v20;
      v23 = m_node[4];
      v24 = v22;
      v25 = v38 - (float)(m_friction * v19);
      v26 = v1->m_cfm[0];
      v27 = v39 - (float)(m_friction * v24);
      v28 = v40 - (float)(m_friction * v18);
      m_node[5] = (float)(v26 * v27) + m_node[5];
      m_node[4] = v23 + (float)(v26 * v25);
      m_node[6] = (float)(v26 * v28) + m_node[6];
      v29 = v1->m_weights.mVec128.m128_f32[0] * v1->m_cfm[1];
      v7[4] = v7[4] - (float)(v25 * v29);
      v7[5] = v7[5] - (float)(v27 * v29);
      v7[6] = v7[6] - (float)(v28 * v29);
      v30 = v1->m_weights.mVec128.m128_f32[1] * v1->m_cfm[1];
      v4[4] = v4[4] - (float)(v25 * v30);
      v4[5] = v4[5] - (float)(v27 * v30);
      ++v33;
      v4[6] = v4[6] - (float)(v28 * v30);
      v31 = v1->m_weights.mVec128.m128_f32[2] * v1->m_cfm[1];
      v32 = m_size-- == 1;
      v3[4] = v3[4] - (float)(v25 * v31);
      v3[5] = v3[5] - (float)(v27 * v31);
      v3[6] = v3[6] - (float)(v28 * v31);
    }
    while ( !v32 );
  }
}
