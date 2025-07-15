char __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Accept(Scaleform::GFx::AMP::GFxSocketImpl *this, int timeout)
{
  SOCKET v3; // eax
  SOCKET ListenSocket; // [esp-Ch] [ebp-120h]
  int addrlen; // [esp+4h] [ebp-110h] BYREF
  _DWORD v7[2]; // [esp+8h] [ebp-10Ch] BYREF
  fd_set v8; // [esp+10h] [ebp-104h] BYREF

  if ( timeout >= 0 )
  {
    v7[0] = timeout;
    v8.fd_array[0] = this->ListenSocket;
    v7[1] = 0;
    v8.fd_count = 1;
    if ( ((int (__stdcall *)(unsigned int, fd_set *, _DWORD, _DWORD, _DWORD *))(&off_8E3A98 + 13))(
           v8.fd_array[0] + 1,
           &v8,
           0,
           0,
           v7) <= 0
      || !__WSAFDIsSet(this->ListenSocket, &v8) )
    {
      return 0;
    }
  }
  ListenSocket = this->ListenSocket;
  addrlen = 16;
  v3 = accept(ListenSocket, (struct sockaddr *)&this->SocketAddress, &addrlen);
  if ( v3 == -1 )
    return 0;
  this->Socket = v3;
  return 1;
}
