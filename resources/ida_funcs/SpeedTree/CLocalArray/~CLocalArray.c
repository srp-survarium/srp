void __thiscall SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::~CLocalArray<SpeedTree::CTreeCell const *>(
        int this)
{
  *(_DWORD *)this = &SpeedTree::CLocalArray<SpeedTree::CTreeCell const *>::`vftable';
  if ( *(_BYTE *)(this + 20) )
    SpeedTree::CCore::UnlockTmpHeapBlock(*(_DWORD *)(this + 24));
  *(_DWORD *)this = &SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::`vftable';
  if ( *(_BYTE *)(this + 16) )
    SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::SetExternalMemory(
      (SpeedTree::CArray<SpeedTree::CCore *,1> *)this,
      0,
      0);
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear((SpeedTree::CArray<SpeedTree::CCore *,1> *)this);
}
