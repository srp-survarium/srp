char __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Accept(Scaleform::GFx::AMP::GFxSocketImpl *this, int timeout)
{
  SOCKET v3; // eax
  SOCKET ListenSocket; // [esp-Ch] [ebp-120h]
  int iSize; // [esp+4h] [ebp-110h] BYREF
  timeval tv; // [esp+8h] [ebp-10Ch] BYREF
  fd_set readfds; // [esp+10h] [ebp-104h] BYREF

  if ( timeout >= 0 )
  {
    tv.tv_sec = timeout;
    readfds.fd_array[0] = this->ListenSocket;
    tv.tv_usec = 0;
    readfds.fd_count = 1;
    if ( select(readfds.fd_array[0] + 1, &readfds, 0, 0, &tv) <= 0 || !__WSAFDIsSet(this->ListenSocket, &readfds) )
      return 0;
  }
  ListenSocket = this->ListenSocket;
  iSize = 16;
  v3 = accept(ListenSocket, (struct sockaddr *)&this->SocketAddress, &iSize);
  if ( v3 == -1 )
    return 0;
  this->Socket = v3;
  return 1;
}
