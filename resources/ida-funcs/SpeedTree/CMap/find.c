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


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::find(
        _DWORD *this,
        _DWORD *a2,
        _DWORD *a3)
{
  int v4; // [esp+24h] [ebp-4h]

  v4 = this[1];
  while ( v4 && *(_DWORD *)(v4 + this[4]) != *a3 )
  {
    if ( *a3 >= *(_DWORD *)(v4 + this[4]) )
      v4 = *(_DWORD *)(v4 + this[4] + 28);
    else
      v4 = *(_DWORD *)(v4 + this[4] + 24);
  }
  *a2 = v4;
  a2[1] = this + 3;
  return a2;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::find(
        _DWORD *this,
        _DWORD *a2,
        _DWORD *a3)
{
  bool v4; // [esp+8h] [ebp-28h]
  _DWORD *v6; // [esp+1Ch] [ebp-14h]
  _DWORD *v7; // [esp+24h] [ebp-Ch]
  int v8; // [esp+2Ch] [ebp-4h]

  v8 = this[1];
  while ( v8 )
  {
    v7 = (_DWORD *)(v8 + this[4]);
    if ( *v7 == *a3 && v7[1] == a3[1] )
      break;
    v6 = (_DWORD *)(v8 + this[4]);
    if ( *a3 == *v6 )
      v4 = a3[1] < v6[1];
    else
      v4 = *a3 < *v6;
    if ( v4 )
      v8 = *(_DWORD *)(v8 + this[4] + 76);
    else
      v8 = *(_DWORD *)(v8 + this[4] + 80);
  }
  *a2 = v8;
  a2[1] = this + 3;
  return a2;
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::find(
        _DWORD *this,
        _DWORD *a2,
        _DWORD *a3)
{
  bool v4; // [esp+8h] [ebp-28h]
  _DWORD *v6; // [esp+1Ch] [ebp-14h]
  _DWORD *v7; // [esp+24h] [ebp-Ch]
  int v8; // [esp+2Ch] [ebp-4h]

  v8 = this[1];
  while ( v8 )
  {
    v7 = (_DWORD *)(v8 + this[4]);
    if ( *v7 == *a3 && v7[1] == a3[1] )
      break;
    v6 = (_DWORD *)(v8 + this[4]);
    if ( *a3 == *v6 )
      v4 = a3[1] < v6[1];
    else
      v4 = *a3 < *v6;
    if ( v4 )
      v8 = *(_DWORD *)(v8 + this[4] + 144);
    else
      v8 = *(_DWORD *)(v8 + this[4] + 148);
  }
  *a2 = v8;
  a2[1] = this + 3;
  return a2;
}
