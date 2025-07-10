_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::higher(
        _DWORD *this,
        _DWORD *a2,
        _DWORD *a3)
{
  bool v4; // [esp+0h] [ebp-74h]
  bool v5; // [esp+8h] [ebp-6Ch]
  _DWORD *v6; // [esp+Ch] [ebp-68h]
  int v8; // [esp+14h] [ebp-60h]
  _DWORD *v9; // [esp+20h] [ebp-54h]
  _DWORD *v10; // [esp+24h] [ebp-50h]
  int v11; // [esp+64h] [ebp-10h] BYREF
  int v12; // [esp+68h] [ebp-Ch]
  int v13; // [esp+6Ch] [ebp-8h] BYREF
  int v14; // [esp+70h] [ebp-4h]

  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::lower(&v13, a3);
  if ( v13 )
  {
    if ( v14 )
      v9 = (_DWORD *)(v13 + *(_DWORD *)(v14 + 4));
    else
      v9 = 0;
    if ( *v9 == *a3 )
      v4 = v9[1] < a3[1];
    else
      v4 = *v9 < *a3;
    if ( v4 )
      SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(&v13);
  }
  else if ( this[2] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::begin(this, &v11);
    if ( v12 )
    {
      if ( v11 )
        v6 = (_DWORD *)(v11 + *(_DWORD *)(v12 + 4));
      else
        v6 = 0;
      v10 = v6;
    }
    else
    {
      v10 = 0;
    }
    if ( *a3 == *v10 )
      v5 = a3[1] < v10[1];
    else
      v5 = *a3 < *v10;
    if ( v5 )
    {
      v13 = v11;
      v14 = v12;
    }
  }
  v8 = v14;
  *a2 = v13;
  a2[1] = v8;
  return a2;
}
