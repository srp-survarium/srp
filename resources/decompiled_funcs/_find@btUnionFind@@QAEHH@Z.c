int __usercall btUnionFind::find@<eax>(btUnionFind *this@<esi>, int x@<eax>)
{
  int i; // ecx
  btElement *m_data; // eax
  int m_id; // edx

  for ( i = x; x != this->m_elements.m_data[x].m_id; i = x )
  {
    m_data = this->m_elements.m_data;
    m_id = m_data[i].m_id;
    m_data[i].m_id = m_data[m_id].m_id;
    x = m_data[m_id].m_id;
  }
  return x;
}
