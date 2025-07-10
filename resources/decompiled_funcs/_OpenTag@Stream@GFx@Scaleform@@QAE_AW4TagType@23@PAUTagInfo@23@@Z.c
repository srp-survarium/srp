Scaleform::GFx::TagType __thiscall Scaleform::GFx::Stream::OpenTag(
        Scaleform::GFx::Stream *this,
        Scaleform::GFx::TagInfo *pTagInfo)
{
  unsigned int DataSize; // eax
  unsigned int Pos; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ecx
  int v9; // edi
  Scaleform::GFx::TagType v10; // ebp
  int v11; // edx
  unsigned int v12; // edx
  unsigned __int8 *pBuffer; // eax
  int v14; // eax

  DataSize = this->DataSize;
  Pos = this->Pos;
  v5 = Pos + this->FilePos - DataSize;
  this->UnusedBits = 0;
  if ( (int)(DataSize - Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  v6 = this->Pos;
  v7 = *(_WORD *)&this->pBuffer[v6];
  v8 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v6 + 2);
  v9 = v7 & 0x3F;
  v10 = (int)v7 >> 6;
  this->Pos = v6 + 2;
  if ( v9 == 63 )
  {
    v11 = this->DataSize - (_DWORD)v8;
    this->UnusedBits = 0;
    if ( v11 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 4);
    v12 = this->Pos;
    pBuffer = this->pBuffer;
    v8 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pBuffer[v12];
    v14 = (unsigned int)v8 | ((pBuffer[v12 + 1] | (*(unsigned __int16 *)&pBuffer[v12 + 2] << 8)) << 8);
    this->Pos = v12 + 4;
    v9 = v14;
  }
  pTagInfo->TagOffset = v5;
  pTagInfo->TagType = v10;
  pTagInfo->TagLength = v9;
  pTagInfo->TagDataOffset = this->Pos + this->FilePos - this->DataSize;
  if ( (this->ParseFlags & 1) != 0 )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v8);
  this->TagStack[this->TagStackEntryCount++] = v9 + this->Pos + this->FilePos - this->DataSize;
  return v10;
}
