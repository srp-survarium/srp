void __thiscall Scaleform::BufferedFile::FlushBuffer(Scaleform::BufferedFile *this)
{
  int v2; // eax
  bool v3; // cf
  unsigned int Pos; // eax

  if ( this->BufferMode == ReadBuffer )
  {
    Pos = this->Pos;
    if ( this->DataSize != Pos )
      this->FilePos = ((__int64 (__thiscall *)(Scaleform::File *, unsigned int, int, int))this->pFile.pObject->LSeek)(
                        this->pFile.pObject,
                        Pos - this->DataSize,
                        (int)(Pos - this->DataSize) >> 31,
                        1);
    this->DataSize = 0;
    this->Pos = 0;
  }
  else if ( this->BufferMode == WriteBuffer )
  {
    v2 = this->pFile.pObject->Write(this->pFile.pObject, this->pBuffer, this->Pos);
    v3 = __CFADD__(v2, this->FilePos);
    LODWORD(this->FilePos) += v2;
    this->Pos = 0;
    HIDWORD(this->FilePos) += (v2 >> 31) + v3;
  }
}
