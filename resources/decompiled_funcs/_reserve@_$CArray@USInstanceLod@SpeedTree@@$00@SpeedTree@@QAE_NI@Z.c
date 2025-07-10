bool __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::reserve(int this, unsigned int a2)
{
  SpeedTree::SInstanceLod *pRawBlock; // [esp+10h] [ebp-5Ch] BYREF
  unsigned int i; // [esp+5Ch] [ebp-10h]
  char *v6; // [esp+60h] [ebp-Ch]
  char *v7; // [esp+64h] [ebp-8h]
  char *v8; // [esp+68h] [ebp-4h]

  if ( *(_BYTE *)(this + 16) )
    return *(_DWORD *)(this + 12) >= a2;
  if ( a2 > *(_DWORD *)(this + 12) )
  {
    v8 = (char *)SpeedTree::CArray<SpeedTree::SInstanceLod,1>::Allocate(a2);
    if ( *(_DWORD *)(this + 8) )
    {
      v6 = v8;
      v7 = *(char **)(this + 4);
      for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
      {
        qmemcpy(v6, v7, 0x20u);
        v6 += 32;
        v7 += 32;
      }
    }
    pRawBlock = *(SpeedTree::SInstanceLod **)(this + 4);
    SpeedTree::st_delete_array<SpeedTree::SInstanceLod>(&pRawBlock);
    *(_DWORD *)(this + 4) = v8;
    *(_DWORD *)(this + 12) = a2;
  }
  return 1;
}
