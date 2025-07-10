void __thiscall Scaleform::MemoryHeapPT::FreeSysDirect(Scaleform::MemoryHeapPT *this, void *ptr, unsigned int size)
{
  Scaleform::HeapPT::HeapRoot::FreeSysDirect(Scaleform::HeapPT::GlobalRoot, ptr, size);
}
