Scaleform::HeapPT::DualTNode *__thiscall Scaleform::SysAllocStatic::Alloc(
        Scaleform::SysAllocStatic *this,
        unsigned int size,
        unsigned int alignment)
{
  return Scaleform::HeapPT::AllocLite::Alloc(
           this->pAllocator,
           size,
           alignment,
           (Scaleform::HeapPT::TreeSeg **)&alignment);
}
