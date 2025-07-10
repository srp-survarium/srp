int __thiscall Scaleform::FILEFile::Read(Scaleform::FILEFile *this, unsigned __int8 *pbuffer, int numBytes)
{
  signed int v4; // ebx
  _iobuf *fs; // [esp-4h] [ebp-10h]

  if ( this->LastOp >= 2u )
    fflush(this->fs);
  fs = this->fs;
  this->LastOp = 1;
  v4 = fread((char *)pbuffer, 1u, numBytes, fs);
  if ( v4 < numBytes )
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
