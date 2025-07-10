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
