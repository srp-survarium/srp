void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::SetBlocking(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        unsigned int blocking)
{
  SOCKET Socket; // eax

  Socket = this->Socket;
  if ( Socket != -1 )
  {
    blocking = (_BYTE)blocking == 0;
    ioctlsocket(Socket, -2147195266, &blocking);
  }
}
