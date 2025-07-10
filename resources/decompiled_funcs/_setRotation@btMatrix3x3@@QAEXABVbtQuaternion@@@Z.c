void __usercall btMatrix3x3::setRotation(btMatrix3x3 *this@<ecx>, int a2@<eax>)
{
  float v2; // xmm2_4
  float v3; // xmm3_4
  float v4; // xmm1_4
  float v5; // xmm5_4
  float v6; // xmm4_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm6_4
  const vostok::math::float4x4 *v15; // xmm4_4
  float wz; // [esp+0h] [ebp-Ch]
  float wy; // [esp+4h] [ebp-8h]
  float wx; // [esp+8h] [ebp-4h]

  v2 = this->m_el[0].mVec128.m128_f32[1];
  v3 = this->m_el[0].mVec128.m128_f32[2];
  v4 = this->m_el[0].mVec128.m128_f32[3];
  v5 = 2.0
     / (float)((float)((float)((float)(this->m_el[0].mVec128.m128_f32[0] * this->m_el[0].mVec128.m128_f32[0])
                             + (float)(v2 * v2))
                     + (float)(v3 * v3))
             + (float)(v4 * v4));
  v6 = v3 * v5;
  v7 = this->m_el[0].mVec128.m128_f32[0] * v5;
  v8 = v2 * v5;
  wx = v4 * v7;
  wy = v4 * (float)(v2 * v5);
  v9 = v3 * (float)(v3 * v5);
  wz = v4 * v6;
  v10 = this->m_el[0].mVec128.m128_f32[0] * v7;
  v11 = this->m_el[0].mVec128.m128_f32[0] * v6;
  v12 = this->m_el[0].mVec128.m128_f32[0] * (float)(v2 * v5);
  v13 = v2 * v6;
  v14 = this->m_el[0].mVec128.m128_f32[1] * v8;
  *(float *)a2 = *(float *)&clear_value - (float)(v9 + v14);
  *(float *)(a2 + 4) = v12 - wz;
  *(_DWORD *)(a2 + 12) = 0;
  *(float *)(a2 + 8) = v11 + wy;
  v15 = clear_value;
  *(float *)(a2 + 16) = v12 + wz;
  *(float *)(a2 + 20) = *(float *)&v15 - (float)(v9 + v10);
  *(_DWORD *)(a2 + 28) = 0;
  *(float *)(a2 + 24) = v13 - wx;
  *(float *)(a2 + 32) = v11 - wy;
  *(float *)(a2 + 36) = v13 + wx;
  *(float *)(a2 + 40) = *(float *)&v15 - (float)(v14 + v10);
  *(_DWORD *)(a2 + 44) = 0;
}
