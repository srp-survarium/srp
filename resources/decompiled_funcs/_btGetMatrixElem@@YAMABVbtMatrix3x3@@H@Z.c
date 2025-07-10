int __usercall btGetMatrixElem@<xmm0>(const btMatrix3x3 *mat)
{
  int index; // ecx

  return *(int *)((char *)mat->m_el[0].mVec128.m128_i32 + 16 * index - 44 * (index / 3));
}
