bool __usercall Scaleform::FILEFile::Close@<al>(Scaleform::FILEFile *this@<ecx>, int a2@<ebx>)
{
  bool result; // al

  if ( fclose(a2, this->fs) )
  {
    if ( *_errno() == 2 )
    {
      result = 0;
      this->ErrorCode = 4097;
    }
    else if ( *_errno() == 13 || *_errno() == 1 )
    {
      result = 0;
      this->ErrorCode = 4098;
    }
    else
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return 0;
    }
  }
  else
  {
    result = 1;
    this->Opened = 0;
    this->fs = 0;
    this->ErrorCode = 0;
  }
  return result;
}
