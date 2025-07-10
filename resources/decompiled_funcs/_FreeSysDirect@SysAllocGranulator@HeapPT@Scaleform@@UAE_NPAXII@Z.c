int __thiscall Scaleform::HeapPT::SysAllocGranulator::FreeSysDirect(
        Scaleform::HeapPT::SysAllocGranulator *this,
        void *ptr,
        unsigned int size,
        unsigned int alignment)
{
  this->SysDirectFootprint -= size;
  return ((int (__thiscall *)(Scaleform::SysAllocPaged *, void *, unsigned int, unsigned int))this->pGranulator->pSysAlloc->Free)(
           this->pGranulator->pSysAlloc,
           ptr,
           size,
           alignment);
}
