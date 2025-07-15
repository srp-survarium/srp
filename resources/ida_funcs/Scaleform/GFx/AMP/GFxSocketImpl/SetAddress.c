void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::SetAddress(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        u_short port,
        const char *address)
{
  *(_DWORD *)&this->SocketAddress.sin_family = 0;
  this->SocketAddress.sin_addr.S_un.S_addr = 0;
  *(_DWORD *)this->SocketAddress.sin_zero = 0;
  *(_DWORD *)&this->SocketAddress.sin_zero[4] = 0;
  this->SocketAddress.sin_family = 2;
  this->SocketAddress.sin_port = htons(port);
  this->SocketAddress.sin_addr.S_un.S_addr = inet_addr(address);
}
