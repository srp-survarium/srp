void __thiscall Scaleform::GFx::Stream::LogBytes(Scaleform::GFx::Stream *this, unsigned int numOfBytes)
{
  int v2; // edi
  unsigned int v4; // ebp
  signed int v5; // eax
  unsigned int Pos; // eax
  unsigned int v7; // ebx
  int i; // edi
  _BYTE v9[16]; // [esp+8h] [ebp-10h]

  v2 = 0;
  if ( numOfBytes )
  {
    v4 = numOfBytes;
    do
    {
      v5 = this->DataSize - this->Pos;
      this->UnusedBits = 0;
      if ( v5 < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(this, 1);
      Pos = this->Pos;
      v7 = this->pBuffer[Pos];
      this->Pos = Pos + 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, "%02X", v7);
      if ( v7 < 0x20 || v7 > 0x7F )
        LOBYTE(v7) = 46;
      v9[v2++] = v7;
      if ( v2 < 16 )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, " ");
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, "    ");
        for ( i = 0; i < 16; ++i )
          Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, "%c", (char)v9[i]);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, "\n");
        v2 = 0;
      }
      --v4;
    }
    while ( v4 );
    if ( v2 > 0 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(this, "\n");
  }
}
