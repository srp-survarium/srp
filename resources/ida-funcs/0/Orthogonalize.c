void __usercall Orthogonalize(btMatrix3x3 *m@<eax>)
{
  float v1; // xmm4_4
  float v2; // xmm5_4
  float v3; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // [esp+Ch] [ebp-14h]
  unsigned __int64 v24; // [esp+14h] [ebp-Ch]

  v1 = m->m_el[1].mVec128.m128_f32[2];
  v2 = m->m_el[1].mVec128.m128_f32[1];
  v3 = m->m_el[1].mVec128.m128_f32[0];
  v4 = (float)(m->m_el[0].mVec128.m128_f32[1] * v1) - (float)(m->m_el[0].mVec128.m128_f32[2] * v2);
  v5 = (float)(m->m_el[0].mVec128.m128_f32[2] * v3) - (float)(m->m_el[0].mVec128.m128_f32[0] * v1);
  v6 = (float)(m->m_el[0].mVec128.m128_f32[0] * v2) - (float)(m->m_el[0].mVec128.m128_f32[1] * v3);
  v7 = fsqrt((float)((float)(v6 * v6) + (float)(v4 * v4)) + (float)(v5 * v5));
  v8 = s_bm_current_air_resistance;
  *(float *)&v24 = v5 * (float)(s_bm_current_air_resistance / v7);
  *((float *)&v24 + 1) = v6 * (float)(s_bm_current_air_resistance / v7);
  m->m_el[2].mVec128.m128_f32[0] = v4 * (float)(s_bm_current_air_resistance / v7);
  *(unsigned __int64 *)((char *)m->m_el[2].mVec128.m128_u64 + 4) = v24;
  m->m_el[2].mVec128.m128_i32[3] = 0;
  v9 = m->m_el[2].mVec128.m128_f32[2];
  v10 = (float)(m->m_el[0].mVec128.m128_f32[2] * m->m_el[2].mVec128.m128_f32[1])
      - (float)(m->m_el[0].mVec128.m128_f32[1] * v9);
  v11 = m->m_el[0].mVec128.m128_f32[0] * v9;
  v12 = m->m_el[2].mVec128.m128_f32[0];
  v13 = v11 - (float)(m->m_el[0].mVec128.m128_f32[2] * v12);
  v14 = (float)(m->m_el[0].mVec128.m128_f32[1] * v12)
      - (float)(m->m_el[0].mVec128.m128_f32[0] * m->m_el[2].mVec128.m128_f32[1]);
  v15 = fsqrt((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v10 * v10));
  m->m_el[1].mVec128.m128_f32[0] = v10 * (float)(v8 / v15);
  m->m_el[1].mVec128.m128_f32[1] = v13 * (float)(v8 / v15);
  m->m_el[1].mVec128.m128_f32[2] = v14 * (float)(v8 / v15);
  m->m_el[1].mVec128.m128_i32[3] = 0;
  v16 = m->m_el[2].mVec128.m128_f32[2];
  v17 = m->m_el[1].mVec128.m128_f32[2];
  v23 = m->m_el[1].mVec128.m128_f32[1];
  v18 = (float)(v16 * v23) - (float)(m->m_el[2].mVec128.m128_f32[1] * v17);
  v19 = m->m_el[2].mVec128.m128_f32[0];
  v20 = (float)(m->m_el[1].mVec128.m128_f32[0] * m->m_el[2].mVec128.m128_f32[1]) - (float)(v19 * v23);
  v21 = (float)(v19 * v17) - (float)(m->m_el[1].mVec128.m128_f32[0] * v16);
  v22 = v8 / fsqrt((float)((float)(v20 * v20) + (float)(v21 * v21)) + (float)(v18 * v18));
  m->m_el[0].mVec128.m128_f32[0] = v18 * v22;
  m->m_el[0].mVec128.m128_f32[1] = v21 * v22;
  m->m_el[0].mVec128.m128_f32[2] = v20 * v22;
  m->m_el[0].mVec128.m128_i32[3] = 0;
}
