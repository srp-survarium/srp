char __thiscall Scaleform::Thread::Start(Scaleform::Thread *this, Scaleform::Thread::ThreadState initialState)
{
  HANDLE v4; // eax

  if ( initialState == NotRunning )
    return 0;
  if ( (this->SuspendCount.Value > 0 || (this->ThreadFlags.Value & 1) != 0)
    && !Scaleform::Waitable::Wait(this, 0xFFFFFFFF) )
  {
    return 0;
  }
  if ( this->ThreadHandle )
  {
    CloseHandle(this->ThreadHandle);
    this->ThreadHandle = 0;
  }
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this);
  Scaleform::ThreadList::AddRunningThread(this);
  this->ExitCode = 0;
  InterlockedExchange(&this->SuspendCount.Value, 0);
  InterlockedExchange((volatile LONG *)&this->ThreadFlags, initialState != Running ? 8 : 0);
  v4 = _beginthreadex(
         (unsigned int)this,
         0,
         this->StackSize,
         (unsigned int (__stdcall *)(void *))Scaleform::Thread_Win32StartFn,
         this,
         0,
         (unsigned int *)&this->IdValue);
  this->ThreadHandle = v4;
  if ( !v4 )
  {
    InterlockedExchange((volatile LONG *)&this->ThreadFlags, 0);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this);
    Scaleform::ThreadList::RemoveRunningThread(this);
    return 0;
  }
  return 1;
}
