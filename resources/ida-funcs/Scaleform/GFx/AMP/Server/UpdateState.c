void __thiscall Scaleform::GFx::AMP::Server::UpdateState(
        Scaleform::GFx::AMP::Server *this,
        const Scaleform::GFx::AMP::ServerState *state)
{
  unsigned int *p_CurrentLineNumber; // ebx
  char v4; // bl
  volatile int RefCount; // [esp+10h] [ebp-8h]
  unsigned int *v6; // [esp+14h] [ebp-4h]
  char rhs; // [esp+1Ch] [ebp+4h]

  p_CurrentLineNumber = &this->CurrentState.CurrentLineNumber;
  v6 = &this->CurrentState.CurrentLineNumber;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  if ( Scaleform::GFx::AMP::ServerState::operator!=(
         (Scaleform::GFx::AMP::ServerState *)&this->Scaleform::AmpServer,
         state) )
  {
    RefCount = this->CurrentState.RefCount;
    v4 = ((int)this->CurrentState.__vftable & 0x20) != 0;
    Scaleform::GFx::AMP::ServerState::operator=((Scaleform::GFx::AMP::ServerState *)&this->Scaleform::AmpServer, state);
    EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
    rhs = ((int)this->CurrentState.__vftable & 0x20) != 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
    if ( v4 != rhs && this->FontThrashing.Value )
    {
      if ( v4 )
        this->CurrentState.__vftable = (Scaleform::GFx::AMP::ServerState_vtbl *)((int)this->CurrentState.__vftable | 0x20);
      else
        this->CurrentState.__vftable = (Scaleform::GFx::AMP::ServerState_vtbl *)((int)this->CurrentState.__vftable
                                                                               & ~0x20u);
    }
    if ( ((int (__thiscall *)(Scaleform::GFx::AMP::Server *))this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[20].~Scaleform::GFx::AMP::Server)(this) != RefCount
      && this->FontFailures.Value )
    {
      this->CurrentState.RefCount = RefCount;
    }
    this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[34].~Scaleform::GFx::AMP::Server(this);
    p_CurrentLineNumber = v6;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentLineNumber);
}
