void __thiscall __noreturn Scaleform::Thread::Exit(Scaleform::Thread *this, DWORD exitCode)
{
  this->OnExit(this);
  Scaleform::Thread::FinishAndRelease(this);
  Scaleform::ThreadList::RemoveRunningThread(this);
  _endthreadex(exitCode);
}
