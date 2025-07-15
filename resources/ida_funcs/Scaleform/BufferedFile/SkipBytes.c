int __thiscall Scaleform::BufferedFile::SkipBytes(Scaleform::BufferedFile *this, int numBytes)
{
  int v2; // eax
  int v4; // edi
  unsigned int Pos; // ecx
  int v6; // eax
  bool v7; // cf

  v2 = numBytes;
  v4 = 0;
  if ( this->BufferMode == ReadBuffer )
  {
    Pos = this->Pos;
    v4 = this->DataSize - Pos;
    if ( v4 >= numBytes )
      v4 = numBytes;
    this->Pos = v4 + Pos;
    v2 = numBytes - v4;
  }
  if ( !v2 )
    return v4;
  v6 = this->pFile.pObject->SkipBytes(this->pFile.pObject, v2);
  if ( v6 != -1 )
  {
    v4 += v6;
    v7 = __CFADD__(v6, this->FilePos);
    LODWORD(this->FilePos) += v6;
    this->DataSize = 0;
    this->Pos = 0;
    HIDWORD(this->FilePos) += (v6 >> 31) + v7;
    return v4;
  }
  if ( v4 > 0 )
    return v4;
  return -1;
}
