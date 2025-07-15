void __thiscall Scaleform::SysAllocPagedMalloc::GetInfo(
        Scaleform::SysAllocPagedMalloc *this,
        Scaleform::SysAllocPaged::Info *i)
{
  i->MinAlign = 1;
  i->MaxAlign = 1;
  i->Granularity = this->Granularity;
  i->SysDirectThreshold = 0x8000;
  i->MaxHeapGranularity = 0x2000;
  i->HasRealloc = 0;
}
