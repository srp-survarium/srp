unsigned int __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Send(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        const char *dataBuffer,
        unsigned int dataBufferSize)
{
  unsigned int result; // eax
  int v5; // [esp+0h] [ebp-4h]

  result = this->Socket;
  if ( result != -1 )
  {
    result = ((int (__stdcall *)(unsigned int, const char *, unsigned int, _DWORD, int))(&off_8E3A98 + 1))(
               result,
               dataBuffer,
               dataBufferSize,
               0,
               v5);
    if ( result == -1 )
      return -(this->GetLastError(this) != 10035);
  }
  return result;
}
