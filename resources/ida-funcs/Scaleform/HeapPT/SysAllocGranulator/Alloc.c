void *__thiscall Scaleform::HeapPT::SysAllocGranulator::Alloc(
        Scaleform::HeapPT::SysAllocGranulator *this,
        unsigned int size,
        unsigned int alignment)
{
  return Scaleform::HeapPT::Granulator::Alloc(this->pGranulator, size, alignment);
}
