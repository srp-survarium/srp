void __thiscall Scaleform::HeapPT::Granulator::Granulator(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::SysAllocPaged *sysAlloc,
        unsigned int minSize,
        unsigned int granularity,
        unsigned int hdrPageSize)
{
  Scaleform::SysAllocPaged *pSysAlloc; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // [esp+8h] [ebp-18h] BYREF
  unsigned int v12; // [esp+Ch] [ebp-14h]
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]
  BOOL v16; // [esp+1Ch] [ebp-4h]

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
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  pSysAlloc->GetInfo(pSysAlloc, (Scaleform::SysAllocPaged::Info *)&v11);
  v7 = v13;
  if ( v13 < 0x1000 )
    v7 = 4096;
  v8 = v11;
  v9 = v12;
  this->MinAlign = v11;
  this->MaxAlign = v9;
  if ( !v8 )
    this->MinAlign = 1;
  if ( !v9 )
    this->MaxAlign = 0x80000000;
  v10 = this->Granularity;
  this->HasRealloc = v16;
  this->Granularity = v7 * ((v10 + v7 - 1) / v7);
}
