void __thiscall Scaleform::HeapPT::Bookkeeper::Bookkeeper(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::SysAllocPaged *sysAlloc,
        unsigned int granularity)
{
  Scaleform::SysAllocPaged *pSysAlloc; // ecx
  unsigned int v5; // ecx
  Scaleform::SysAllocPaged::Info i; // [esp+4h] [ebp-18h] BYREF

  this->pSysAlloc = sysAlloc;
  this->Granularity = granularity;
  this->SegmentList.Root.pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->SegmentList.Root.pNext = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  Scaleform::HeapPT::AllocBitSet2::AllocBitSet2((Scaleform::HeapPT::AllocBitSet2 *)&this->Allocator, 4u);
  pSysAlloc = this->pSysAlloc;
  this->Footprint = 0;
  memset(&i, 0, sizeof(i));
  pSysAlloc->GetInfo(pSysAlloc, &i);
  v5 = i.Granularity;
  if ( i.Granularity < 0x1000 )
    v5 = 4096;
  this->Granularity = v5 * ((this->Granularity + v5 - 1) / v5);
}
