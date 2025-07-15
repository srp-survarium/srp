btMatrix3x3 *__usercall Diagonal@<eax>(btMatrix3x3 *result@<eax>, unsigned int a2@<xmm1>)
{
  unsigned __int64 v3; // xmm2_8
  unsigned __int64 v4; // xmm0_8
  unsigned __int64 v5; // [esp+0h] [ebp-10h]
  unsigned __int64 v6; // [esp+8h] [ebp-8h]

  v6 = 0;
  result->m_el[0].mVec128.m128_u64[0] = a2;
  LODWORD(v5) = 0;
  HIDWORD(v5) = a2;
  result->m_el[0].mVec128.m128_u64[1] = v6;
  v6 = 0;
  result->m_el[1].mVec128.m128_u64[0] = v5;
  v3 = v6;
  HIDWORD(v6) = 0;
  result->m_el[2].mVec128.m128_u64[0] = 0;
  LODWORD(v6) = a2;
  v4 = v6;
  result->m_el[1].mVec128.m128_u64[1] = v3;
  result->m_el[2].mVec128.m128_u64[1] = v4;
  return result;
}
