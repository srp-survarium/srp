void __thiscall Scaleform::SysAllocMapper::GetInfo(Scaleform::SysAllocMapper *this, Scaleform::SysAllocPaged::Info *i)
{
  i->MinAlign = this->PageSize;
  i->MaxAlign = 0;
  i->Granularity = this->Granularity > 0x1000 ? this->Granularity : 0;
  i->HasRealloc = 1;
}
