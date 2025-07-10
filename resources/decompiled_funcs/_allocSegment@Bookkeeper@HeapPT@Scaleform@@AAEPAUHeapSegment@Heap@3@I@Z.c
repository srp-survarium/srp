Scaleform::Heap::HeapSegment *__thiscall Scaleform::HeapPT::Bookkeeper::allocSegment(
        Scaleform::HeapPT::Bookkeeper *this,
        unsigned int dataSize)
{
  Scaleform::Heap::HeapSegment *v3; // esi
  unsigned int v5; // eax

  v3 = (Scaleform::Heap::HeapSegment *)this->pSysAlloc->Alloc(this->pSysAlloc, dataSize, 4096);
  if ( !v3 )
    return 0;
  v3->SelfSize = dataSize;
  v3->SegType = 8;
  v3->Alignment = 12;
  v3->UseCount = 0;
  v3->pHeap = 0;
  v3->DataSize = 0;
  v3->pData = 0;
  if ( !Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned int)v3, dataSize) )
  {
    this->pSysAlloc->Free(this->pSysAlloc, (void *)v3, dataSize, 4096u);
    return 0;
  }
  Scaleform::HeapPT::PageTable::SetSegmentInRange(Scaleform::HeapPT::GlobalPageTable, (unsigned int)v3, dataSize, v3);
  v5 = (4 * ((((dataSize + this->Allocator.MinAlignMask) >> this->Allocator.MinAlignShift) + 31) >> 5) + 47)
     & 0xFFFFFFF0;
  v3->pData = (unsigned __int8 *)v3 + v5;
  v3->DataSize = dataSize - v5;
  v3->pNext = this->SegmentList.Root.pNext;
  v3->pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->SegmentList.Root.pNext->pPrev = v3;
  this->SegmentList.Root.pNext = v3;
  Scaleform::HeapPT::AllocBitSet1::InitSegment(&this->Allocator, v3);
  this->Footprint += v3->SelfSize;
  return v3;
}
