unsigned __int8 *__thiscall Scaleform::HeapMH::AllocBitSet2MH::ReallocInPlace(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned __int8 *oldPtr,
        unsigned int newSize,
        unsigned int *oldSize,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  unsigned __int8 *Bound; // eax
  unsigned __int8 *AlignedStart; // ecx
  unsigned __int8 *AlignedEnd; // edx
  unsigned int *BitSet; // ebp
  unsigned int v11; // esi
  unsigned int BlockSize; // ecx
  int v13; // ebx
  int v14; // esi
  unsigned int v15; // eax
  unsigned __int8 *v16; // esi
  unsigned int v17; // ebx
  unsigned int v18; // esi
  unsigned __int8 *v20; // eax
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // ebx
  unsigned __int8 *v24; // esi
  unsigned int v25; // ebx
  unsigned int v26; // esi
  unsigned int start; // [esp+14h] [ebp-8h]
  unsigned __int8 *v29; // [esp+18h] [ebp-4h]
  Scaleform::HeapMH::MagicHeadersInfo *headersa; // [esp+30h] [ebp+14h]
  Scaleform::HeapMH::MagicHeadersInfo *headersb; // [esp+30h] [ebp+14h]

  Scaleform::HeapMH::GetMagicHeaders((unsigned int)page->Start, headers);
  Bound = headers->Bound;
  AlignedStart = headers->AlignedStart;
  AlignedEnd = headers->AlignedEnd;
  headers->Page = page;
  v29 = AlignedStart;
  headersa = (Scaleform::HeapMH::MagicHeadersInfo *)AlignedEnd;
  if ( oldPtr < Bound )
  {
    headersa = (Scaleform::HeapMH::MagicHeadersInfo *)(Bound - 16);
    if ( headers->BitSet < (unsigned int *)Bound )
      headersa = (Scaleform::HeapMH::MagicHeadersInfo *)(Bound - 80);
  }
  BitSet = headers->BitSet;
  v11 = (oldPtr - AlignedStart) >> 4;
  start = v11;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize(BitSet, v11);
  v13 = 16 * BlockSize;
  *oldSize = 16 * BlockSize;
  if ( newSize <= 16 * BlockSize )
  {
    if ( newSize < 16 * BlockSize )
    {
      v20 = &oldPtr[v13];
      v21 = v13 - newSize;
      if ( &oldPtr[v13] >= (unsigned __int8 *)headersa
        || ((BitSet[(BlockSize + v11) >> 4] >> ((2 * (BlockSize + v11)) & 0x1E)) & 3) != 0 )
      {
        v22 = 0;
      }
      else
      {
        v22 = 16 * v20[12];
      }
      v23 = v22 + v21;
      headersb = (Scaleform::HeapMH::MagicHeadersInfo *)(v22 + v21);
      if ( v22 + v21 )
      {
        if ( v22 )
          Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)v20);
        v24 = &oldPtr[newSize];
        v25 = v23 >> 4;
        v24[(_DWORD)headersb - 1] = v25;
        v24[12] = v25;
        *((_DWORD *)v24 + 2) = page;
        Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)&oldPtr[newSize]);
        Scaleform::Heap::BitSet2::MarkBusy(BitSet, start, newSize >> 4);
        v26 = (&oldPtr[newSize] - v29) >> 4;
        BitSet[v26 >> 4] &= ~(3 << ((2 * v26) & 0x1E));
        BitSet[(v25 + v26 - 1) >> 4] &= ~(3 << ((2 * (v25 + v26 - 1)) & 0x1E));
      }
    }
    return oldPtr;
  }
  else
  {
    if ( &oldPtr[v13] >= (unsigned __int8 *)headersa )
      return 0;
    if ( ((BitSet[(BlockSize + v11) >> 4] >> ((2 * (BlockSize + v11)) & 0x1E)) & 3) != 0 )
      return 0;
    v14 = 16 * oldPtr[v13 + 12];
    if ( newSize > v14 + v13 )
    {
      return 0;
    }
    else
    {
      Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)&oldPtr[v13]);
      v15 = v13 + v14 - newSize;
      if ( v15 )
      {
        v16 = &oldPtr[newSize];
        v17 = v15 >> 4;
        v16[v15 - 1] = v15 >> 4;
        v16[12] = v15 >> 4;
        *((_DWORD *)v16 + 2) = page;
        Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)&oldPtr[newSize]);
        v18 = (&oldPtr[newSize] - v29) >> 4;
        BitSet[v18 >> 4] &= ~(3 << ((2 * v18) & 0x1E));
        BitSet[(v17 + v18 - 1) >> 4] &= ~(3 << ((2 * (v17 + v18 - 1)) & 0x1E));
      }
      Scaleform::Heap::BitSet2::MarkBusy(BitSet, start, newSize >> 4);
      return oldPtr;
    }
  }
}
