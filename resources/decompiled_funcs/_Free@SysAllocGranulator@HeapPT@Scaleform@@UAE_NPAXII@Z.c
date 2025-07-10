bool __thiscall Scaleform::HeapPT::SysAllocGranulator::Free(
        Scaleform::HeapPT::SysAllocGranulator *this,
        void *ptr,
        unsigned int size,
        unsigned int alignment)
{
  return Scaleform::HeapPT::Granulator::Free(this->pGranulator, ptr, size, alignment);
}
