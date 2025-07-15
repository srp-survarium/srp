bool __thiscall Scaleform::GFx::AMP::Socket::IsConnected(Scaleform::GFx::AMP::Socket *this)
{
  int v1; // eax
  char strBuf[1]; // [esp+1h] [ebp-1h] BYREF

  strBuf[0] = HIBYTE(this);
  v1 = this->SocketImpl->Send(this->SocketImpl, strBuf, 0);
  if ( v1 < 0 )
    v1 = -1;
  return v1 >= 0;
}
