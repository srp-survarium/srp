SOCKET __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Send(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        const char *dataBuffer,
        unsigned int dataBufferSize)
{
  SOCKET result; // eax

  result = this->Socket;
  if ( result != -1 )
  {
    result = send(result, dataBuffer, dataBufferSize, 0);
    if ( result == -1 )
      return -(this->GetLastError(this) != 10035);
  }
  return result;
}
