int __thiscall Scaleform::HeapPT::SysAllocWrapper::Free(
        Scaleform::HeapPT::SysAllocWrapper *this,
        void *ptr,
        unsigned int size,
        unsigned int align)
{
  this->UsedSpace -= size;
  return ((int (__thiscall *)(Scaleform::SysAllocPaged *, void *, unsigned int, unsigned int))this->pSysAlloc->Free)(
           this->pSysAlloc,
           ptr,
           size,
           align);
}
