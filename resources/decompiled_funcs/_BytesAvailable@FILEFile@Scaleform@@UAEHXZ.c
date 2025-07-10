int __thiscall Scaleform::FILEFile::BytesAvailable(Scaleform::FILEFile *this)
{
  __int64 v2; // kr00_8
  int v3; // eax
  int v4; // edx
  int result; // eax

  v2 = this->LTell(this);
  v3 = this->LGetLength(this);
  if ( (HIDWORD(v2) & (unsigned int)v2) == 0xFFFFFFFF || (v4 & v3) == 0xFFFFFFFF )
  {
    if ( *_errno() == 2 )
    {
      this->ErrorCode = 4097;
      return 0;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      this->ErrorCode = 4098;
      return 0;
    }
    else
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return 0;
    }
  }
  else
  {
    result = v3 - v2;
    this->ErrorCode = 0;
  }
  return result;
}
