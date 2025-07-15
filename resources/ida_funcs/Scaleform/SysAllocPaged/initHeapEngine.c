BOOL __thiscall Scaleform::SysAllocPaged::initHeapEngine(
        Scaleform::SysAllocPaged *this,
        const Scaleform::MemoryHeap::HeapDesc *heapDesc)
{
  if ( !Scaleform::HeapPT::GlobalPageTable && !Scaleform::HeapPT::GlobalRoot )
  {
    Scaleform::HeapPT::PageTable::Init();
    Scaleform::HeapPT::HeapRoot::HeapRoot(&RootMem, this);
  }
  return Scaleform::MemoryHeap::CreateRootHeapPT(heapDesc) != 0;
}
