void __thiscall Scaleform::HeapPT::SysAllocWrapper::GetInfo(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::SysAllocPaged::Info *i)
{
  i->MinAlign = 0;
  i->MaxAlign = 0;
  i->Granularity = 0;
  i->SysDirectThreshold = 0;
  i->MaxHeapGranularity = 0;
  *(_DWORD *)&i->HasRealloc = 0;
  this->pSysAlloc->GetInfo(this->pSysAlloc, i);
}
