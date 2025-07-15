void __thiscall Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::SysAllocGranulator *p_Allocator; // edi
  unsigned int Granularity; // eax
  Scaleform::SysAllocPaged::Info i; // [esp+10h] [ebp-18h] BYREF

  this->__vftable = (Scaleform::HeapPT::SysAllocWrapper_vtbl *)&Scaleform::HeapPT::SysAllocWrapper::`vftable';
  this->Allocator.__vftable = (Scaleform::HeapPT::SysAllocGranulator_vtbl *)&Scaleform::HeapPT::SysAllocGranulator::`vftable';
  this->Allocator.pGranulator = 0;
  this->Allocator.SysDirectThreshold = 0;
  this->Allocator.MinAlign = 0;
  this->Allocator.MaxAlign = 0;
  this->Allocator.SysDirectFootprint = 0;
  p_Allocator = &this->Allocator;
  this->pSrcAlloc = sysAlloc;
  this->pSysAlloc = sysAlloc;
  this->SysGranularity = 4096;
  this->MinAlign = 1;
  this->UsedSpace = 0;
  memset(&i, 0, sizeof(i));
  sysAlloc->GetInfo(sysAlloc, &i);
  if ( i.Granularity )
  {
    Scaleform::HeapPT::SysAllocGranulator::Init(p_Allocator, sysAlloc);
    Granularity = i.Granularity;
    this->pSysAlloc = p_Allocator;
    this->SysGranularity = Granularity;
  }
  if ( this->MinAlign < i.MinAlign )
    this->MinAlign = i.MinAlign;
}
