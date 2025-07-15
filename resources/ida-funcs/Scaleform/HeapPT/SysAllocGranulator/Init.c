void __thiscall Scaleform::HeapPT::SysAllocGranulator::Init(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  unsigned int *PrivateData; // ecx
  Scaleform::HeapPT::Granulator *v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // [esp+4h] [ebp-18h] BYREF
  unsigned int v9; // [esp+8h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-10h]
  unsigned int v11; // [esp+10h] [ebp-Ch]
  unsigned int v12; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

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
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v4->pSysAlloc->GetInfo(v4->pSysAlloc, (Scaleform::SysAllocPaged::Info *)&v8);
  v5 = v12;
  this->SysDirectThreshold = v11;
  v6 = v8;
  this->MaxHeapGranularity = v5;
  v7 = v9;
  this->MinAlign = v6;
  this->MaxAlign = v7;
  if ( !v6 )
    this->MinAlign = 1;
  if ( !v7 )
    this->MaxAlign = 0x80000000;
}
