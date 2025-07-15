int __thiscall Scaleform::FILEFile::Tell(Scaleform::FILEFile *this)
{
  int result; // eax
  int v3; // esi

  result = ftell(this->fs);
  v3 = result;
  if ( result < 0 )
  {
    if ( *_errno() == 2 )
    {
      this->ErrorCode = 4097;
      return v3;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      this->ErrorCode = 4098;
      return v3;
    }
    else
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return v3;
    }
  }
  return result;
}
