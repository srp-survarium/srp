Scaleform::HeapPT::BinTNode *__thiscall Scaleform::HeapPT::AllocBitSet2::Alloc(
        Scaleform::HeapPT::AllocBitSet2 *this,
        unsigned int bytes,
        Scaleform::Heap::HeapSegment **allocSeg)
{
  Scaleform::HeapPT::BinTNode *result; // eax
  Scaleform::HeapPT::BinTNode *v6; // esi
  unsigned int MinAlignShift; // ebx
  Scaleform::Heap::HeapSegment *pSegment; // ebp
  unsigned int ShortSize; // ecx
  unsigned int v10; // edx
  char *v11; // eax
  unsigned int v12; // eax
  unsigned int *bitSet; // [esp+Ch] [ebp-10h]
  unsigned __int8 *base; // [esp+10h] [ebp-Ch]
  Scaleform::HeapPT::FreeBin *p_Bin; // [esp+14h] [ebp-8h]
  unsigned int tailBlocks; // [esp+20h] [ebp+4h]

  p_Bin = &this->Bin;
  result = Scaleform::HeapPT::FreeBin::PullBest(&this->Bin, bytes >> this->MinAlignShift);
  v6 = result;
  if ( result )
  {
    MinAlignShift = this->MinAlignShift;
    pSegment = result->pSegment;
    bitSet = (unsigned int *)&pSegment[1];
    ShortSize = result->ShortSize;
    base = pSegment->pData;
    if ( ShortSize >= 0x21 )
      ShortSize = result->Size;
    tailBlocks = ShortSize - (bytes >> MinAlignShift);
    v10 = tailBlocks << MinAlignShift;
    if ( tailBlocks << MinAlignShift < 0x10 )
    {
      Scaleform::Heap::BitSet2::MarkBusy(
        bitSet,
        ((char *)result - (char *)base) >> MinAlignShift,
        (v10 + bytes) >> MinAlignShift,
        0);
    }
    else
    {
      v11 = (char *)result + bytes;
      if ( tailBlocks >= 0x21 )
      {
        *(_WORD *)&v11[v10 - 2] = 33;
        *((_WORD *)v11 + 6) = 33;
        *(_DWORD *)&v11[v10 - 8] = tailBlocks;
        *((_DWORD *)v11 + 4) = tailBlocks;
      }
      else
      {
        *(_WORD *)&v11[v10 - 2] = tailBlocks;
        *((_WORD *)v11 + 6) = tailBlocks;
      }
      *((_DWORD *)v11 + 2) = pSegment;
      Scaleform::HeapPT::FreeBin::Push(p_Bin, (Scaleform::HeapPT::BinTNode *)((char *)v6 + bytes));
      v12 = (int)(bytes + (char *)v6 - (char *)base) >> MinAlignShift;
      bitSet[v12 >> 4] &= ~(3 << ((2 * v12) & 0x1E));
      *((_DWORD *)&pSegment[1].pPrev + ((v12 + tailBlocks - 1) >> 4)) &= ~(3 << ((2 * (v12 + tailBlocks - 1)) & 0x1E));
      Scaleform::Heap::BitSet2::MarkBusy(
        (unsigned int *)&pSegment[1],
        ((char *)v6 - (char *)base) >> MinAlignShift,
        bytes >> MinAlignShift,
        0);
    }
    *allocSeg = pSegment;
    return v6;
  }
  return result;
}
