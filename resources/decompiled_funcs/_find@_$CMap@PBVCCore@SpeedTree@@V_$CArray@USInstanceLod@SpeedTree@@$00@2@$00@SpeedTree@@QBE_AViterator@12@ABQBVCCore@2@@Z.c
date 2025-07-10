SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::iterator *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::find(
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *this,
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::iterator *result,
        const SpeedTree::CCore *const *tKey)
{
  char *m_pRoot; // edx
  unsigned int v4; // esi
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::iterator *v5; // eax

  m_pRoot = (char *)this->m_pRoot;
  if ( m_pRoot )
  {
    v4 = (unsigned int)*tKey;
    do
    {
      if ( *(_DWORD *)&m_pRoot[(unsigned int)this->m_cPool.m_pData] == v4 )
        break;
      m_pRoot = v4 >= *(_DWORD *)&m_pRoot[(unsigned int)this->m_cPool.m_pData]
              ? *(char **)&m_pRoot[(unsigned int)this->m_cPool.m_pData + 28]
              : *(char **)&m_pRoot[(unsigned int)this->m_cPool.m_pData + 24];
    }
    while ( m_pRoot );
  }
  v5 = result;
  result->m_pNode = m_pRoot;
  result->m_pPool = &this->m_cPool;
  return v5;
}
