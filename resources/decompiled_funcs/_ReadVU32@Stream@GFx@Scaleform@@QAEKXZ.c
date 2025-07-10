int __thiscall Scaleform::GFx::Stream::ReadVU32(Scaleform::GFx::Stream *this)
{
  int v1; // ebp
  unsigned int v3; // edi
  signed int v4; // eax
  unsigned int Pos; // eax
  char v6; // dl
  int v7; // eax

  v1 = 0;
  v3 = 0;
  do
  {
    v4 = this->DataSize - this->Pos;
    this->UnusedBits = 0;
    if ( v4 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    Pos = this->Pos;
    v6 = this->pBuffer[Pos];
    this->Pos = Pos + 1;
    v7 = (v6 & 0x7F) << v3;
    v3 += 7;
    v1 |= v7;
  }
  while ( v3 < 0x20 && v6 < 0 );
  return v1;
}
