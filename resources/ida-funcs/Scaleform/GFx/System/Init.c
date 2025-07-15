void __cdecl Scaleform::GFx::System::Init(
        const Scaleform::MemoryHeap::HeapDesc *rootHeapDesc,
        Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(rootHeapDesc, psysAlloc);
  Scaleform::GFx::AMP::Server::Init();
}


void __cdecl Scaleform::GFx::System::Init(Scaleform::SysAllocBase *psysAlloc)
{
  const Scaleform::MemoryHeap::HeapDesc *v1; // eax
  Scaleform::MemoryHeap::RootHeapDesc v2; // [esp+0h] [ebp-20h] BYREF

  Scaleform::MemoryHeap::RootHeapDesc::RootHeapDesc(&v2);
  Scaleform::GFx::System::Init(v1, psysAlloc);
}
