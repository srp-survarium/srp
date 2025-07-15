char __thiscall Scaleform::GFx::AMP::Socket::Accept(Scaleform::GFx::AMP::Socket *this, int timeout)
{
  if ( !this->IsServer )
    return 1;
  this->SocketImpl->SetBlocking(this->SocketImpl, 1);
  if ( this->SocketImpl->Accept(this->SocketImpl, timeout) )
    return 1;
  if ( this->SocketImpl->IsValid(this->SocketImpl) )
    Scaleform::GFx::AMP::Socket::Shutdown(this);
  return 0;
}
