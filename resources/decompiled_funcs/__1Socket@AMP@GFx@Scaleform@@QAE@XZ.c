void __thiscall Scaleform::GFx::AMP::Socket::~Socket(Scaleform::GFx::AMP::Socket *this)
{
  Scaleform::Lock *CreateLock; // edi

  Scaleform::GFx::AMP::Socket::Destroy(this);
  if ( this->InitLib )
  {
    CreateLock = this->CreateLock;
    if ( CreateLock )
      EnterCriticalSection(&this->CreateLock->cs);
    this->SocketImpl->Cleanup(this->SocketImpl);
    if ( CreateLock )
      LeaveCriticalSection(&CreateLock->cs);
  }
  this->SocketFactory->Destroy(this->SocketFactory, this->SocketImpl);
}
