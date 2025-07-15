SOCKET __thiscall Scaleform::GFx::AMP::GFxSocketImpl::ReceiveBroadcast(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        char *dataBuffer,
        int dataSize)
{
  SOCKET result; // eax
  int addrLength; // [esp+0h] [ebp-4h] BYREF

  addrLength = (int)this;
  result = this->Socket;
  if ( result != -1 )
  {
    addrLength = 16;
    return recvfrom(result, dataBuffer, dataSize, 0, (struct sockaddr *)&this->SocketAddress, &addrLength);
  }
  return result;
}
