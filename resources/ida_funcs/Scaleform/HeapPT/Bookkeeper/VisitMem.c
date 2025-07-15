void __thiscall Scaleform::HeapPT::Bookkeeper::VisitMem(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::Heap::MemVisitor *visitor,
        char flags)
{
  Scaleform::Heap::HeapSegment *pNext; // esi
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // ebp

  if ( (flags & 4) != 0 )
  {
    pNext = this->SegmentList.Root.pNext;
    for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = pNext->pNext )
      visitor->Visit(visitor, pNext, (unsigned int)pNext->pData, pNext->DataSize, Cat_Bookkeeper);
    if ( (flags & 8) != 0 )
      Scaleform::HeapPT::FreeBin::VisitMem(
        &this->Allocator.Bin,
        visitor,
        this->Allocator.MinAlignShift,
        Cat_BookkeeperFree);
  }
}
