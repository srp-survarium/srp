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


void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::clear(
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *this)
{
  char *m_pRoot; // eax
  void **p_m_pRoot; // edi

  m_pRoot = (char *)this->m_pRoot;
  p_m_pRoot = &this->m_pRoot;
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
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::clear(
        _DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  if ( this[1] )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(this);
    result = (_DWORD *)SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(this + 1);
    this[1] = 0;
  }
  this[2] = 0;
  return result;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::clear(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  if ( this[1] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(this);
    result = (_DWORD *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(this + 1);
    this[1] = 0;
  }
  this[2] = 0;
  return result;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::clear(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  if ( this[1] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CNode::DeleteChildren(this);
    result = (_DWORD *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Deallocate(this + 1);
    this[1] = 0;
  }
  this[2] = 0;
  return result;
}
