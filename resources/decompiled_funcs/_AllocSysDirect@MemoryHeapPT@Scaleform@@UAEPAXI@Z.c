void *__thiscall Scaleform::MemoryHeapPT::AllocSysDirect(Scaleform::MemoryHeapPT *this, unsigned int size)
{
  return Scaleform::HeapPT::HeapRoot::AllocSysDirect(Scaleform::HeapPT::GlobalRoot, size);
}
