__int64 __thiscall Scaleform::FILEFile::LTell(Scaleform::FILEFile *this)
{
  int v2; // edi

  v2 = ftell(this->fs);
  if ( v2 < 0 )
  {
    if ( *_errno() == 2 )
    {
      this->ErrorCode = 4097;
      return v2;
    }
    if ( *_errno() != 13 && *_errno() != 1 )
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return v2;
    }
    this->ErrorCode = 4098;
  }
  return v2;
}
