// attributes: thunk
void __cdecl Scaleform::GFx::System::Init(
        const Scaleform::MemoryHeap::HeapDesc *rootHeapDesc,
        Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(rootHeapDesc, psysAlloc);
}


void __cdecl Scaleform::GFx::System::Init(Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::MemoryHeap::HeapDesc rootHeapDesc; // [esp+0h] [ebp-20h] BYREF

  rootHeapDesc.Flags = 0;
  rootHeapDesc.Limit = 0;
  rootHeapDesc.Arena = 0;
  rootHeapDesc.Granularity = 0x4000;
  rootHeapDesc.Reserve = 0x4000;
  rootHeapDesc.MinAlign = 16;
  rootHeapDesc.Threshold = 0x40000;
  rootHeapDesc.HeapId = 1;
  Scaleform::GFx::System::Init(&rootHeapDesc, psysAlloc);
}
