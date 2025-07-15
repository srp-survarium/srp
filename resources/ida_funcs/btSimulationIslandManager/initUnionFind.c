void __usercall btSimulationIslandManager::initUnionFind(
        btSimulationIslandManager *this@<eax>,
        int n@<edi>,
        btUnionFind *a3@<ecx>)
{
  btUnionFind *p_m_unionFind; // esi
  int i; // eax

  p_m_unionFind = &this->m_unionFind;
  btUnionFind::allocate(a3, (int)&this->m_unionFind, n);
  for ( i = 0; i < n; ++i )
  {
    p_m_unionFind->m_elements.m_data[i].m_id = i;
    p_m_unionFind->m_elements.m_data[i].m_sz = 1;
  }
}
