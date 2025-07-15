void __thiscall Scaleform::System::System(
        Scaleform::System *this,
        const Scaleform::MemoryHeap::HeapDesc *rootHeapDesc,
        Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(rootHeapDesc, psysAlloc);
}


void __thiscall Scaleform::System::System(Scaleform::System *this, Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(psysAlloc);
}
