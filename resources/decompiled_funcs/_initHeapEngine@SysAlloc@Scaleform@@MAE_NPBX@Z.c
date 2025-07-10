BOOL __thiscall Scaleform::SysAlloc::initHeapEngine(
        Scaleform::SysAlloc *this,
        const Scaleform::MemoryHeap::HeapDesc *heapDesc)
{
  if ( !Scaleform::HeapMH::GlobalRootMH )
    Scaleform::HeapMH::RootMH::RootMH(&HeapRootMemMH, this);
  return Scaleform::MemoryHeap::CreateRootHeapMH(heapDesc) != 0;
}
