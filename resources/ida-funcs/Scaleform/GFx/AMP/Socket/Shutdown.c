bool __thiscall Scaleform::GFx::AMP::Socket::Shutdown(Scaleform::GFx::AMP::Socket *this)
{
  Scaleform::Lock *CreateLock; // esi
  bool v3; // bl

  CreateLock = this->CreateLock;
  if ( CreateLock )
    EnterCriticalSection(&this->CreateLock->cs);
  v3 = this->SocketImpl->Shutdown(this->SocketImpl);
  if ( CreateLock )
    LeaveCriticalSection(&CreateLock->cs);
  return v3;
}
