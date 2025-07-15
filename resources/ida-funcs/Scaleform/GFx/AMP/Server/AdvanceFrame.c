void __thiscall Scaleform::GFx::AMP::Server::AdvanceFrame(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::GFx::AMP::Server *v2; // edi
  bool ProfilingState; // al
  unsigned int LockSemaphore; // ebx
  unsigned int ForceState; // eax

  v2 = (Scaleform::GFx::AMP::Server *)((char *)this - 8);
  ProfilingState = Scaleform::GFx::AMP::Server::GetProfilingState((Scaleform::GFx::AMP::Server *)((char *)this - 8));
  InterlockedExchange((volatile LONG *)&v2->Profiling, ProfilingState);
  Scaleform::Event::Wait((Scaleform::Event *)&this->ConnectedEvent.StateMutex.pImpl, 0x3E8u);
  if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AMP::Server *))this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[16].~Scaleform::GFx::AMP::Server)(this) )
  {
    Scaleform::GFx::AMP::Server::SendFrameStats(v2);
  }
  else
  {
    Scaleform::GFx::AMP::Server::CollectMovieData(v2, 0);
    Scaleform::GFx::AMP::Server::ClearRendererData(v2);
    Scaleform::GFx::AMP::Server::CollectTaskData(v2, 0);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&this->PendingForceState);
  LockSemaphore = (unsigned int)this->CurrentStateLock.cs.LockSemaphore;
  if ( LockSemaphore )
  {
    EnterCriticalSection(&v2->CurrentStateLock.cs);
    Scaleform::GFx::AMP::Server::SetAmpState(v2, LockSemaphore ^ v2->CurrentState.StateFlags, 1);
    LeaveCriticalSection(&v2->CurrentStateLock.cs);
    this->CurrentStateLock.cs.LockSemaphore = 0;
  }
  if ( LOBYTE(this->ToggleState) )
  {
    Scaleform::GFx::AMP::Server::SetAmpState(v2, this->CurrentStateLock.cs.SpinCount, 1);
    LOBYTE(this->ToggleState) = 0;
  }
  ForceState = this->ForceState;
  if ( ForceState != -1 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AMP::Server *, unsigned int, _DWORD))this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[21].~Scaleform::GFx::AMP::Server)(
      this,
      ForceState,
      0);
    this->ForceState = -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->PendingForceState);
  this->GpaDomain = 0;
}
