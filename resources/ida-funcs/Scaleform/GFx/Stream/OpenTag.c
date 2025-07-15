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


int __thiscall Scaleform::GFx::Stream::OpenTag(Scaleform::GFx::Stream *this)
{
  signed int v2; // eax
  unsigned int Pos; // eax
  unsigned __int16 v4; // dx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ecx
  int v6; // edi
  int v7; // ebp
  int v8; // edx
  unsigned int v9; // edx
  unsigned __int8 *pBuffer; // eax
  int v11; // eax

  v2 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v2 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  Pos = this->Pos;
  v4 = *(_WORD *)&this->pBuffer[Pos];
  v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(Pos + 2);
  v6 = v4 & 0x3F;
  v7 = (int)v4 >> 6;
  this->Pos = Pos + 2;
  if ( v6 == 63 )
  {
    v8 = this->DataSize - (_DWORD)v5;
    this->UnusedBits = 0;
    if ( v8 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 4);
    v9 = this->Pos;
    pBuffer = this->pBuffer;
    v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pBuffer[v9];
    v11 = (unsigned int)v5 | ((pBuffer[v9 + 1] | (*(unsigned __int16 *)&pBuffer[v9 + 2] << 8)) << 8);
    this->Pos = v9 + 4;
    v6 = v11;
  }
  if ( (this->ParseFlags & 1) != 0 )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v5);
  this->TagStack[this->TagStackEntryCount++] = v6 + this->Pos + this->FilePos - this->DataSize;
  return v7;
}
