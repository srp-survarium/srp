int __stdcall Scaleform::Thread_Win32StartFn(Scaleform::Thread *phandle)
{
  HANDLE CurrentThread; // eax
  HANDLE v2; // eax
  int v3; // edi
  DWORD_PTR Processor; // [esp-4h] [ebp-Ch]
  int OSPriority; // [esp-4h] [ebp-Ch]

  if ( phandle->Processor != -1 )
  {
    Processor = phandle->Processor;
    CurrentThread = GetCurrentThread();
    SetThreadAffinityMask(CurrentThread, Processor);
  }
  OSPriority = Scaleform::Thread::GetOSPriority(phandle->Priority);
  v2 = GetCurrentThread();
  SetThreadPriority(v2, OSPriority);
  phandle->IdValue = (void *volatile)GetCurrentThreadId();
  if ( (phandle->ThreadFlags.Value & 8) != 0 )
  {
    if ( (phandle->ThreadFlags.Value & 1) != 0 && SuspendThread(phandle->ThreadHandle) != -1 )
      InterlockedExchangeAdd(&phandle->SuspendCount.Value, 1);
    Scaleform::AtomicInt<unsigned long>::operator&=(&phandle->ThreadFlags, 0xFFFFFFF7);
  }
  v3 = phandle->Run(phandle);
  phandle->ExitCode = v3;
  Scaleform::Thread::FinishAndRelease(phandle);
  Scaleform::ThreadList::RemoveRunningThread(phandle);
  return v3;
}
