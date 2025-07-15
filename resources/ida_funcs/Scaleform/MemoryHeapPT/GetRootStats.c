void __thiscall Scaleform::MemoryHeapPT::GetRootStats(
        Scaleform::MemoryHeapPT *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::HeapPT::HeapRoot::GetStats(Scaleform::HeapPT::GlobalRoot, stats);
  stats->UserDebugFootprint = 0;
  stats->UserDebugUsedSpace = 0;
  Scaleform::Memory::pGlobalHeap->getUserDebugStats(Scaleform::Memory::pGlobalHeap, stats);
}
