Scaleform::SysAllocMalloc *__thiscall survarium::scaleform_engine::xrSysAllocMalloc::`scalar deleting destructor'(
        Scaleform::SysAllocMalloc *this,
        char a2)
{
  this->__vftable = (Scaleform::SysAllocMalloc_vtbl *)&Scaleform::SysAllocBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
