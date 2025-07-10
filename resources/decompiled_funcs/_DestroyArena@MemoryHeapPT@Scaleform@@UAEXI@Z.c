void __thiscall Scaleform::MemoryHeapPT::DestroyArena(Scaleform::MemoryHeapPT *this, unsigned int arena)
{
  Scaleform::HeapPT::HeapRoot::DestroyArena(Scaleform::HeapPT::GlobalRoot, arena);
}
