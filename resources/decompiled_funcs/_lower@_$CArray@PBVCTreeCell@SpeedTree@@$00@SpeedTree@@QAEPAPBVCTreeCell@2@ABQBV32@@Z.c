int __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::lower(_DWORD *this, _DWORD *a2)
{
  int v3; // [esp+8h] [ebp-Ch]
  int v4; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  if ( !this[2] || *a2 < *(_DWORD *)this[1] )
    return this[1] + 4 * this[2];
  v4 = this[2] >> 1;
  v3 = this[1];
  v5 = v3 + 4 * this[2];
  while ( v4 )
  {
    if ( *a2 >= *(_DWORD *)(v3 + 4 * v4) )
      v3 += 4 * v4;
    else
      v5 = v3 + 4 * v4;
    v4 = ((v5 - v3) >> 2) / 2;
  }
  return v3;
}
