void __cdecl Scaleform::System::Init(
        const Scaleform::MemoryHeap::HeapDesc *rootHeapDesc,
        Scaleform::SysAllocBase *psysAlloc)
{
  if ( !System_pSysAlloc )
  {
    Scaleform::Timer::initializeTimerSystem();
    psysAlloc->initHeapEngine(psysAlloc, rootHeapDesc);
    System_pSysAlloc = psysAlloc;
  }
}


void __cdecl Scaleform::System::Init(Scaleform::SysAllocBase *psysAlloc)
{
  const Scaleform::MemoryHeap::HeapDesc *v1; // eax
  Scaleform::MemoryHeap::RootHeapDesc v2; // [esp+0h] [ebp-20h] BYREF

  Scaleform::MemoryHeap::RootHeapDesc::RootHeapDesc(&v2);
  Scaleform::System::Init(v1, psysAlloc);
}
