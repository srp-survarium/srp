void __usercall Orthogonalize(btMatrix3x3 *m@<esi>)
{
  float v1; // xmm4_4
  float v2; // xmm5_4
  float v3; // xmm6_4
  float v4; // xmm0_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // [esp+10h] [ebp-24h]
  float v16; // [esp+10h] [ebp-24h]
  float v17; // [esp+10h] [ebp-24h]
  btVector3 v18; // [esp+14h] [ebp-20h]
  float v19; // [esp+18h] [ebp-1Ch]
  float v20; // [esp+1Ch] [ebp-18h]
  btVector3 v21; // [esp+24h] [ebp-10h]

  v1 = m->m_el[1].mVec128.m128_f32[2];
  v2 = m->m_el[1].mVec128.m128_f32[1];
  v3 = m->m_el[1].mVec128.m128_f32[0];
  v4 = (float)(m->m_el[0].mVec128.m128_f32[1] * v1) - (float)(m->m_el[0].mVec128.m128_f32[2] * v2);
  v20 = (float)(m->m_el[0].mVec128.m128_f32[0] * v2) - (float)(m->m_el[0].mVec128.m128_f32[1] * v3);
  v19 = (float)(m->m_el[0].mVec128.m128_f32[2] * v3) - (float)(m->m_el[0].mVec128.m128_f32[0] * v1);
  v15 = 1.0 / sqrtf((float)((float)(v20 * v20) + (float)(v4 * v4)) + (float)(v19 * v19));
  v21.mVec128.m128_f32[0] = v4 * v15;
  v21.mVec128.m128_f32[1] = v15 * v19;
  v21.mVec128.m128_f32[2] = v20 * v15;
  v21.mVec128.m128_i32[3] = 0;
  m->m_el[2] = (btVector3)v21.mVec128;
  v5 = m->m_el[2].mVec128.m128_f32[1];
  v6 = m->m_el[2].mVec128.m128_f32[2];
  v7 = m->m_el[2].mVec128.m128_f32[0];
  v8 = m->m_el[0].mVec128.m128_f32[2];
  v21.mVec128.m128_f32[2] = (float)(m->m_el[0].mVec128.m128_f32[1] * v7) - (float)(m->m_el[0].mVec128.m128_f32[0] * v5);
  v21.mVec128.m128_f32[1] = (float)(m->m_el[0].mVec128.m128_f32[0] * v6) - (float)(v8 * v7);
  v21.mVec128.m128_f32[0] = (float)(v8 * v5) - (float)(m->m_el[0].mVec128.m128_f32[1] * v6);
  v16 = 1.0
      / sqrtf(
          (float)((float)(v21.mVec128.m128_f32[2] * v21.mVec128.m128_f32[2])
                + (float)(v21.mVec128.m128_f32[1] * v21.mVec128.m128_f32[1]))
        + (float)(v21.mVec128.m128_f32[0] * v21.mVec128.m128_f32[0]));
  v18.mVec128.m128_f32[0] = v21.mVec128.m128_f32[0] * v16;
  v18.mVec128.m128_f32[1] = v21.mVec128.m128_f32[1] * v16;
  v18.mVec128.m128_f32[2] = v21.mVec128.m128_f32[2] * v16;
  v18.mVec128.m128_i32[3] = 0;
  m->m_el[1] = (btVector3)v18.mVec128;
  v9 = m->m_el[1].mVec128.m128_f32[2];
  v10 = m->m_el[1].mVec128.m128_f32[1];
  v11 = (float)(m->m_el[2].mVec128.m128_f32[2] * v10) - (float)(m->m_el[2].mVec128.m128_f32[1] * v9);
  v12 = m->m_el[2].mVec128.m128_f32[0] * v9;
  v13 = m->m_el[1].mVec128.m128_f32[0];
  v14 = v12 - (float)(v13 * m->m_el[2].mVec128.m128_f32[2]);
  v21.mVec128.m128_f32[2] = (float)(v13 * m->m_el[2].mVec128.m128_f32[1])
                          - (float)(m->m_el[2].mVec128.m128_f32[0] * v10);
  v17 = 1.0
      / sqrtf((float)((float)(v21.mVec128.m128_f32[2] * v21.mVec128.m128_f32[2]) + (float)(v14 * v14)) + (float)(v11 * v11));
  v18.mVec128.m128_f32[0] = v11 * v17;
  v18.mVec128.m128_f32[1] = v14 * v17;
  v18.mVec128.m128_f32[2] = v21.mVec128.m128_f32[2] * v17;
  v18.mVec128.m128_i32[3] = 0;
  m->m_el[0] = (btVector3)v18.mVec128;
}
