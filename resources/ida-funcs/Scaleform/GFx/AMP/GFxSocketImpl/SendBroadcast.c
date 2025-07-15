unsigned int __thiscall Scaleform::GFx::AMP::GFxSocketImpl::SendBroadcast(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        const char *dataBuffer,
        unsigned int dataBufferSize)
{
  unsigned int result; // eax

  result = this->Socket;
  if ( result != -1 )
    return ((int (__stdcall *)(unsigned int, const char *, unsigned int, _DWORD, sockaddr_in *))(&off_8E3A98 + 3))(
             result,
             dataBuffer,
             dataBufferSize,
             0,
             &this->SocketAddress);
  return result;
}
