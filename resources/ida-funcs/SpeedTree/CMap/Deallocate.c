void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Deallocate(
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *this,
        void **pData)
{
  char *v3; // eax
  bool v4; // zf
  SpeedTree::CArray<SpeedTree::SInstanceLod,1> *v5; // esi

  if ( *pData )
    v3 = (char *)*pData + (unsigned int)this->m_cPool.m_pData;
  else
    v3 = 0;
  v4 = v3[20] == 0;
  v5 = (SpeedTree::CArray<SpeedTree::SInstanceLod,1> *)(v3 + 4);
  *((_DWORD *)v3 + 1) = &SpeedTree::CArray<SpeedTree::SInstanceLod,1>::`vftable';
  if ( !v4 )
  {
    SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear((SpeedTree::CArray<SpeedTree::SInstanceLod,1> *)(v3 + 4));
    if ( v5->m_bExternalMemory )
    {
      v5->m_uiDataSize = 0;
      v5->m_pData = 0;
    }
    v5->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear(v5);
  this->m_cPool.m_pFreeLocations[this->m_cPool.m_uiCurrent++] = (unsigned int)*pData;
  *pData = 0;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  if ( *a2 )
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::~CNode(*a2 + this[4]);
  else
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::~CNode(0);
  *(_DWORD *)(this[5] + 4 * this[7]) = *a2;
  result = this + 3;
  ++this[7];
  *a2 = 0;
  return result;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  _DWORD *p; // [esp+8h] [ebp-Ch]

  if ( *a2 )
    p = (_DWORD *)(*a2 + this[4]);
  else
    p = 0;
  p[2] = &SpeedTree::CGrassCell::`vftable';
  p[2] = &SpeedTree::CCell::`vftable';
  *(_DWORD *)(this[5] + 4 * this[7]) = *a2;
  result = this + 3;
  ++this[7];
  *a2 = 0;
  return result;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Deallocate(_DWORD *this, _DWORD *a2)
{
  _DWORD *result; // eax
  char *p; // [esp+Ch] [ebp-30h]

  if ( *a2 )
    p = (char *)(*a2 + this[4]);
  else
    p = 0;
  *((_DWORD *)p + 2) = &SpeedTree::CTreeCell::`vftable';
  SpeedTree::CCellInstances::~CCellInstances((SpeedTree::CCellInstances *)(p + 64));
  *((_DWORD *)p + 2) = &SpeedTree::CCell::`vftable';
  *(_DWORD *)(this[5] + 4 * this[7]) = *a2;
  result = this + 3;
  ++this[7];
  *a2 = 0;
  return result;
}
