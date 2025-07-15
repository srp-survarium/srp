void __thiscall Scaleform::BufferedFile::LoadBuffer(Scaleform::BufferedFile *this)
{
  int v2; // eax
  unsigned int v3; // eax
  bool v4; // cf

  if ( this->BufferMode == ReadBuffer )
  {
    v2 = this->pFile.pObject->Read(this->pFile.pObject, this->pBuffer, 8184);
    this->Pos = 0;
    v3 = v2 < 0 ? 0 : v2;
    v4 = __CFADD__(v3, this->FilePos);
    LODWORD(this->FilePos) += v3;
    this->DataSize = v3;
    HIDWORD(this->FilePos) += v4;
  }
}
