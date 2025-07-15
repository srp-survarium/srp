char __thiscall Scaleform::GFx::AMP::Server::OpenConnection(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::GFx::AMP::Server *v2; // edi
  unsigned int *p_CurrentLineNumber; // ebp
  bool v4; // bl
  char result; // al
  bool ProfilingState; // al

  v2 = (Scaleform::GFx::AMP::Server *)((char *)this - 8);
  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
  v4 = (v2->CurrentState.StateFlags & 2) != 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
  if ( !v4 )
  {
    result = Scaleform::GFx::AMP::ThreadMgr::InitAmp(
               (Scaleform::GFx::AMP::ThreadMgr *)this->Port,
               0,
               (unsigned int)this->ToggleStateLock.cs.LockSemaphore,
               this->ToggleStateLock.cs.SpinCount,
               0);
    if ( !result )
      return result;
    ProfilingState = Scaleform::GFx::AMP::Server::GetProfilingState(v2);
    InterlockedExchange((volatile LONG *)&v2->Profiling, ProfilingState);
    Scaleform::Event::Wait(
      (Scaleform::Event *)&this->SourceFileLock.cs.LockSemaphore,
      (DWORD)this->SendingEvent.StateMutex.pImpl);
  }
  return 1;
}
