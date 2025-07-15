int __thiscall Scaleform::HeapPT::SysAllocWrapper::FreeSysDirect(
        Scaleform::HeapPT::SysAllocWrapper *this,
        void *ptr,
        unsigned int size,
        unsigned int alignment)
{
  this->UsedSpace -= size;
  return ((int (__thiscall *)(Scaleform::SysAllocPaged *, void *, unsigned int, unsigned int))this->pSysAlloc->FreeSysDirect)(
           this->pSysAlloc,
           ptr,
           size,
           alignment);
}
