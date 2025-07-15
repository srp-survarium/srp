int __thiscall Scaleform::GFx::Stream::ReadUInt(Scaleform::GFx::Stream *this, int bitcount)
{
  int v2; // edi
  int v3; // ebp
  unsigned __int8 UnusedBits; // al
  int v6; // ecx
  int v7; // eax
  signed int v8; // ecx
  unsigned int Pos; // eax
  unsigned __int8 v10; // cl
  unsigned __int8 CurrentByte; // dl
  unsigned __int8 v13; // cl

  v2 = bitcount;
  v3 = 0;
  if ( bitcount <= 0 )
    return v3;
  while ( 1 )
  {
    UnusedBits = this->UnusedBits;
    if ( !UnusedBits )
    {
      v8 = this->DataSize - this->Pos;
      this->UnusedBits = 0;
      if ( v8 < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(this, 1);
      Pos = this->Pos;
      v10 = this->pBuffer[Pos];
      this->Pos = Pos + 1;
      this->CurrentByte = v10;
      this->UnusedBits = 8;
      goto LABEL_8;
    }
    if ( v2 < UnusedBits )
      break;
    v6 = v2 - UnusedBits;
    v7 = this->CurrentByte << (v2 - UnusedBits);
    v2 = v6;
    this->UnusedBits = 0;
    v3 |= v7;
LABEL_8:
    if ( v2 <= 0 )
      return v3;
  }
  CurrentByte = this->CurrentByte;
  v13 = this->UnusedBits - v2;
  v3 |= CurrentByte >> v13;
  this->UnusedBits = v13;
  this->CurrentByte = CurrentByte & ((1 << v13) - 1);
  return v3;
}
