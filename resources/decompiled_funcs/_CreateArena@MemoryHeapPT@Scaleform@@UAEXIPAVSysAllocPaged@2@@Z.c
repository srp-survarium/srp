void __thiscall Scaleform::MemoryHeapPT::CreateArena(
        Scaleform::MemoryHeapPT *this,
        unsigned int arena,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::HeapRoot::CreateArena(Scaleform::HeapPT::GlobalRoot, arena, sysAlloc);
}
