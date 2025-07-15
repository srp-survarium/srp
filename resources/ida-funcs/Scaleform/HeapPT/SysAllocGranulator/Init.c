void __thiscall Scaleform::HeapPT::SysAllocGranulator::Init(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  unsigned int *PrivateData; // ecx
  Scaleform::HeapPT::Granulator *v4; // eax
  unsigned int MaxHeapGranularity; // ecx
  unsigned int MinAlign; // eax
  unsigned int MaxAlign; // ecx
  Scaleform::SysAllocPaged::Info i; // [esp+4h] [ebp-18h] BYREF

  PrivateData = this->PrivateData;
  if ( PrivateData )
    Scaleform::HeapPT::Granulator::Granulator(
      (Scaleform::HeapPT::Granulator *)PrivateData,
      sysAlloc,
      0x1000u,
      0x1000u,
      0x1000u);
  else
    v4 = 0;
  this->pGranulator = v4;
  memset(&i, 0, sizeof(i));
  v4->pSysAlloc->GetInfo(v4->pSysAlloc, &i);
  MaxHeapGranularity = i.MaxHeapGranularity;
  this->SysDirectThreshold = i.SysDirectThreshold;
  MinAlign = i.MinAlign;
  this->MaxHeapGranularity = MaxHeapGranularity;
  MaxAlign = i.MaxAlign;
  this->MinAlign = MinAlign;
  this->MaxAlign = MaxAlign;
  if ( !MinAlign )
    this->MinAlign = 1;
  if ( !MaxAlign )
    this->MaxAlign = 0x80000000;
}
