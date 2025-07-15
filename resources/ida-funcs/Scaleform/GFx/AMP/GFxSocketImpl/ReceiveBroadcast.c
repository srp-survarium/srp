unsigned int __thiscall Scaleform::GFx::AMP::GFxSocketImpl::ReceiveBroadcast(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        char *dataBuffer,
        int dataSize)
{
  unsigned int result; // eax

  result = this->Socket;
  if ( result != -1 )
    return ((int (__stdcall *)(unsigned int, char *, int, _DWORD, sockaddr_in *))(&off_8E3A98 + 4))(
             result,
             dataBuffer,
             dataSize,
             0,
             &this->SocketAddress);
  return result;
}
