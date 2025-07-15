unsigned int __thiscall Scaleform::HeapPT::AllocBitSet2::GetUsableSize(
        Scaleform::HeapPT::AllocBitSet2 *this,
        const Scaleform::Heap::HeapSegment *seg,
        const void *ptr)
{
  unsigned int MinAlignShift; // esi

  MinAlignShift = this->MinAlignShift;
  return Scaleform::Heap::BitSet2::GetBlockSize(
           (const unsigned int *)&seg[1],
           (signed int)((int)ptr - (unsigned int)seg->pData) >> this->MinAlignShift) << MinAlignShift;
}
