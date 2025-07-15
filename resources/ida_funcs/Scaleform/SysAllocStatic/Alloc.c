void *__thiscall Scaleform::SysAllocStatic::Alloc(
        Scaleform::SysAllocStatic *this,
        unsigned int size,
        Scaleform::HeapPT::TreeSeg *alignment)
{
  return Scaleform::HeapPT::AllocLite::Alloc(this->pAllocator, size, (unsigned int)alignment, &alignment);
}
