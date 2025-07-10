bool __thiscall SpeedTree::CArray<int,1>::reserve(int this, unsigned int a2)
{
  _DWORD v4[4]; // [esp+8h] [ebp-40h] BYREF
  unsigned int i; // [esp+38h] [ebp-10h]
  _DWORD *v6; // [esp+3Ch] [ebp-Ch]
  _DWORD *v7; // [esp+40h] [ebp-8h]
  int v8; // [esp+44h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= a2;
  if ( a2 > *(_DWORD *)(this + 12) )
  {
    v8 = SpeedTree::CArray<float,1>::Allocate(a2);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = (_DWORD *)v8;
      v7 = *(_DWORD **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
        *v6++ = *v7++;
    }
    v4[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<float>(v4);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = a2;
  }
  return 1;
}
