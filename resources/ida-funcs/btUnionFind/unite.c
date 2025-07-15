void __userpurge btUnionFind::unite(btUnionFind *this@<esi>, int p@<eax>, int q)
{
  int v3; // edi
  int v4; // eax

  v3 = btUnionFind::find(this, p);
  v4 = btUnionFind::find(this, q);
  if ( v3 != v4 )
  {
    this->m_elements.m_data[v3].m_id = v4;
    this->m_elements.m_data[v4].m_sz += this->m_elements.m_data[v3].m_sz;
  }
}
