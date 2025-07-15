bool __thiscall Scaleform::GFx::AMP::Socket::IsConnected(Scaleform::GFx::AMP::Socket *this)
{
  int v1; // eax
  char v3; // [esp+1h] [ebp-1h] BYREF

  v3 = HIBYTE(this);
  v1 = this->SocketImpl->Send(this->SocketImpl, &v3, 0);
  if ( v1 < 0 )
    v1 = -1;
  return v1 >= 0;
}
