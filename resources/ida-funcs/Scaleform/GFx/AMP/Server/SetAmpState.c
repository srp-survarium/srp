void __thiscall Scaleform::GFx::AMP::Server::SetAmpState(
        Scaleform::GFx::AMP::Server *this,
        unsigned int newState,
        bool sendState)
{
  Scaleform::Lock *p_CurrentStateLock; // edi
  char v5; // bl
  bool v6; // bl
  Scaleform::AmpServer_vtbl *v7; // eax
  Scaleform::AmpServer *v8; // ecx
  bool ProfilingState; // al
  bool v10; // [esp+13h] [ebp-1h]

  p_CurrentStateLock = &this->CurrentStateLock;
  EnterCriticalSection(&this->CurrentStateLock.cs);
  v5 = ((newState >> 1) ^ (this->CurrentState.StateFlags >> 1)) & 1;
  if ( this->MemReportLocked.Value )
  {
    EnterCriticalSection(&p_CurrentStateLock->cs);
    v10 = (this->CurrentState.StateFlags & 0x20) != 0;
    LeaveCriticalSection(&p_CurrentStateLock->cs);
    if ( v10 )
      newState |= 0x20u;
    else
      newState &= ~0x20u;
  }
  this->CurrentState.StateFlags = newState;
  if ( v5 )
  {
    EnterCriticalSection(&p_CurrentStateLock->cs);
    v6 = (this->CurrentState.StateFlags & 2) != 0;
    LeaveCriticalSection(&p_CurrentStateLock->cs);
    v7 = this->Scaleform::AmpServer::__vftable;
    v8 = &this->Scaleform::AmpServer;
    if ( v6 )
      ((void (__fastcall *)(Scaleform::AmpServer *))v7->CloseConnection)(v8);
    else
      ((void (__fastcall *)(Scaleform::AmpServer *))v7->OpenConnection)(v8);
  }
  ProfilingState = Scaleform::GFx::AMP::Server::GetProfilingState(this);
  InterlockedExchange((volatile LONG *)&this->Profiling, ProfilingState);
  if ( sendState )
    this->SendCurrentState(&this->Scaleform::AmpServer);
  LeaveCriticalSection(&p_CurrentStateLock->cs);
}
