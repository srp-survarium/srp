void __thiscall Scaleform::HeapPT::Granulator::Granulator(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::SysAllocPaged *sysAlloc,
        unsigned int minSize,
        unsigned int granularity,
        unsigned int hdrPageSize)
{
  Scaleform::SysAllocPaged *pSysAlloc; // ecx
  unsigned int v7; // ecx
  unsigned int MinAlign; // eax
  unsigned int MaxAlign; // edx
  unsigned int v10; // eax
  Scaleform::SysAllocPaged::Info i; // [esp+8h] [ebp-18h] BYREF

  this->pSysAlloc = sysAlloc;
  this->HdrPageSize = hdrPageSize;
  this->HdrCapacity = (hdrPageSize - 32) >> 5;
  this->Granularity = granularity;
  this->MinAlign = 0;
  this->MaxAlign = 0;
  this->HasRealloc = 0;
  this->HdrList.Root.pPrev = (Scaleform::HeapPT::HdrPage *)&this->HdrList;
  this->HdrList.Root.pNext = (Scaleform::HeapPT::HdrPage *)&this->HdrList;
  this->FreeSeg.Root.AddrChild[0] = &this->FreeSeg.Root;
  this->FreeSeg.Root.AddrChild[1] = &this->FreeSeg.Root;
  this->UsedSeg.Root = 0;
  this->Footprint = 0;
  Scaleform::HeapPT::AllocLite::AllocLite(&this->Allocator, minSize);
  pSysAlloc = this->pSysAlloc;
  memset(&i, 0, sizeof(i));
  pSysAlloc->GetInfo(pSysAlloc, &i);
  v7 = i.Granularity;
  if ( i.Granularity < 0x1000 )
    v7 = 4096;
  MinAlign = i.MinAlign;
  MaxAlign = i.MaxAlign;
  this->MinAlign = i.MinAlign;
  this->MaxAlign = MaxAlign;
  if ( !MinAlign )
    this->MinAlign = 1;
  if ( !MaxAlign )
    this->MaxAlign = 0x80000000;
  v10 = this->Granularity;
  this->HasRealloc = i.HasRealloc;
  this->Granularity = v7 * ((v10 + v7 - 1) / v7);
}
