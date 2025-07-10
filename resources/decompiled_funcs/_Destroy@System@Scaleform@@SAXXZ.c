void __cdecl Scaleform::System::Destroy()
{
  if ( System_pSysAlloc )
  {
    Scaleform::Thread::FinishAllThreads();
    Scaleform::System::HasMemoryLeaks = !System_pSysAlloc->shutdownHeapEngine(System_pSysAlloc);
    System_pSysAlloc = 0;
    Scaleform::Timer::shutdownTimerSystem();
  }
}
