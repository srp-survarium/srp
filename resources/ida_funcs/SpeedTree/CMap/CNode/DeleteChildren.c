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


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( this[6] )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(a2);
    result = SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(
               a2,
               this + 6);
  }
  if ( this[7] )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(a2);
    return SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(
             a2,
             this + 7);
  }
  return result;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( this[19] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(a2);
    result = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(a2, this + 19);
  }
  if ( this[20] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(a2);
    return SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(a2, this + 20);
  }
  return result;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CNode::DeleteChildren(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( this[36] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CNode::DeleteChildren(a2);
    result = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Deallocate(a2, this + 36);
  }
  if ( this[37] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CNode::DeleteChildren(a2);
    return SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Deallocate(a2, this + 37);
  }
  return result;
}
