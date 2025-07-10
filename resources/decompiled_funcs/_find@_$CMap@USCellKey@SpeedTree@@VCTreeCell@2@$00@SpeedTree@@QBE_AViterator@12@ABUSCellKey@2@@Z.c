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
