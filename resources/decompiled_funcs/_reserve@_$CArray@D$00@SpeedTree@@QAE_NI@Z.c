bool __thiscall SpeedTree::CArray<char,1>::reserve(int this, unsigned int siNumElements)
{
  char *pRawBlock; // [esp+Ch] [ebp-40h] BYREF
  unsigned int i; // [esp+3Ch] [ebp-10h]
  char *v6; // [esp+40h] [ebp-Ch]
  char *v7; // [esp+44h] [ebp-8h]
  char *v8; // [esp+48h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= siNumElements;
  if ( siNumElements > *(_DWORD *)(this + 12) )
  {
    v8 = SpeedTree::st_new_array<char>(siNumElements);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(char **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
        *v6++ = *v7++;
    }
    pRawBlock = *(char **)(this + 4);
    SpeedTree::st_delete_array<char>(&pRawBlock);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = siNumElements;
  }
  return 1;
}
