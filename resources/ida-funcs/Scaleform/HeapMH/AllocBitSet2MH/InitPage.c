void __thiscall Scaleform::HeapMH::AllocBitSet2MH::InitPage(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned int index)
{
  Scaleform::HeapMH::AllocBitSet2MH *v3; // ebp
  Scaleform::HeapMH::MagicHeader *Header1; // eax
  unsigned __int8 *AlignedStart; // esi
  Scaleform::HeapMH::MagicHeader *Header2; // edx
  Scaleform::HeapMH::MagicHeader *v7; // ebx
  Scaleform::HeapMH::MagicHeader *v8; // edi
  int v9; // ebx
  unsigned int v10; // esi
  unsigned int *BitSet; // edx
  unsigned int *v12; // edx
  int v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // edi
  unsigned int *v16; // edx
  unsigned int *v17; // edx
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+14h] [ebp-1Ch] BYREF
  unsigned __int8 *AlignedEnd; // [esp+38h] [ebp+8h]

  v3 = this;
  Scaleform::HeapMH::GetMagicHeaders((unsigned int)page->Start, &headers);
  memset((int)headers.BitSet, 85, 64);
  Header1 = headers.Header1;
  AlignedStart = 0;
  if ( headers.Header1 )
  {
    headers.Header1->Magic = 24512;
    headers.Header1->UseCount = 0;
    headers.Header1->Index = index;
    headers.Header1->DebugHeader = 0;
    Header1 = headers.Header1;
  }
  Header2 = headers.Header2;
  if ( headers.Header2 )
  {
    headers.Header2->Magic = 24512;
    headers.Header2->UseCount = 0;
    headers.Header2->Index = index;
    headers.Header2->DebugHeader = 0;
    Header2 = headers.Header2;
    Header1 = headers.Header1;
  }
  v7 = 0;
  v8 = 0;
  AlignedEnd = 0;
  if ( Header1 )
  {
    AlignedStart = headers.AlignedStart;
    v7 = Header1;
  }
  if ( Header2 )
  {
    v8 = Header2 + 1;
    AlignedEnd = headers.AlignedEnd;
  }
  if ( headers.BitSet >= (unsigned int *)headers.Bound )
    v8 += 4;
  else
    v7 -= 4;
  if ( AlignedStart )
  {
    v9 = (char *)v7 - (char *)AlignedStart;
    AlignedStart[v9 - 1] = (unsigned int)v9 >> 4;
    AlignedStart[12] = (unsigned int)v9 >> 4;
    *((_DWORD *)AlignedStart + 2) = page;
    Scaleform::HeapMH::ListBinMH::Push(&v3->Bin, (Scaleform::HeapMH::BinNodeMH *)AlignedStart);
    v10 = (AlignedStart - headers.AlignedStart) >> 4;
    BitSet = headers.BitSet;
    v9 >>= 4;
    headers.BitSet[v10 >> 4] &= ~(3 << ((2 * v10) & 0x1E));
    v3 = this;
    v12 = &BitSet[(v9 + v10 - 1) >> 4];
    *v12 &= ~(3 << ((2 * (v9 + v10 - 1)) & 0x1E));
  }
  if ( v8 )
  {
    v13 = AlignedEnd - (unsigned __int8 *)v8;
    v14 = (unsigned int)(AlignedEnd - (unsigned __int8 *)v8) >> 4;
    *(AlignedEnd - 1) = v14;
    LOBYTE(v8->Filler) = v14;
    v8->DebugHeader = (struct Scaleform::HeapMH::DebugDataMH *)page;
    Scaleform::HeapMH::ListBinMH::Push(&v3->Bin, (Scaleform::HeapMH::BinNodeMH *)v8);
    v15 = ((char *)v8 - (char *)headers.AlignedStart) >> 4;
    v16 = headers.BitSet;
    v13 >>= 4;
    headers.BitSet[v15 >> 4] &= ~(3 << ((2 * v15) & 0x1E));
    v17 = &v16[(v13 + v15 - 1) >> 4];
    *v17 &= ~(3 << ((2 * (v13 + v15 - 1)) & 0x1E));
  }
}
