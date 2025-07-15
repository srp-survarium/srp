void __cdecl btSoftBody::PSolve_Anchors(btSoftBody *psb, float kst)
{
  int m_size; // eax
  int v3; // edi
  btSoftBody::Anchor *m_data; // eax
  float *m_body; // ecx
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm6_4
  const btVector3 *v10; // eax
  float *v11; // edx
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm7_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm5_4
  btRigidBody *v31; // edx
  int v32; // [esp+B4h] [ebp-50h]
  float sdt; // [esp+BCh] [ebp-48h]
  float v34; // [esp+C0h] [ebp-44h]
  btVector3 impulse; // [esp+C4h] [ebp-40h] BYREF
  float v36; // [esp+DCh] [ebp-28h]
  float v37; // [esp+E8h] [ebp-1Ch]
  float v38; // [esp+F4h] [ebp-10h]

  m_size = psb->m_anchors.m_size;
  v34 = psb->m_cfg.kAHR * kst;
  sdt = psb->m_sst.sdt;
  if ( m_size > 0 )
  {
    impulse.mVec128.m128_i32[3] = 0;
    v3 = 0;
    v32 = m_size;
    do
    {
      m_data = psb->m_anchors.m_data;
      m_body = (float *)m_data[v3].m_body;
      v6 = m_data[v3].m_local.mVec128.m128_f32[2];
      v7 = m_data[v3].m_local.mVec128.m128_f32[1];
      v8 = m_data[v3].m_local.mVec128.m128_f32[0];
      v9 = m_body[86];
      v10 = (const btVector3 *)&m_data[v3];
      v11 = (float *)v10->mVec128.m128_i32[0];
      v12 = (float)((float)((float)((float)(m_body[13] * v7) + (float)(m_body[14] * v6)) + (float)(v8 * m_body[12]))
                  + m_body[18])
          - *(float *)(v10->mVec128.m128_i32[0] + 24);
      v13 = (float)((float)((float)((float)(m_body[5] * v7) + (float)(m_body[6] * v6)) + (float)(v8 * m_body[4]))
                  + m_body[16])
          - *(float *)(v10->mVec128.m128_i32[0] + 16);
      v14 = (float)((float)((float)((float)(m_body[9] * v7) + (float)(m_body[10] * v6)) + (float)(v8 * m_body[8]))
                  + m_body[17])
          - *(float *)(v10->mVec128.m128_i32[0] + 20);
      v15 = m_body[84];
      v16 = m_body[80]
          + (float)((float)(v10[6].mVec128.m128_f32[2] * m_body[85]) - (float)(v10[6].mVec128.m128_f32[1] * v9));
      v17 = m_body[81] + (float)((float)(v10[6].mVec128.m128_f32[0] * v9) - (float)(v15 * v10[6].mVec128.m128_f32[2]));
      v18 = (float)(m_body[82]
                  + (float)((float)(v15 * v10[6].mVec128.m128_f32[1]) - (float)(v10[6].mVec128.m128_f32[0] * m_body[85])))
          * sdt;
      v19 = v11[4] - v11[8];
      v37 = v11[5] - v11[9];
      v20 = v11[6] - v11[10];
      v36 = v12;
      v38 = v13 * v34;
      v21 = (float)((float)(v17 * sdt) - v37) + (float)(v14 * v34);
      v22 = (float)((float)(v16 * sdt) - v19) + (float)(v13 * v34);
      v23 = (float)(v18 - v20) + (float)(v12 * v34);
      v24 = v10[2].mVec128.m128_f32[1]
          * (float)((float)((float)(v10[3].mVec128.m128_f32[2] * v23) + (float)(v10[3].mVec128.m128_f32[1] * v21))
                  + (float)(v22 * v10[3].mVec128.m128_f32[0]));
      v25 = v10[2].mVec128.m128_f32[1]
          * (float)((float)((float)(v10[4].mVec128.m128_f32[2] * v23) + (float)(v10[4].mVec128.m128_f32[1] * v21))
                  + (float)(v10[4].mVec128.m128_f32[0] * v22));
      v26 = v10[2].mVec128.m128_f32[1]
          * (float)((float)((float)(v10[5].mVec128.m128_f32[2] * v23) + (float)(v10[5].mVec128.m128_f32[1] * v21))
                  + (float)(v10[5].mVec128.m128_f32[0] * v22));
      v27 = v10[7].mVec128.m128_f32[0];
      v28 = (float)(v27 * v26) + v11[6];
      v29 = (float)(v27 * v24) + v11[4];
      v30 = (float)(v27 * v25) + v11[5];
      v11[4] = v29;
      v11[5] = v30;
      v11[6] = v28;
      v31 = (btRigidBody *)v10[2].mVec128.m128_i32[0];
      impulse.mVec128.m128_f32[0] = -v24;
      impulse.mVec128.m128_f32[1] = -v25;
      impulse.mVec128.m128_f32[2] = -v26;
      btRigidBody::applyImpulse(v31, &impulse, v10 + 6);
      ++v3;
      --v32;
    }
    while ( v32 );
  }
}
