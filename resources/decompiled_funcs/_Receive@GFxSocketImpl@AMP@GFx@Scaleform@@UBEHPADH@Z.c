SOCKET __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Receive(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        char *dataBuffer,
        int dataBufferSize)
{
  SOCKET result; // eax

  result = this->Socket;
  if ( result != -1 )
    return recv(result, dataBuffer, dataBufferSize, 0);
  return result;
}
