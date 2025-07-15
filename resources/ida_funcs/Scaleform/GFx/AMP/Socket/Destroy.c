void __thiscall Scaleform::GFx::AMP::Socket::Destroy(Scaleform::GFx::AMP::Socket *this)
{
  Scaleform::Lock *CreateLock; // edi

  if ( this->SocketImpl->IsValid(this->SocketImpl) )
  {
    CreateLock = this->CreateLock;
    if ( CreateLock )
      EnterCriticalSection(&this->CreateLock->cs);
    this->SocketImpl->Shutdown(this->SocketImpl);
    if ( CreateLock )
      LeaveCriticalSection(&CreateLock->cs);
  }
  if ( this->SocketImpl->IsListening(this->SocketImpl) )
    this->SocketImpl->ShutdownListener(this->SocketImpl);
}
