void __thiscall Scaleform::HeapMH::AllocBitSet2MH::Free(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned __int8 *ptr,
        Scaleform::HeapMH::MagicHeadersInfo *headers,
        unsigned int *oldSize)
{
  unsigned int *BitSet; // ecx
  unsigned int v6; // esi
  unsigned int BlockSize; // eax
  unsigned int v8; // edx
  unsigned int *v9; // ebx
  unsigned int v10; // ebp
  unsigned int *v11; // ebx
  unsigned __int8 *v12; // eax
  bool v13; // cl
  unsigned int v14; // edx
  bool left; // [esp+14h] [ebp+10h]

  Scaleform::HeapMH::GetMagicHeaders((unsigned int)page->Start, headers);
  BitSet = headers->BitSet;
  headers->Page = page;
  v6 = (ptr - headers->AlignedStart) >> 4;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize(BitSet, v6);
  v8 = 16 * BlockSize;
  *oldSize = 16 * BlockSize;
  v9 = headers->BitSet;
  v9[v6 >> 4] &= ~(3 << ((2 * v6) & 0x1E));
  v10 = BlockSize + v6;
  v11 = &v9[(BlockSize + v6 - 1) >> 4];
  *v11 &= ~(3 << ((2 * (BlockSize + v6 - 1)) & 0x1E));
  v12 = &ptr[16 * BlockSize];
  if ( !v6 || (left = 1, ((headers->BitSet[(v6 - 1) >> 4] >> ((2 * (v6 - 1)) & 0x1E)) & 3) != 0) )
    left = 0;
  v13 = v12 < headers->AlignedEnd && ((headers->BitSet[v10 >> 4] >> ((2 * v10) & 0x1E)) & 3) == 0;
  if ( left || v13 )
  {
    Scaleform::HeapMH::ListBinMH::Merge(&this->Bin, ptr, v8, left, v13, page);
  }
  else
  {
    v14 = v8 >> 4;
    *(v12 - 1) = v14;
    ptr[12] = v14;
    *((_DWORD *)ptr + 2) = page;
    Scaleform::HeapMH::ListBinMH::Push(&this->Bin, ptr);
  }
}
