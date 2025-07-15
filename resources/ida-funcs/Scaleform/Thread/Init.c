void __thiscall Scaleform::Thread::Init(Scaleform::Thread *this, const Scaleform::Thread::CreateParams *params)
{
  Scaleform::Thread::ThreadState initialState; // eax

  InterlockedExchange((volatile LONG *)&this->ThreadFlags, 0);
  this->ThreadHandle = 0;
  this->IdValue = 0;
  this->ExitCode = 0;
  InterlockedExchange(&this->SuspendCount.Value, 0);
  this->StackSize = params->stackSize;
  this->Processor = params->processor;
  this->Priority = params->priority;
  this->ThreadFunction = params->threadFunction;
  this->UserHandle = params->userHandle;
  initialState = params->initialState;
  if ( initialState )
    this->Start(this, initialState);
}
