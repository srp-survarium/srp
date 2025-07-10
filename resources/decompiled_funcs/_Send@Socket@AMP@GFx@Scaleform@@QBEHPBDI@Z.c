int __thiscall Scaleform::GFx::AMP::Socket::Send(
        Scaleform::GFx::AMP::Socket *this,
        const char *dataBuffer,
        unsigned int dataBufferSize)
{
  int result; // eax

  result = this->SocketImpl->Send(this->SocketImpl, dataBuffer, dataBufferSize);
  if ( result < 0 )
    return -1;
  return result;
}
