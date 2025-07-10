void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CMap<SpeedTree::CCore const *,int,1>(
        SpeedTree::CMap<SpeedTree::CCore const *,int,1> *this,
        unsigned int uiStartingPoolSize)
{
  SpeedTree::CBlockPool<1> *p_m_cPool; // ecx

  this->m_pRoot = 0;
  this->m_uiSize = 0;
  p_m_cPool = &this->m_cPool;
  this->__vftable = (SpeedTree::CMap<SpeedTree::CCore const *,int,1>_vtbl *)&SpeedTree::CMap<SpeedTree::CCore const *,int,1>::`vftable';
  p_m_cPool->m_pData = 0;
  p_m_cPool->m_pFreeLocations = 0;
  p_m_cPool->m_uiSize = 0;
  p_m_cPool->m_uiCurrent = 0;
  p_m_cPool->__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  p_m_cPool->m_uiBlockSize = 24;
  SpeedTree::CBlockPool<1>::resize(p_m_cPool, uiStartingPoolSize);
}
