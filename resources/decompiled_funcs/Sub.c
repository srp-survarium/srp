btMatrix3x3 *__fastcall Sub(const btMatrix3x3 *b, const btMatrix3x3 *a, int a3)
{
  btMatrix3x3 *result; // eax
  unsigned int v4; // xmm0_4
  float v5; // xmm1_4
  __int64 v6; // [esp+0h] [ebp-10h]
  __int64 v7; // [esp+8h] [ebp-8h]

  result = (btMatrix3x3 *)a3;
  *(float *)&v6 = a->m_el[0].mVec128.m128_f32[0] - b->m_el[0].mVec128.m128_f32[0];
  *((float *)&v6 + 1) = a->m_el[0].mVec128.m128_f32[1] - b->m_el[0].mVec128.m128_f32[1];
  *(float *)&v4 = a->m_el[0].mVec128.m128_f32[2] - b->m_el[0].mVec128.m128_f32[2];
  *(_QWORD *)a3 = v6;
  v7 = v4;
  *(_QWORD *)(a3 + 8) = v4;
  *(float *)&v6 = a->m_el[1].mVec128.m128_f32[0] - b->m_el[1].mVec128.m128_f32[0];
  *((float *)&v6 + 1) = a->m_el[1].mVec128.m128_f32[1] - b->m_el[1].mVec128.m128_f32[1];
  *(float *)&v7 = a->m_el[1].mVec128.m128_f32[2] - b->m_el[1].mVec128.m128_f32[2];
  *(_QWORD *)(a3 + 16) = v6;
  HIDWORD(v7) = 0;
  *(_QWORD *)(a3 + 24) = (unsigned int)v7;
  *(float *)&v6 = a->m_el[2].mVec128.m128_f32[0] - b->m_el[2].mVec128.m128_f32[0];
  *((float *)&v6 + 1) = a->m_el[2].mVec128.m128_f32[1] - b->m_el[2].mVec128.m128_f32[1];
  v5 = a->m_el[2].mVec128.m128_f32[2] - b->m_el[2].mVec128.m128_f32[2];
  HIDWORD(v7) = 0;
  *(_QWORD *)(a3 + 32) = v6;
  *(float *)&v7 = v5;
  *(_QWORD *)(a3 + 40) = v7;
  return result;
}
