bool __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Connect(Scaleform::GFx::AMP::GFxSocketImpl *this)
{
  return connect(this->Socket, (const struct sockaddr *)&this->SocketAddress, 16) != -1;
}
