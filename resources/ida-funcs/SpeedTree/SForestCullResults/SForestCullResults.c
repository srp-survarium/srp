void __usercall SpeedTree::SForestCullResults::SForestCullResults(
        SpeedTree::SForestCullResults *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = &SpeedTree::SForestCullResults::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = &SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::`vftable';
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_BYTE *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 28) = &SpeedTree::CArray<SpeedTree::CTreeCell *,1>::`vftable';
  *(_DWORD *)(a2 + 48) = &SpeedTree::CArray<SpeedTree::CTreeCell *,1>::`vftable';
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_BYTE *)(a2 + 64) = 0;
  *(_BYTE *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = &SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::`vftable';
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = 0;
  *(_DWORD *)(a2 + 84) = &SpeedTree::CBlockPool<1>::`vftable';
  *(_DWORD *)(a2 + 88) = 0;
  *(_DWORD *)(a2 + 92) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 40;
  SpeedTree::CBlockPool<1>::resize((SpeedTree::CBlockPool<1> *)(a2 + 84), 0xAu);
}
