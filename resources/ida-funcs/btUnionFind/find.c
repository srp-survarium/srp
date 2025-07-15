int __usercall btUnionFind::find@<eax>(btUnionFind *this@<edx>, int x@<eax>)
{
  btElement *m_data; // eax
  btElement *v3; // ecx
  btElement *v4; // eax
  int v5; // ecx

  while ( 1 )
  {
    v5 = x;
    if ( x == this->m_elements.m_data[x].m_id )
      break;
    m_data = this->m_elements.m_data;
    v3 = &m_data[v5];
    v4 = &m_data[v3->m_id];
    v3->m_id = v4->m_id;
    x = v4->m_id;
  }
  return x;
}
