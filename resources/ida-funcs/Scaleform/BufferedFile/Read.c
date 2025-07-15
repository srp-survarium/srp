int __thiscall Scaleform::BufferedFile::Read(Scaleform::BufferedFile *this, unsigned __int8 *pdestBuffer, int numBytes)
{
  unsigned int Pos; // eax
  signed int v5; // ebx
  const __m128i *v6; // ecx
  int result; // eax
  signed int v8; // edi
  unsigned __int8 *v9; // ebp
  int v10; // eax
  bool v11; // cf
  unsigned int v12; // ecx

  if ( this->BufferMode == ReadBuffer )
  {
LABEL_4:
    Pos = this->Pos;
    v5 = this->DataSize - Pos;
    v6 = (const __m128i *)&this->pBuffer[Pos];
    if ( v5 < numBytes )
    {
      memcpy((int)pdestBuffer, v6, v5);
      v8 = numBytes - v5;
      v9 = &pdestBuffer[v5];
      this->Pos = this->DataSize;
      if ( numBytes - v5 <= 4096 )
      {
        Scaleform::BufferedFile::LoadBuffer(this);
        v12 = this->Pos;
        if ( (int)(this->DataSize - v12) < v8 )
          v8 = this->DataSize - v12;
        memcpy((int)v9, (const __m128i *)&this->pBuffer[v12], v8);
        this->Pos += v8;
        return v5 + v8;
      }
      else
      {
        v10 = this->pFile.pObject->Read(this->pFile.pObject, v9, v8);
        if ( v10 > 0 )
        {
          v11 = __CFADD__(v10, this->FilePos);
          LODWORD(this->FilePos) += v10;
          this->DataSize = 0;
          this->Pos = 0;
          HIDWORD(this->FilePos) += (v10 >> 31) + v11;
        }
        return v5 + (v10 != -1 ? v10 : 0);
      }
    }
    else
    {
      memcpy((int)pdestBuffer, v6, numBytes);
      this->Pos += numBytes;
      return numBytes;
    }
  }
  if ( this->pBuffer )
  {
    Scaleform::BufferedFile::FlushBuffer(this);
    this->BufferMode = ReadBuffer;
    this->Pos = 0;
    this->DataSize = 0;
    goto LABEL_4;
  }
  result = this->pFile.pObject->Read(this->pFile.pObject, pdestBuffer, numBytes);
  if ( result > 0 )
    this->FilePos += result;
  return result;
}
