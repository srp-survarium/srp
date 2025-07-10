void __thiscall Scaleform::GFx::AMP::Socket::SetBlocking(Scaleform::GFx::AMP::Socket *this, BOOL blocking)
{
  this->SocketImpl->SetBlocking(this->SocketImpl, blocking);
}
