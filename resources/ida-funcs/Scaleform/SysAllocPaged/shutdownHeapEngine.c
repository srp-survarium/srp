char __thiscall Scaleform::SysAllocPaged::shutdownHeapEngine(Scaleform::SysAllocPaged *this)
{
  char v1; // bl

  v1 = Scaleform::MemoryHeap::ReleaseRootHeapPT();
  if ( Scaleform::HeapPT::GlobalPageTable && Scaleform::HeapPT::GlobalRoot )
  {
    Scaleform::HeapPT::HeapRoot::DestroyAllArenas(Scaleform::HeapPT::GlobalRoot);
    Scaleform::HeapPT::GlobalPageTable = 0;
    Scaleform::HeapPT::HeapRoot::~HeapRoot(Scaleform::HeapPT::GlobalRoot);
    Scaleform::HeapPT::GlobalRoot = 0;
  }
  return v1;
}
