int __thiscall Scaleform::HeapPT::SysAllocWrapper::ReallocInPlace(
        Scaleform::HeapPT::SysAllocWrapper *this,
        void *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int align)
{
  this->UsedSpace += newSize - oldSize;
  return ((int (__thiscall *)(Scaleform::SysAllocPaged *, void *, unsigned int, unsigned int, unsigned int))this->pSysAlloc->ReallocInPlace)(
           this->pSysAlloc,
           oldPtr,
           oldSize,
           newSize,
           align);
}
