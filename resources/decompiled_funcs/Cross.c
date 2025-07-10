btMatrix3x3 *__usercall Cross@<eax>(const btVector3 *v@<ecx>, btMatrix3x3 *result@<eax>)
{
  unsigned __int64 v2; // [esp+0h] [ebp-10h]
  int v3; // [esp+8h] [ebp-8h]
  unsigned int v4; // [esp+8h] [ebp-8h]

  *((float *)&v2 + 1) = -v->mVec128.m128_f32[2];
  v3 = v->mVec128.m128_i32[1];
  LODWORD(v2) = 0;
  result->m_el[0].mVec128.m128_u64[0] = v2;
  result->m_el[0].mVec128.m128_u64[1] = (unsigned int)v3;
  *(float *)&v4 = -v->mVec128.m128_f32[0];
  result->m_el[1].mVec128.m128_u64[0] = v->mVec128.m128_u32[2];
  result->m_el[1].mVec128.m128_u64[1] = v4;
  result->m_el[2].mVec128.m128_u64[0] = __PAIR64__(v->mVec128.m128_i32[0], -v->mVec128.m128_f32[1]);
  result->m_el[2].mVec128.m128_u64[1] = 0;
  return result;
}
