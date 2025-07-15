void __thiscall Scaleform::GFx::AMP::Server::SetProfileLevel(
        Scaleform::GFx::AMP::Server *this,
        volatile int profileLevel,
        bool lock)
{
  Scaleform::AtomicInt<unsigned long> *p_FontFailures; // esi
  bool v5; // bl

  p_FontFailures = &this->FontFailures;
  if ( !this->FontFailures.Value || lock )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
    this->CurrentState.RefCount = profileLevel;
    if ( lock )
      InterlockedExchange((volatile LONG *)p_FontFailures, 1);
    EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
    v5 = ((int)this->CurrentState.__vftable & 0x40) != 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
    if ( profileLevel >= 2 != v5 )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
      Scaleform::GFx::AMP::Server::SetAmpState(
        (Scaleform::GFx::AMP::Server *)((char *)this - 8),
        (int)this->CurrentState.__vftable ^ 0x40,
        0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->CurrentState.CurrentLineNumber);
  }
  this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[34].~Scaleform::GFx::AMP::Server(this);
}
