bool __thiscall SpeedTree::CArray<unsigned char,1>::reserve(int this, unsigned int count)
{
  _DWORD v4[4]; // [esp+Ch] [ebp-40h] BYREF
  unsigned int i; // [esp+3Ch] [ebp-10h]
  unsigned int *v6; // [esp+40h] [ebp-Ch]
  _BYTE *v7; // [esp+44h] [ebp-8h]
  unsigned int *v8; // [esp+48h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= count;
  if ( count > *(_DWORD *)(this + 12) )
  {
    v8 = SpeedTree::st_new_array<unsigned char>(count);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(_BYTE **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
      {
        *(_BYTE *)v6 = *v7;
        v6 = (unsigned int *)((char *)v6 + 1);
        ++v7;
      }
    }
    v4[0] = *(_DWORD *)(this + 4);
    SpeedTree::st_delete_array<unsigned char>(v4);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = count;
  }
  return 1;
}
