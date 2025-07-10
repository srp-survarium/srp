void __thiscall Scaleform::SysAllocStatic::GetInfo(Scaleform::SysAllocStatic *this, Scaleform::SysAllocPaged::Info *i)
{
  i->MinAlign = this->pAllocator->MinSize;
  i->MaxAlign = 0;
  i->Granularity = 0;
  i->HasRealloc = 1;
}
