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
