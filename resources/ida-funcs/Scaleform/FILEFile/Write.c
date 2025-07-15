int __userpurge Scaleform::FILEFile::Write@<eax>(
        Scaleform::FILEFile *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const __m128i *pbuffer,
        int numBytes)
{
  int LastOp; // eax
  signed int v7; // ebx
  _iobuf *fs; // [esp-4h] [ebp-10h]

  LastOp = this->LastOp;
  if ( LastOp && LastOp != 2 )
    fflush(a2, a3, this->fs);
  fs = this->fs;
  this->LastOp = 2;
  v7 = fwrite(a2, numBytes, pbuffer, 1u, numBytes, fs);
  if ( v7 < numBytes )
  {
    if ( *_errno() == 2 )
    {
      this->ErrorCode = 4097;
      return v7;
    }
    if ( *_errno() != 13 && *_errno() != 1 )
    {
      this->ErrorCode = (*_errno() == 28) + 4099;
      return v7;
    }
    this->ErrorCode = 4098;
  }
  return v7;
}
