void __thiscall Scaleform::HeapPT::Bookkeeper::VisitSegments(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::HeapSegment *pNext; // esi
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // ebx

  pNext = this->SegmentList.Root.pNext;
  for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = pNext->pNext )
    visitor->Visit(visitor, 3u, 0, (unsigned int)pNext, pNext->SelfSize);
  Scaleform::HeapPT::FreeBin::VisitUnused(&this->Allocator.Bin, visitor, this->Allocator.MinAlignShift, 0x83u);
}
