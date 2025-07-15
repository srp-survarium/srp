void *__thiscall Scaleform::HeapPT::SysAllocWrapper::Alloc(
        Scaleform::HeapPT::SysAllocWrapper *this,
        unsigned int size,
        unsigned int align)
{
  this->UsedSpace += size;
  return this->pSysAlloc->Alloc(this->pSysAlloc, size, align);
}
