unsigned int __thiscall Scaleform::HeapPT::AllocEngine::GetUsableSize(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        const void *ptr)
{
  unsigned __int16 SegType; // ax

  SegType = seg->SegType;
  if ( SegType <= 7u )
    return (SegType + 1) << this->MinAlignShift;
  if ( SegType == 10 )
    return Scaleform::HeapPT::AllocBitSet2::GetUsableSize(&this->Allocator, seg, ptr);
  return seg->DataSize;
}
