_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::begin(
        _DWORD *this,
        _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int i; // [esp+14h] [ebp-4h]

  if ( this[1] )
  {
    for ( i = this[1]; ; i = *(_DWORD *)(v3 + 24) )
    {
      v4 = i ? i + this[4] : 0;
      if ( !*(_DWORD *)(v4 + 24) )
        break;
      if ( i )
        v3 = i + this[4];
      else
        v3 = 0;
    }
    *a2 = i;
    a2[1] = this + 3;
    return a2;
  }
  else
  {
    *a2 = 0;
    a2[1] = 0;
    return a2;
  }
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::begin(_DWORD *this, _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int i; // [esp+14h] [ebp-4h]

  if ( this[1] )
  {
    for ( i = this[1]; ; i = *(_DWORD *)(v3 + 76) )
    {
      v4 = i ? i + this[4] : 0;
      if ( !*(_DWORD *)(v4 + 76) )
        break;
      if ( i )
        v3 = i + this[4];
      else
        v3 = 0;
    }
    *a2 = i;
    a2[1] = this + 3;
    return a2;
  }
  else
  {
    *a2 = 0;
    a2[1] = 0;
    return a2;
  }
}


_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(_DWORD *this, _DWORD *a2)
{
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int i; // [esp+14h] [ebp-4h]

  if ( this[1] )
  {
    for ( i = this[1]; ; i = *(_DWORD *)(v3 + 144) )
    {
      v4 = i ? i + this[4] : 0;
      if ( !*(_DWORD *)(v4 + 144) )
        break;
      if ( i )
        v3 = i + this[4];
      else
        v3 = 0;
    }
    *a2 = i;
    a2[1] = this + 3;
    return a2;
  }
  else
  {
    *a2 = 0;
    a2[1] = 0;
    return a2;
  }
}
