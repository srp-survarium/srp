void __thiscall Scaleform::GFx::AMP::BroadcastSocket::~BroadcastSocket(Scaleform::GFx::AMP::BroadcastSocket *this)
{
  if ( this->SocketImpl->IsValid(this->SocketImpl) )
    this->SocketImpl->Shutdown(this->SocketImpl);
  if ( this->InitLib )
    this->SocketImpl->Cleanup(this->SocketImpl);
  this->SocketFactory->Destroy(this->SocketFactory, this->SocketImpl);
}
