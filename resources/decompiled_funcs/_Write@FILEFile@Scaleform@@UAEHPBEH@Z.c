int __userpurge Scaleform::FILEFile::Write@<eax>(
        Scaleform::FILEFile *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned __int8 *pbuffer,
        int numBytes)
{
  int LastOp; // eax
  signed int v6; // ebx
  _iobuf *fs; // [esp-4h] [ebp-10h]

  LastOp = this->LastOp;
  if ( LastOp && LastOp != 2 )
    fflush(this->fs);
  fs = this->fs;
  this->LastOp = 2;
  v6 = fwrite(a2, numBytes, pbuffer, 1u, numBytes, fs);
  if ( v6 < numBytes )
  {
    if ( *_errno() == 2 )
    {
      this->ErrorCode = 4097;
      return v6;
    }
    if ( *_errno() != 13 && *_errno() != 1 )
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return v6;
    }
    this->ErrorCode = 4098;
  }
  return v6;
}
