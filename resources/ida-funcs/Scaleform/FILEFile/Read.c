int __userpurge Scaleform::FILEFile::Read@<eax>(
        Scaleform::FILEFile *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        unsigned __int8 *pbuffer,
        int numBytes)
{
  signed int v6; // ebx
  _iobuf *fs; // [esp-4h] [ebp-10h]

  if ( this->LastOp >= 2u )
    fflush(a2, a3, this->fs);
  fs = this->fs;
  this->LastOp = 1;
  v6 = fread(a2, numBytes, pbuffer, 1u, numBytes, fs);
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
