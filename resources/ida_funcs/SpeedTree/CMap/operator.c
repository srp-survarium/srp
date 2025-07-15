int __thiscall SpeedTree::CMap<SpeedTree::CCore const *,int,1>::operator[](_DWORD *this, _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-138h]
  int v5; // [esp+130h] [ebp-8h]
  int v6; // [esp+134h] [ebp-4h]

  v6 = this[1];
  v5 = 0;
  while ( v6 && *a2 != *(_DWORD *)(v6 + this[4]) )
  {
    v5 = v6;
    if ( *a2 >= *(_DWORD *)(v6 + this[4]) )
      v6 = *(_DWORD *)(v6 + this[4] + 12);
    else
      v6 = *(_DWORD *)(v6 + this[4] + 8);
  }
  if ( !v6 )
  {
    v6 = SpeedTree::CMap<SpeedTree::CCore const *,int,1>::Allocate(a2, v5);
    if ( v5 )
    {
      if ( *a2 >= *(_DWORD *)(v5 + this[4]) )
        *(_DWORD *)(v5 + this[4] + 12) = v6;
      else
        *(_DWORD *)(v5 + this[4] + 8) = v6;
    }
    else
    {
      this[1] = v6;
    }
    SpeedTree::CMap<SpeedTree::CCore const *,int,1>::Rebalance(v5);
    ++this[2];
  }
  if ( v6 )
    v3 = v6 + this[4];
  else
    v3 = 0;
  return v3 + 4;
}


int __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::operator[](
        _DWORD *this,
        _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-138h]
  int v5; // [esp+130h] [ebp-8h]
  int v6; // [esp+134h] [ebp-4h]

  v6 = this[1];
  v5 = 0;
  while ( v6 && *a2 != *(_DWORD *)(v6 + this[4]) )
  {
    v5 = v6;
    if ( *a2 >= *(_DWORD *)(v6 + this[4]) )
      v6 = *(_DWORD *)(v6 + this[4] + 28);
    else
      v6 = *(_DWORD *)(v6 + this[4] + 24);
  }
  if ( !v6 )
  {
    v6 = SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Allocate(a2, v5);
    if ( v5 )
    {
      if ( *a2 >= *(_DWORD *)(v5 + this[4]) )
        *(_DWORD *)(v5 + this[4] + 28) = v6;
      else
        *(_DWORD *)(v5 + this[4] + 24) = v6;
    }
    else
    {
      this[1] = v6;
    }
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Rebalance(v5);
    ++this[2];
  }
  if ( v6 )
    v3 = v6 + this[4];
  else
    v3 = 0;
  return v3 + 4;
}


int __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::operator[](
        _DWORD *this,
        _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-138h]
  int v5; // [esp+130h] [ebp-8h]
  int v6; // [esp+134h] [ebp-4h]

  v6 = this[1];
  v5 = 0;
  while ( v6 && *a2 != *(_DWORD *)(v6 + this[4]) )
  {
    v5 = v6;
    if ( *a2 >= *(_DWORD *)(v6 + this[4]) )
      v6 = *(_DWORD *)(v6 + this[4] + 28);
    else
      v6 = *(_DWORD *)(v6 + this[4] + 24);
  }
  if ( !v6 )
  {
    v6 = SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Allocate(a2, v5);
    if ( v5 )
    {
      if ( *a2 >= *(_DWORD *)(v5 + this[4]) )
        *(_DWORD *)(v5 + this[4] + 28) = v6;
      else
        *(_DWORD *)(v5 + this[4] + 24) = v6;
    }
    else
    {
      this[1] = v6;
    }
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Rebalance(v5);
    ++this[2];
  }
  if ( v6 )
    v3 = v6 + this[4];
  else
    v3 = 0;
  return v3 + 4;
}


int __thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::operator[](_DWORD *this, _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-144h]
  bool v4; // [esp+Ch] [ebp-138h]
  bool v5; // [esp+18h] [ebp-12Ch]
  _DWORD *v8; // [esp+10Ch] [ebp-38h]
  _DWORD *v9; // [esp+12Ch] [ebp-18h]
  _DWORD *v10; // [esp+134h] [ebp-10h]
  int v11; // [esp+13Ch] [ebp-8h]
  int v12; // [esp+140h] [ebp-4h]

  v12 = this[1];
  v11 = 0;
  while ( v12 )
  {
    v10 = (_DWORD *)(v12 + this[4]);
    if ( *a2 == *v10 && a2[1] == v10[1] )
      break;
    v11 = v12;
    v9 = (_DWORD *)(v12 + this[4]);
    if ( *a2 == *v9 )
      v5 = a2[1] < v9[1];
    else
      v5 = *a2 < *v9;
    if ( v5 )
      v12 = *(_DWORD *)(v12 + this[4] + 76);
    else
      v12 = *(_DWORD *)(v12 + this[4] + 80);
  }
  if ( !v12 )
  {
    v12 = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Allocate(a2, v11);
    if ( v11 )
    {
      v8 = (_DWORD *)(v11 + this[4]);
      if ( *a2 == *v8 )
        v4 = a2[1] < v8[1];
      else
        v4 = *a2 < *v8;
      if ( v4 )
        *(_DWORD *)(v11 + this[4] + 76) = v12;
      else
        *(_DWORD *)(v11 + this[4] + 80) = v12;
    }
    else
    {
      this[1] = v12;
    }
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Rebalance(this, v11);
    ++this[2];
  }
  if ( v12 )
    v3 = v12 + this[4];
  else
    v3 = 0;
  return v3 + 8;
}


int __thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::operator[](_DWORD *this, _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-144h]
  bool v4; // [esp+Ch] [ebp-138h]
  bool v5; // [esp+18h] [ebp-12Ch]
  _DWORD *v8; // [esp+10Ch] [ebp-38h]
  _DWORD *v9; // [esp+12Ch] [ebp-18h]
  _DWORD *v10; // [esp+134h] [ebp-10h]
  int v11; // [esp+13Ch] [ebp-8h]
  int v12; // [esp+140h] [ebp-4h]

  v12 = this[1];
  v11 = 0;
  while ( v12 )
  {
    v10 = (_DWORD *)(v12 + this[4]);
    if ( *a2 == *v10 && a2[1] == v10[1] )
      break;
    v11 = v12;
    v9 = (_DWORD *)(v12 + this[4]);
    if ( *a2 == *v9 )
      v5 = a2[1] < v9[1];
    else
      v5 = *a2 < *v9;
    if ( v5 )
      v12 = *(_DWORD *)(v12 + this[4] + 144);
    else
      v12 = *(_DWORD *)(v12 + this[4] + 148);
  }
  if ( !v12 )
  {
    v12 = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Allocate(a2, v11);
    if ( v11 )
    {
      v8 = (_DWORD *)(v11 + this[4]);
      if ( *a2 == *v8 )
        v4 = a2[1] < v8[1];
      else
        v4 = *a2 < *v8;
      if ( v4 )
        *(_DWORD *)(v11 + this[4] + 144) = v12;
      else
        *(_DWORD *)(v11 + this[4] + 148) = v12;
    }
    else
    {
      this[1] = v12;
    }
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Rebalance(this, v11);
    ++this[2];
  }
  if ( v12 )
    v3 = v12 + this[4];
  else
    v3 = 0;
  return v3 + 8;
}
