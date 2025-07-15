void __thiscall Scaleform::HeapPT::AllocEngine::FreeAll(Scaleform::HeapPT::AllocEngine *this)
{
  Scaleform::Heap::HeapSegment *pNext; // eax
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // edi

  pNext = this->SegmentList.Root.pNext;
  for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = this->SegmentList.Root.pNext )
    Scaleform::HeapPT::AllocEngine::freeSegment(this, (unsigned int)pNext);
  Scaleform::HeapPT::FreeBin::Reset(&this->Allocator.Bin);
}
