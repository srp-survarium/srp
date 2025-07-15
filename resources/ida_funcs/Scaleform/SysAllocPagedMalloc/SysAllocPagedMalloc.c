void __thiscall Scaleform::SysAllocPagedMalloc::SysAllocPagedMalloc(
        Scaleform::SysAllocPagedMalloc *this,
        unsigned int granularity)
{
  this->pContainer = 0;
  this->__vftable = (Scaleform::SysAllocPagedMalloc_vtbl *)&Scaleform::SysAllocPagedMalloc::`vftable';
  this->Granularity = (granularity + 0xFFFF) >> 16 << 16;
  this->Footprint = 0;
  this->Base = -1;
}
