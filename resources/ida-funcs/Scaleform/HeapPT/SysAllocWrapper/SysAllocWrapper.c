void __thiscall Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::SysAllocGranulator *p_Allocator; // edi
  unsigned int v4; // eax
  _DWORD v5[2]; // [esp+10h] [ebp-18h] BYREF
  unsigned int v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-Ch]
  int v8; // [esp+20h] [ebp-8h]
  int v9; // [esp+24h] [ebp-4h]

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
  v5[0] = 0;
  v5[1] = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  sysAlloc->GetInfo(sysAlloc, (Scaleform::SysAllocPaged::Info *)v5);
  if ( v6 )
  {
    Scaleform::HeapPT::SysAllocGranulator::Init(p_Allocator, sysAlloc);
    v4 = v6;
    this->pSysAlloc = p_Allocator;
    this->SysGranularity = v4;
  }
  if ( this->MinAlign < v5[0] )
    this->MinAlign = v5[0];
}
