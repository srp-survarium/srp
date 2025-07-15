void __thiscall Scaleform::HeapPT::Bookkeeper::freeSegment(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::HeapPT::AllocBitSet1::ReleaseSegment((Scaleform::HeapPT::AllocBitSet2 *)&this->Allocator, seg);
  seg->pPrev->pNext = seg->pNext;
  seg->pNext->Scaleform::ListNode<Scaleform::Heap::HeapSegment>::$10C38F3F495752B04D9D9C52DB001523::pPrev = seg->pPrev;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned int)seg, seg->SelfSize);
  this->Footprint -= seg->SelfSize;
  this->pSysAlloc->Free(this->pSysAlloc, (void *)seg, seg->SelfSize, 4096u);
}
