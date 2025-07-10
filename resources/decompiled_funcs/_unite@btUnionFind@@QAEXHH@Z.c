void __userpurge btUnionFind::unite(btUnionFind *this@<ecx>, int p@<eax>, int q)
{
  int v4; // edi
  int v5; // eax

  v4 = btUnionFind::find(this, p);
  v5 = btUnionFind::find(this, q);
  if ( v4 != v5 )
  {
    this->m_elements.m_data[v4].m_id = v5;
    this->m_elements.m_data[v5].m_sz += this->m_elements.m_data[v4].m_sz;
  }
}
