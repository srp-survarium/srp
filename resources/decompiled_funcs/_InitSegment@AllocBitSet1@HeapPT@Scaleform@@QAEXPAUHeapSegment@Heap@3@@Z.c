void __thiscall Scaleform::HeapPT::AllocBitSet1::InitSegment(
        Scaleform::HeapPT::AllocBitSet1 *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned int DataSize; // eax
  unsigned int MinAlignShift; // ecx
  unsigned int v5; // eax
  _DWORD *v6; // esi
  Scaleform::HeapPT::BinTNode *pData; // esi
  unsigned int v8; // edi

  DataSize = seg->DataSize;
  MinAlignShift = this->MinAlignShift;
  seg[1].pPrev = (Scaleform::Heap::HeapSegment *)((int)seg[1].pPrev & ~1u);
  v5 = DataSize >> MinAlignShift;
  v6 = &seg[1].pPrev + ((v5 - 1) >> 5);
  *v6 &= ~(1 << ((v5 - 1) & 0x1F));
  pData = (Scaleform::HeapPT::BinTNode *)seg->pData;
  v8 = v5 << this->MinAlignShift;
  if ( v5 >= 0x21 )
  {
    *(_WORD *)((char *)pData + v8 - 2) = 33;
    pData->ShortSize = 33;
    *(_DWORD *)((char *)pData + v8 - 8) = v5;
    pData->Size = v5;
  }
  else
  {
    *(_WORD *)((char *)pData + v8 - 2) = v5;
    pData->ShortSize = v5;
  }
  pData->pSegment = seg;
  Scaleform::HeapPT::FreeBin::Push(&this->Bin, pData);
}
