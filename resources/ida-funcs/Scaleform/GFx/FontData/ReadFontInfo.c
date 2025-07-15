void __thiscall Scaleform::GFx::FontData::ReadFontInfo(
        Scaleform::GFx::FontData *this,
        Scaleform::GFx::Stream *in,
        Scaleform::GFx::TagType tagType)
{
  char *Name; // eax
  signed int v6; // ecx
  unsigned int Pos; // eax
  unsigned __int8 v8; // bl
  unsigned int v9; // eax
  int v10; // ecx
  unsigned int v11; // eax
  char *v12; // eax
  unsigned int v13; // ecx
  const char *v14; // edx
  unsigned __int8 ina; // [esp+14h] [ebp+4h]

  Name = this->Name;
  if ( Name )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Name);
    this->Name = 0;
  }
  this->Name = Scaleform::GFx::Stream::ReadStringWithLength(in, in->FileName.pHeap);
  v6 = in->DataSize - in->Pos;
  in->UnusedBits = 0;
  if ( v6 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(in);
  Pos = in->Pos;
  v8 = in->pBuffer[Pos];
  v9 = Pos + 1;
  in->Pos = v9;
  ina = 0;
  if ( tagType == Tag_DefineFontInfo2 )
  {
    v10 = in->DataSize - v9;
    in->UnusedBits = 0;
    if ( v10 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(in);
    v11 = in->Pos;
    ina = in->pBuffer[v11];
    in->Pos = v11 + 1;
  }
  if ( (v8 & 0x10) != 0 )
  {
    this->Flags = this->Flags & 0xFFFFFCFF | 0x200;
  }
  else if ( (v8 & 8) != 0 )
  {
    this->Flags = this->Flags & 0xFFFFFCFF | 0x100;
  }
  else
  {
    this->Flags &= 0xFFFFFCFF;
  }
  if ( (v8 & 4) != 0 )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( (v8 & 2) != 0 )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
  if ( (v8 & 1) != 0 )
    this->Flags |= 0x4000u;
  else
    this->Flags &= ~0x4000u;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(in) )
  {
    if ( tagType == Tag_DefineFontInfo )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(in, "reading DefineFontInfo\n");
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(in, "reading DefineFontInfo2\n");
    v12 = this->Name;
    if ( !v12 )
      v12 = "(none)";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(in, "  Name = %s\n", v12);
    v13 = this->Flags & 0x300;
    v14 = "Unicode";
    if ( v13 == 512 )
    {
      v14 = "ShiftJIS";
    }
    else if ( v13 == 256 )
    {
      v14 = "ANSI";
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      in,
      "  CodePage = %s, Italic = %d, Bold = %d\n",
      v14,
      this->Flags & 1,
      (this->Flags >> 1) & 1);
    if ( tagType == Tag_DefineFontInfo2 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(in, "  LangCode = %d\n", ina);
  }
  Scaleform::GFx::FontData::ReadCodeTable(this, in);
}
