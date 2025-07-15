int __thiscall Scaleform::GFx::Stream::ReadUInt1(Scaleform::GFx::Stream *this)
{
  unsigned __int8 UnusedBits; // al
  unsigned int Pos; // eax
  unsigned __int8 v4; // cl
  int result; // eax
  char v6; // dl

  UnusedBits = this->UnusedBits;
  if ( UnusedBits )
  {
    v6 = UnusedBits - 1;
    this->UnusedBits = UnusedBits - 1;
    result = this->CurrentByte >> (UnusedBits - 1);
    this->CurrentByte &= (1 << v6) - 1;
  }
  else
  {
    this->UnusedBits = 0;
    if ( (signed int)(this->DataSize - this->Pos) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    Pos = this->Pos;
    v4 = this->pBuffer[Pos];
    this->Pos = Pos + 1;
    result = v4 >> 7;
    this->UnusedBits = 7;
    this->CurrentByte = v4 & 0x7F;
  }
  return result;
}
