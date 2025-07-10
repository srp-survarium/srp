void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::~CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>(
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *this)
{
  char *m_pRoot; // eax
  void **p_m_pRoot; // edi

  m_pRoot = (char *)this->m_pRoot;
  p_m_pRoot = &this->m_pRoot;
  this->__vftable = (SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>_vtbl *)&SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::`vftable';
  if ( m_pRoot )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode::DeleteChildren(
      (SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode *)&m_pRoot[(unsigned int)this->m_cPool.m_pData],
      this);
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Deallocate(
      this,
      p_m_pRoot);
    *p_m_pRoot = 0;
  }
  this->m_uiSize = 0;
  this->m_cPool.__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear(&this->m_cPool, 0);
}
