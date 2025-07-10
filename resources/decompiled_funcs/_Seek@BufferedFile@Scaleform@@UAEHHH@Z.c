unsigned int __thiscall Scaleform::BufferedFile::Seek(Scaleform::BufferedFile *this, int offset, int origin)
{
  int v4; // ebp
  unsigned int Pos; // edx
  unsigned int DataSize; // ecx
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int result; // eax
  unsigned int v10; // edi

  if ( this->BufferMode != ReadBuffer )
  {
    Scaleform::BufferedFile::FlushBuffer(this);
    v4 = origin;
    goto LABEL_12;
  }
  v4 = origin;
  if ( origin == 1 )
  {
    Pos = this->Pos;
    DataSize = this->DataSize;
    v7 = Pos + offset;
    if ( Pos + offset <= DataSize )
    {
      v8 = LODWORD(this->FilePos) - DataSize;
      this->Pos = v7;
      return v7 + v8;
    }
    v4 = 0;
    result = Pos + LODWORD(this->FilePos) - DataSize + offset;
    this->DataSize = 0;
    this->Pos = 0;
    goto LABEL_13;
  }
  if ( origin )
  {
    Scaleform::BufferedFile::FlushBuffer(this);
LABEL_12:
    result = offset;
    goto LABEL_13;
  }
  result = offset;
  v10 = this->DataSize;
  if ( v10 + (unsigned int)offset - this->FilePos <= v10 )
  {
    this->Pos = offset + v10 - LODWORD(this->FilePos);
    return result;
  }
  this->DataSize = 0;
  this->Pos = 0;
LABEL_13:
  result = this->pFile.pObject->Seek(this->pFile.pObject, result, v4);
  this->FilePos = (int)result;
  return result;
}
