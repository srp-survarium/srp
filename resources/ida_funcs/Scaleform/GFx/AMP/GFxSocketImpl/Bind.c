bool __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Bind(Scaleform::GFx::AMP::GFxSocketImpl *this)
{
  return bind(this->ListenSocket, (const struct sockaddr *)&this->SocketAddress, 16) != -1;
}
