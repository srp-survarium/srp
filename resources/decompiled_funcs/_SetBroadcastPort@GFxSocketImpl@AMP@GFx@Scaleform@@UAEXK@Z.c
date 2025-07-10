void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::SetBroadcastPort(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        u_short port)
{
  *(_DWORD *)&this->SocketAddress.sin_family = 0;
  this->SocketAddress.sin_addr.S_un.S_addr = 0;
  *(_DWORD *)this->SocketAddress.sin_zero = 0;
  *(_DWORD *)&this->SocketAddress.sin_zero[4] = 0;
  this->SocketAddress.sin_family = 2;
  this->SocketAddress.sin_addr.S_un.S_addr = htonl(0xFFFFFFFF);
  this->SocketAddress.sin_port = htons(port);
}
