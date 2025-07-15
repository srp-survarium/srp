void __thiscall Scaleform::HeapPT::Bookkeeper::Bookkeeper(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::SysAllocPaged *sysAlloc,
        unsigned int granularity)
{
  Scaleform::SysAllocPaged *pSysAlloc; // ecx
  unsigned int v5; // ecx
  _DWORD v6[2]; // [esp+4h] [ebp-18h] BYREF
  unsigned int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h]

  this->pSysAlloc = sysAlloc;
  this->Granularity = granularity;
  this->SegmentList.Root.pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->SegmentList.Root.pNext = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  Scaleform::HeapPT::AllocBitSet2::AllocBitSet2((Scaleform::HeapPT::AllocBitSet2 *)&this->Allocator, 4u);
  pSysAlloc = this->pSysAlloc;
  this->Footprint = 0;
  v6[0] = 0;
  v6[1] = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  pSysAlloc->GetInfo(pSysAlloc, (Scaleform::SysAllocPaged::Info *)v6);
  v5 = v7;
  if ( v7 < 0x1000 )
    v5 = 4096;
  this->Granularity = v5 * ((this->Granularity + v5 - 1) / v5);
}
