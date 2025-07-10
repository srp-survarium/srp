int __thiscall SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::CLocalArray<SpeedTree::CTreeCell const *>(
        int this,
        unsigned int a2,
        char *a3,
        char a4)
{
  unsigned __int8 *pMemory; // [esp+68h] [ebp-14h]

  *(_DWORD *)this = &SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::`vftable';
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_BYTE *)(this + 16) = 0;
  *(_DWORD *)this = &SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::`vftable';
  *(_BYTE *)(this + 20) = 1;
  *(_DWORD *)(this + 24) = -1;
  pMemory = SpeedTree::CCore::LockTmpHeapBlock(4 * a2, a3, (int *)(this + 24));
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::SetExternalMemory(
    (SpeedTree::CArray<SpeedTree::CCore *,1> *)this,
    pMemory,
    4 * a2);
  if ( a4 )
  {
    if ( SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve((SpeedTree::CArray<SpeedTree::CCore *,1> *)this, a2) )
      *(_DWORD *)(this + 8) = a2;
    else
      *(_DWORD *)(this + 8) = *(_DWORD *)(this + 12);
  }
  return this;
}
