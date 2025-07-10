void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode::DeleteChildren(
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode *this,
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *pMap)
{
  void **p_m_pLeft; // esi

  p_m_pLeft = &this->m_pLeft;
  if ( this->m_pLeft )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode::DeleteChildren(
      (SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode *)((char *)*p_m_pLeft + (unsigned int)pMap->m_cPool.m_pData),
      pMap);
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Deallocate(
      pMap,
      p_m_pLeft);
  }
  if ( this->m_pRight )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode::DeleteChildren(
      (SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::CNode *)((char *)this->m_pRight + (unsigned int)pMap->m_cPool.m_pData),
      pMap);
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Deallocate(
      pMap,
      &this->m_pRight);
  }
}
