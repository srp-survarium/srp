void __thiscall Scaleform::HeapPT::AllocBitSet2::Free(
        Scaleform::HeapPT::AllocBitSet2 *this,
        Scaleform::Heap::HeapSegment *seg,
        char *ptr)
{
  unsigned __int8 *pData; // eax
  unsigned int MinAlignShift; // ecx
  unsigned int v5; // esi
  Scaleform::Heap::HeapSegment *v6; // edi
  unsigned __int8 *v7; // ebx
  unsigned int BlockSize; // eax
  _DWORD *v9; // ecx
  unsigned int v10; // edx
  bool v11; // cl
  bool left; // [esp+10h] [ebp-10h]
  char shift; // [esp+14h] [ebp-Ch]

  pData = seg->pData;
  MinAlignShift = this->MinAlignShift;
  v5 = (ptr - (char *)pData) >> MinAlignShift;
  v6 = seg + 1;
  v7 = &pData[seg->DataSize];
  shift = MinAlignShift;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize((const unsigned int *)&seg[1], v5);
  *((_DWORD *)&seg[1].pPrev + (v5 >> 4)) &= ~(3 << ((2 * v5) & 0x1E));
  v9 = &seg[1].pPrev + ((BlockSize + v5 - 1) >> 4);
  *v9 &= ~(3 << ((2 * (BlockSize + v5 - 1)) & 0x1E));
  v10 = BlockSize << shift;
  if ( !v5 || (left = 1, ((*((_DWORD *)&v6->pPrev + ((v5 - 1) >> 4)) >> ((2 * (v5 - 1)) & 0x1E)) & 3) != 0) )
    left = 0;
  v11 = &ptr[BlockSize << shift] < (char *)v7
     && ((*((_DWORD *)&v6->pPrev + ((BlockSize + v5) >> 4)) >> ((2 * (BlockSize + v5)) & 0x1E)) & 3) == 0;
  if ( BlockSize >= 0x21 )
  {
    *(_WORD *)&ptr[v10 - 2] = 33;
    *((_WORD *)ptr + 6) = 33;
    *(_DWORD *)&ptr[v10 - 8] = BlockSize;
    *((_DWORD *)ptr + 4) = BlockSize;
  }
  else
  {
    *(_WORD *)&ptr[v10 - 2] = BlockSize;
    *((_WORD *)ptr + 6) = BlockSize;
  }
  *((_DWORD *)ptr + 2) = seg;
  if ( left || v11 )
    Scaleform::HeapPT::FreeBin::Merge(&this->Bin, (Scaleform::HeapPT::BinTNode *)ptr, shift, left, v11);
  else
    Scaleform::HeapPT::FreeBin::Push(&this->Bin, (Scaleform::HeapPT::BinTNode *)ptr);
}
