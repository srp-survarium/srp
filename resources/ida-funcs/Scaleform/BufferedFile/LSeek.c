int __thiscall Scaleform::BufferedFile::LSeek(Scaleform::BufferedFile *this, __int64 offset, int origin)
{
  int v4; // ebp
  unsigned __int64 v5; // rax
  unsigned int v6; // ecx
  unsigned int v7; // edi
  unsigned __int64 v8; // kr00_8
  unsigned int DataSize; // edi

  if ( this->BufferMode != ReadBuffer )
  {
    Scaleform::BufferedFile::FlushBuffer(this);
    v4 = origin;
    goto LABEL_12;
  }
  v4 = origin;
  if ( origin != 1 )
  {
    if ( !origin )
    {
      DataSize = this->DataSize;
      LODWORD(v5) = offset;
      if ( offset + DataSize - this->FilePos <= DataSize )
      {
        this->Pos = offset + DataSize - LODWORD(this->FilePos);
        return v5;
      }
      goto LABEL_6;
    }
    Scaleform::BufferedFile::FlushBuffer(this);
LABEL_12:
    LODWORD(v5) = offset;
    goto LABEL_13;
  }
  HIDWORD(v5) = this->Pos;
  v6 = this->DataSize;
  v7 = HIDWORD(v5) + offset;
  if ( HIDWORD(v5) + (int)offset > v6 )
  {
    v4 = 0;
    v8 = HIDWORD(v5) + this->FilePos - v6;
    LODWORD(v5) = v8 + offset;
    HIDWORD(offset) = (v8 + offset) >> 32;
LABEL_6:
    this->DataSize = 0;
    this->Pos = 0;
LABEL_13:
    v5 = ((__int64 (__thiscall *)(Scaleform::File *, _DWORD, _DWORD, int))this->pFile.pObject->LSeek)(
           this->pFile.pObject,
           v5,
           HIDWORD(offset),
           v4);
    this->FilePos = v5;
    return v5;
  }
  v5 = this->FilePos - v6;
  this->Pos = v7;
  LODWORD(v5) = v7 + v5;
  return v5;
}
