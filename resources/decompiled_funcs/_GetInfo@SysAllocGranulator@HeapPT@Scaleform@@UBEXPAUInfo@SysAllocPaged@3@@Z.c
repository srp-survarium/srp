void __thiscall Scaleform::HeapPT::SysAllocGranulator::GetInfo(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::SysAllocPaged::Info *i)
{
  i->MinAlign = 0;
  i->MaxAlign = 0;
  i->Granularity = 0;
  i->SysDirectThreshold = this->SysDirectThreshold;
  i->MaxHeapGranularity = this->MaxHeapGranularity;
  i->HasRealloc = 1;
}
