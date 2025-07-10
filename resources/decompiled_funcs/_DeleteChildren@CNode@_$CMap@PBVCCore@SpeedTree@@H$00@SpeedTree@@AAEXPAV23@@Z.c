void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode::DeleteChildren(
        SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode *this,
        SpeedTree::CMap<SpeedTree::CCore const *,int,1> *pMap)
{
  char *m_pLeft; // eax
  SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode *v4; // ecx
  char *m_pRight; // eax
  SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode *v6; // ecx

  if ( this->m_pLeft )
  {
    m_pLeft = (char *)this->m_pLeft;
    if ( m_pLeft )
      v4 = (SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode *)&m_pLeft[(unsigned int)pMap->m_cPool.m_pData];
    else
      v4 = 0;
    SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode::DeleteChildren(v4, pMap);
    pMap->m_cPool.m_pFreeLocations[pMap->m_cPool.m_uiCurrent++] = (unsigned int)this->m_pLeft;
    this->m_pLeft = 0;
  }
  if ( this->m_pRight )
  {
    m_pRight = (char *)this->m_pRight;
    if ( m_pRight )
      v6 = (SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode *)&m_pRight[(unsigned int)pMap->m_cPool.m_pData];
    else
      v6 = 0;
    SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode::DeleteChildren(v6, pMap);
    pMap->m_cPool.m_pFreeLocations[pMap->m_cPool.m_uiCurrent++] = (unsigned int)this->m_pRight;
    this->m_pRight = 0;
  }
}
