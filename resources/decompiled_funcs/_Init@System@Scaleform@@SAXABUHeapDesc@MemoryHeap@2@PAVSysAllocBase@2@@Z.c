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
