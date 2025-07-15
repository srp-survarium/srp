bool __thiscall Scaleform::MemoryHeapPT::ArenaIsEmpty(Scaleform::MemoryHeapPT *this, unsigned int arena)
{
  return Scaleform::HeapPT::HeapRoot::ArenaIsEmpty(Scaleform::HeapPT::GlobalRoot, arena);
}
