int __usercall Scaleform::FILEFile::Tell@<eax>(Scaleform::FILEFile *this@<ecx>, int a2@<ebx>)
{
  int result; // eax
  int v4; // esi

  result = ftell(a2, (int)this, this->fs);
  v4 = result;
  if ( result < 0 )
  {
    if ( *_errno() == 2 )
    {
      this->ErrorCode = 4097;
      return v4;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      this->ErrorCode = 4098;
      return v4;
    }
    else
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return v4;
    }
  }
  return result;
}
