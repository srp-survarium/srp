char __thiscall Scaleform::GFx::AMP::BroadcastSocket::Create(
        Scaleform::GFx::AMP::BroadcastSocket *this,
        unsigned int port,
        BOOL broadcast)
{
  Scaleform::GFx::AMP::SocketInterface *SocketImpl; // ecx
  bool v6; // zf
  Scaleform::GFx::AMP::SocketInterface_vtbl *v7; // eax

  if ( !this->SocketImpl->CreateDatagram(this->SocketImpl, broadcast) )
    return 0;
  SocketImpl = this->SocketImpl;
  if ( broadcast )
  {
    SocketImpl->SetBroadcastPort(SocketImpl, port);
    this->SocketImpl->SetBroadcast(this->SocketImpl, 1);
    return 1;
  }
  SocketImpl->SetListenPort(SocketImpl, port);
  v6 = !this->SocketImpl->Bind(this->SocketImpl);
  v7 = this->SocketImpl->__vftable;
  if ( v6 )
  {
    if ( ((unsigned __int8 (*)(void))v7->IsValid)() )
      this->SocketImpl->Shutdown(this->SocketImpl);
    return 0;
  }
  ((void (__stdcall *)(_DWORD))v7->SetBlocking)(0);
  return 1;
}
