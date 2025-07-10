btTransform *__usercall btTransform::inverse@<eax>(btTransform *this@<ecx>, btTransform *a2@<eax>)
{
  float v2; // xmm7_4
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm3_4
  unsigned __int64 v6; // [esp+30h] [ebp-40h]
  unsigned __int64 v7; // [esp+38h] [ebp-38h]
  unsigned __int64 v8; // [esp+40h] [ebp-30h]
  unsigned __int64 v9; // [esp+50h] [ebp-20h]
  unsigned __int64 v10; // [esp+58h] [ebp-18h]
  unsigned __int64 v11; // [esp+60h] [ebp-10h]
  unsigned __int64 v12; // [esp+68h] [ebp-8h]

  v2 = this->m_basis.m_el[2].mVec128.m128_f32[0];
  LODWORD(v8) = this->m_basis.m_el[0].mVec128.m128_i32[0];
  v12 = this->m_basis.m_el[2].mVec128.m128_u32[2];
  v3 = -this->m_origin.mVec128.m128_f32[1];
  v4 = -this->m_origin.mVec128.m128_f32[2];
  v5 = -this->m_origin.mVec128.m128_f32[0];
  HIDWORD(v8) = this->m_basis.m_el[1].mVec128.m128_i32[0];
  LODWORD(v9) = this->m_basis.m_el[0].mVec128.m128_i32[1];
  v10 = this->m_basis.m_el[2].mVec128.m128_u32[1];
  *(float *)&v6 = (float)((float)(this->m_basis.m_el[0].mVec128.m128_f32[0] * v5) + (float)(v4 * v2))
                + (float)(v3 * *((float *)&v8 + 1));
  HIDWORD(v9) = this->m_basis.m_el[1].mVec128.m128_i32[1];
  LODWORD(v11) = this->m_basis.m_el[0].mVec128.m128_i32[2];
  HIDWORD(v11) = this->m_basis.m_el[1].mVec128.m128_i32[2];
  HIDWORD(v7) = 0;
  a2->m_basis.m_el[0].mVec128.m128_u64[0] = v8;
  a2->m_basis.m_el[0].mVec128.m128_u64[1] = LODWORD(v2);
  a2->m_basis.m_el[1].mVec128.m128_u64[0] = v9;
  a2->m_basis.m_el[1].mVec128.m128_u64[1] = v10;
  a2->m_basis.m_el[2].mVec128.m128_u64[0] = v11;
  a2->m_basis.m_el[2].mVec128.m128_u64[1] = v12;
  *((float *)&v6 + 1) = (float)((float)(*((float *)&v9 + 1) * v3) + (float)(*(float *)&v10 * v4))
                      + (float)(*(float *)&v9 * v5);
  a2->m_origin.mVec128.m128_u64[0] = v6;
  *(float *)&v7 = (float)((float)(*((float *)&v11 + 1) * v3) + (float)(*(float *)&v12 * v4))
                + (float)(*(float *)&v11 * v5);
  a2->m_origin.mVec128.m128_u64[1] = v7;
  return a2;
}
