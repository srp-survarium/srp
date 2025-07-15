btTransform *__userpurge btTransform::inverse@<eax>(btTransform *this@<ecx>, int a2@<eax>, btTransform *result)
{
  int v4; // xmm1_4
  int v5; // xmm2_4
  int v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  unsigned __int64 v19; // [esp+10h] [ebp-40h]
  btMatrix3x3 v20; // [esp+20h] [ebp-30h] BYREF

  btMatrix3x3::btMatrix3x3(
    (btMatrix3x3 *)a2,
    &v20,
    (float *)(a2 + 16),
    (float *)(a2 + 32),
    (float *)(a2 + 4),
    (float *)(a2 + 20),
    (float *)(a2 + 36),
    (float *)(a2 + 8),
    (float *)(a2 + 24),
    (const float *)(a2 + 40));
  v4 = *(_DWORD *)(a2 + 48);
  v5 = *(_DWORD *)(a2 + 52);
  v6 = *(_DWORD *)(a2 + 56);
  v7 = v20.m_el[0].mVec128.m128_f32[1];
  result->m_basis.m_el[0].mVec128.m128_u64[0] = v20.m_el[0].mVec128.m128_u64[0];
  result->m_basis.m_el[0].mVec128.m128_u64[1] = v20.m_el[0].mVec128.m128_u64[1];
  LODWORD(v8) = v4 ^ _mask__NegFloat_;
  LODWORD(v9) = v5 ^ _mask__NegFloat_;
  LODWORD(v10) = v6 ^ _mask__NegFloat_;
  v11 = v20.m_el[0].mVec128.m128_f32[0] * v8;
  result->m_basis.m_el[1].mVec128.m128_u64[0] = v20.m_el[1].mVec128.m128_u64[0];
  result->m_basis.m_el[1].mVec128.m128_i32[2] = v20.m_el[1].mVec128.m128_i32[2];
  v12 = v11 + (float)(v7 * v9);
  v13 = v20.m_el[0].mVec128.m128_f32[2];
  result->m_basis.m_el[1].mVec128.m128_i32[3] = v20.m_el[1].mVec128.m128_i32[3];
  *(float *)&v19 = v12 + (float)(v13 * v10);
  v14 = (float)(v20.m_el[1].mVec128.m128_f32[0] * v8) + (float)(v20.m_el[1].mVec128.m128_f32[2] * v10);
  v15 = v20.m_el[1].mVec128.m128_f32[1];
  result->m_basis.m_el[2].mVec128.m128_u64[0] = v20.m_el[2].mVec128.m128_u64[0];
  *((float *)&v19 + 1) = v14 + (float)(v15 * v9);
  v16 = (float)(v20.m_el[2].mVec128.m128_f32[0] * v8) + (float)(v20.m_el[2].mVec128.m128_f32[2] * v10);
  v17 = v20.m_el[2].mVec128.m128_f32[1];
  result->m_basis.m_el[2].mVec128.m128_u64[1] = v20.m_el[2].mVec128.m128_u64[1];
  result->m_origin.mVec128.m128_u64[0] = v19;
  result->m_origin.mVec128.m128_f32[2] = v16 + (float)(v17 * v9);
  result->m_origin.mVec128.m128_i32[3] = 0;
  return result;
}
