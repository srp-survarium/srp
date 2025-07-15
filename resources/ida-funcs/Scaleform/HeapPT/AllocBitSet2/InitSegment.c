void __thiscall Scaleform::HeapPT::AllocBitSet2::InitSegment(
        Scaleform::HeapPT::AllocBitSet2 *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned int DataSize; // eax
  unsigned int MinAlignShift; // ecx
  Scaleform::HeapPT::BinTNode *pData; // edi
  unsigned int v6; // eax
  unsigned int v7; // esi

  DataSize = seg->DataSize;
  MinAlignShift = this->MinAlignShift;
  seg[1].pPrev = (Scaleform::Heap::HeapSegment *)((int)seg[1].pPrev & 0xFFFFFFFC);
  *((_DWORD *)&seg[1].pPrev + (((DataSize >> MinAlignShift) - 1) >> 4)) &= ~(3 << ((2 * ((DataSize >> MinAlignShift) - 1))
                                                                                 & 0x1E));
  pData = (Scaleform::HeapPT::BinTNode *)seg->pData;
  v6 = seg->DataSize >> this->MinAlignShift;
  v7 = v6 << this->MinAlignShift;
  if ( v6 >= 0x21 )
  {
    *(_WORD *)((char *)pData + v7 - 2) = 33;
    pData->ShortSize = 33;
    *(_DWORD *)((char *)pData + v7 - 8) = v6;
    pData->Size = v6;
  }
  else
  {
    *(_WORD *)((char *)pData + v7 - 2) = v6;
    pData->ShortSize = v6;
  }
  pData->pSegment = seg;
  Scaleform::HeapPT::FreeBin::Push(&this->Bin, pData);
}
