Scaleform::GFx::TagType __thiscall Scaleform::GFx::Stream::OpenTag(
        Scaleform::GFx::Stream *this,
        Scaleform::GFx::TagInfo *pTagInfo)
{
  unsigned int DataSize; // eax
  unsigned int Pos; // ecx
  int v5; // ebx
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  int v8; // edi
  Scaleform::GFx::TagType v9; // ebp
  signed int v10; // edx
  unsigned int v11; // edx
  int v12; // eax

  DataSize = this->DataSize;
  Pos = this->Pos;
  v5 = Pos + this->FilePos - DataSize;
  this->UnusedBits = 0;
  if ( (int)(DataSize - Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  v6 = this->Pos;
  v7 = *(_WORD *)&this->pBuffer[v6];
  v8 = v7 & 0x3F;
  v9 = (int)v7 >> 6;
  this->Pos = v6 + 2;
  if ( v8 == 63 )
  {
    v10 = this->DataSize - (v6 + 2);
    this->UnusedBits = 0;
    if ( v10 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 4);
    v11 = this->Pos;
    v12 = this->pBuffer[v11] | ((this->pBuffer[v11 + 1] | (*(unsigned __int16 *)&this->pBuffer[v11 + 2] << 8)) << 8);
    this->Pos = v11 + 4;
    v8 = v12;
  }
  pTagInfo->TagOffset = v5;
  pTagInfo->TagType = v9;
  pTagInfo->TagLength = v8;
  pTagInfo->TagDataOffset = this->Pos + this->FilePos - this->DataSize;
  if ( (this->ParseFlags & 1) != 0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      this,
      "---------------Tag type = %d, Tag length = %d, offset = %d\n",
      v9,
      v8,
      v5);
  this->TagStack[this->TagStackEntryCount++] = v8 + this->Pos + this->FilePos - this->DataSize;
  return v9;
}


int __thiscall Scaleform::GFx::Stream::OpenTag(Scaleform::GFx::Stream *this)
{
  signed int v2; // eax
  unsigned int Pos; // eax
  unsigned __int16 v4; // dx
  int v5; // edi
  int v6; // ebp
  signed int v7; // edx
  unsigned int v8; // edx
  int v9; // eax

  v2 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v2 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 2);
  Pos = this->Pos;
  v4 = *(_WORD *)&this->pBuffer[Pos];
  v5 = v4 & 0x3F;
  v6 = (int)v4 >> 6;
  this->Pos = Pos + 2;
  if ( v5 == 63 )
  {
    v7 = this->DataSize - (Pos + 2);
    this->UnusedBits = 0;
    if ( v7 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 4);
    v8 = this->Pos;
    v9 = this->pBuffer[v8] | ((this->pBuffer[v8 + 1] | (*(unsigned __int16 *)&this->pBuffer[v8 + 2] << 8)) << 8);
    this->Pos = v8 + 4;
    v5 = v9;
  }
  if ( (this->ParseFlags & 1) != 0 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      this,
      "---------------Tag type = %d, Tag length = %d\n",
      v6,
      v5);
  this->TagStack[this->TagStackEntryCount++] = v5 + this->Pos + this->FilePos - this->DataSize;
  return v6;
}
