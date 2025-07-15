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


char *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>(
        char *this,
        unsigned int uiSize)
{
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = &SpeedTree::CBlockPool<1>::`vftable';
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 40;
  SpeedTree::CBlockPool<1>::resize((SpeedTree::CBlockPool<1> *)(this + 12), uiSize);
  return this;
}


char *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>(
        char *this,
        unsigned int uiSize)
{
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = &SpeedTree::CBlockPool<1>::`vftable';
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 92;
  SpeedTree::CBlockPool<1>::resize((SpeedTree::CBlockPool<1> *)(this + 12), uiSize);
  return this;
}


char *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>(
        char *this,
        unsigned int uiSize)
{
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = &SpeedTree::CBlockPool<1>::`vftable';
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 160;
  SpeedTree::CBlockPool<1>::resize((SpeedTree::CBlockPool<1> *)(this + 12), uiSize);
  return this;
}
