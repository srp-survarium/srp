void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,int,1>::clear(
        SpeedTree::CMap<SpeedTree::CCore const *,int,1> *this)
{
  char *m_pRoot; // eax

  m_pRoot = (char *)this->m_pRoot;
  if ( m_pRoot )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode::DeleteChildren(
      (SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CNode *)&m_pRoot[(unsigned int)this->m_cPool.m_pData],
      this);
    this->m_cPool.m_pFreeLocations[this->m_cPool.m_uiCurrent++] = (unsigned int)this->m_pRoot;
    this->m_pRoot = 0;
  }
  this->m_uiSize = 0;
}
