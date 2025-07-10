void __thiscall Scaleform::HeapPT::AllocEngine::VisitSegments(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::HeapSegment *pNext; // esi
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // ebx

  pNext = this->SegmentList.Root.pNext;
  for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = pNext->pNext )
    visitor->Visit(visitor, 5u, pNext->pHeap, (unsigned int)pNext->pData, (pNext->DataSize + 4095) & 0xFFFFF000);
  Scaleform::HeapPT::FreeBin::VisitUnused(&this->Allocator.Bin, visitor, this->Allocator.MinAlignShift, 0x85u);
}
