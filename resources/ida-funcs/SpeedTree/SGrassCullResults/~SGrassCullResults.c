void __usercall SpeedTree::SGrassCullResults::~SGrassCullResults(
        SpeedTree::SGrassCullResults *this@<ecx>,
        int a2@<edi>)
{
  SpeedTree::CArray<void *,1> *v2; // ecx
  SpeedTree::CArray<void *,1> *v3; // ecx

  *(_DWORD *)(a2 + 40) = &SpeedTree::CArray<SpeedTree::CGrassCell *,1>::`vftable';
  if ( *(_BYTE *)(a2 + 56) )
  {
    SpeedTree::CArray<void *,1>::clear((SpeedTree::CArray<void *,1> *)this);
    if ( *(_BYTE *)(a2 + 56) )
    {
      *(_DWORD *)(a2 + 52) = 0;
      *(_DWORD *)(a2 + 44) = 0;
    }
    *(_BYTE *)(a2 + 56) = 0;
  }
  SpeedTree::CArray<void *,1>::clear((SpeedTree::CArray<void *,1> *)this);
  *(_DWORD *)(a2 + 20) = &SpeedTree::CArray<void *,1>::`vftable';
  if ( *(_BYTE *)(a2 + 36) )
  {
    SpeedTree::CArray<void *,1>::clear(v2);
    if ( *(_BYTE *)(a2 + 36) )
    {
      *(_DWORD *)(a2 + 32) = 0;
      *(_DWORD *)(a2 + 24) = 0;
    }
    *(_BYTE *)(a2 + 36) = 0;
  }
  SpeedTree::CArray<void *,1>::clear(v2);
  *(_DWORD *)a2 = &SpeedTree::CArray<SpeedTree::CGrassCell *,1>::`vftable';
  if ( *(_BYTE *)(a2 + 16) )
  {
    SpeedTree::CArray<void *,1>::clear(v3);
    if ( *(_BYTE *)(a2 + 16) )
    {
      *(_DWORD *)(a2 + 12) = 0;
      *(_DWORD *)(a2 + 4) = 0;
    }
    *(_BYTE *)(a2 + 16) = 0;
  }
  SpeedTree::CArray<void *,1>::clear(v3);
}
