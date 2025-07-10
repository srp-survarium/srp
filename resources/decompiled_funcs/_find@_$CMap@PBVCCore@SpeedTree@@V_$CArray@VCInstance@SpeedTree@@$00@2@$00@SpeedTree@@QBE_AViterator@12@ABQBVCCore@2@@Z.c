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
