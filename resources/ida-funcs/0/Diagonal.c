btMatrix3x3 *__usercall Diagonal@<eax>(btMatrix3x3 *result@<eax>, unsigned int a2@<xmm1>)
{
  result->m_el[0].mVec128.m128_u64[0] = a2;
  result->m_el[0].mVec128.m128_u64[1] = 0;
  result->m_el[1].mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)result->m_el[1].mVec128.m128_u64 + 4) = a2;
  result->m_el[1].mVec128.m128_i32[3] = 0;
  result->m_el[2].mVec128.m128_u64[0] = 0;
  result->m_el[2].mVec128.m128_u64[1] = a2;
  return result;
}
