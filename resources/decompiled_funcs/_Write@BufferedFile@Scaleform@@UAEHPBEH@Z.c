int __thiscall Scaleform::BufferedFile::Write(
        Scaleform::BufferedFile *this,
        unsigned __int8 *psourceBuffer,
        int numBytes)
{
  Scaleform::File *pObject; // ecx
  int result; // eax

  if ( this->BufferMode != WriteBuffer )
  {
    if ( !this->pBuffer )
      goto LABEL_8;
    Scaleform::BufferedFile::FlushBuffer(this);
    pObject = this->pFile.pObject;
    if ( !pObject || !pObject->IsWritable(pObject) )
      goto LABEL_8;
    this->BufferMode = WriteBuffer;
    this->Pos = 0;
    this->DataSize = 0;
  }
  if ( (signed int)(8184 - this->Pos) >= numBytes || (Scaleform::BufferedFile::FlushBuffer(this), numBytes <= 4096) )
  {
    memcpy(&this->pBuffer[this->Pos], psourceBuffer, numBytes);
    this->Pos += numBytes;
    return numBytes;
  }
LABEL_8:
  result = this->pFile.pObject->Write(this->pFile.pObject, psourceBuffer, numBytes);
  if ( result > 0 )
    this->FilePos += result;
  return result;
}
