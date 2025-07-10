btUnionFind *__usercall btUnionFind::btUnionFind@<eax>(btUnionFind *this@<ecx>, btUnionFind *result@<eax>)
{
  result->m_elements.m_ownsMemory = 1;
  result->m_elements.m_data = 0;
  result->m_elements.m_size = 0;
  result->m_elements.m_capacity = 0;
  return result;
}
