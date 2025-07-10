bool __thiscall Scaleform::HeapPT::SysAllocGranulator::ReallocInPlace(
        Scaleform::HeapPT::SysAllocGranulator *this,
        void *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int alignment)
{
  return Scaleform::HeapPT::Granulator::ReallocInPlace(this->pGranulator, oldPtr, oldSize, newSize, alignment);
}
