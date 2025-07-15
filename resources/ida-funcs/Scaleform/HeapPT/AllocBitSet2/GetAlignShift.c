unsigned int __thiscall Scaleform::HeapPT::AllocBitSet2::GetAlignShift(
        Scaleform::HeapPT::AllocBitSet2 *this,
        const Scaleform::Heap::HeapSegment *seg,
        const void *ptr,
        unsigned int size)
{
  unsigned int MinAlignShift; // esi

  MinAlignShift = this->MinAlignShift;
  return MinAlignShift
       + Scaleform::Heap::BitSet2::GetAlignShift(
           (const unsigned int *)&seg[1],
           (signed int)((int)ptr - (unsigned int)seg->pData) >> this->MinAlignShift,
           size >> this->MinAlignShift);
}
