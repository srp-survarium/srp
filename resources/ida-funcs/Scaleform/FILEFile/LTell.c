__int64 __usercall Scaleform::FILEFile::LTell@<edx:eax>(Scaleform::FILEFile *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // edi

  v4 = ftell(a2, a3, this->fs);
  if ( v4 < 0 )
  {
    if ( *_errno() == 2 )
    {
      this->ErrorCode = 4097;
      return v4;
    }
    if ( *_errno() != 13 && *_errno() != 1 )
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return v4;
    }
    this->ErrorCode = 4098;
  }
  return v4;
}
