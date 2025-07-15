_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::lower(
        _DWORD *this,
        _DWORD *a2,
        _DWORD *a3)
{
  bool v5; // [esp+10h] [ebp-38h]
  _DWORD *v7; // [esp+20h] [ebp-28h]
  _DWORD *v8; // [esp+30h] [ebp-18h]
  _DWORD *v9; // [esp+38h] [ebp-10h]
  int v10; // [esp+40h] [ebp-8h]
  int v11; // [esp+44h] [ebp-4h]

  v11 = this[1];
  v10 = 0;
  while ( v11 )
  {
    v9 = (_DWORD *)(v11 + this[4]);
    if ( *a3 == *v9 && a3[1] == v9[1] )
      break;
    v10 = v11;
    v8 = (_DWORD *)(v11 + this[4]);
    if ( *a3 == *v8 )
      v5 = a3[1] < v8[1];
    else
      v5 = *a3 < *v8;
    if ( v5 )
      v11 = *(_DWORD *)(v11 + this[4] + 144);
    else
      v11 = *(_DWORD *)(v11 + this[4] + 148);
  }
  if ( v11 )
  {
    *a2 = v11;
    a2[1] = this + 3;
    return a2;
  }
  else
  {
    while ( v10 )
    {
      v7 = (_DWORD *)(v10 + this[4]);
      if ( !(*a3 == *v7 ? a3[1] < v7[1] : *a3 < *v7) )
        break;
      v10 = *(_DWORD *)(v10 + this[4] + 152);
    }
    *a2 = v10;
    a2[1] = this + 3;
    return a2;
  }
}
