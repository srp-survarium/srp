SOCKET __thiscall Scaleform::GFx::AMP::GFxSocketImpl::SendBroadcast(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        const char *dataBuffer,
        unsigned int dataBufferSize)
{
  SOCKET result; // eax

  result = this->Socket;
  if ( result != -1 )
    return sendto(result, dataBuffer, dataBufferSize, 0, (const struct sockaddr *)&this->SocketAddress, 16);
  return result;
}
