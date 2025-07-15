bool __thiscall Scaleform::SysAlloc::shutdownHeapEngine(Scaleform::SysAlloc *this)
{
  bool v1; // bl

  v1 = Scaleform::MemoryHeap::ReleaseRootHeapMH();
  if ( Scaleform::HeapMH::GlobalRootMH )
  {
    Scaleform::HeapMH::RootMH::~RootMH(Scaleform::HeapMH::GlobalRootMH);
    Scaleform::HeapMH::GlobalRootMH = 0;
  }
  return v1;
}
