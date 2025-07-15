void *__thiscall Scaleform::HeapPT::SysAllocWrapper::AllocSysDirect(
        Scaleform::HeapPT::SysAllocWrapper *this,
        unsigned int size,
        unsigned int alignment,
        unsigned int *actualSize,
        unsigned int *actualAlign)
{
  this->UsedSpace += size;
  return this->pSysAlloc->AllocSysDirect(this->pSysAlloc, size, alignment, actualSize, actualAlign);
}
