void __thiscall Scaleform::GFx::FontData::ReadFontInfo(
        Scaleform::GFx::FontData *this,
        Scaleform::GFx::Stream *in,
        Scaleform::GFx::TagType tagType)
{
  char *Name; // eax
  signed int v5; // ecx
  unsigned int Pos; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // eax
  int v9; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // ecx

  Name = this->Name;
  if ( Name )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Name);
    this->Name = 0;
  }
  this->Name = Scaleform::GFx::Stream::ReadStringWithLength(in, in->FileName.pHeap);
  v5 = in->DataSize - in->Pos;
  in->UnusedBits = 0;
  if ( v5 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(in);
  Pos = in->Pos;
  v7 = in->pBuffer[Pos];
  v8 = Pos + 1;
  in->Pos = v8;
  if ( tagType == Tag_DefineFontInfo2 )
  {
    v9 = in->DataSize - v8;
    in->UnusedBits = 0;
    if ( v9 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(in);
    ++in->Pos;
  }
  if ( (v7 & 0x10) != 0 )
  {
    this->Flags = this->Flags & 0xFFFFFCFF | 0x200;
  }
  else if ( (v7 & 8) != 0 )
  {
    this->Flags = this->Flags & 0xFFFFFCFF | 0x100;
  }
  else
  {
    this->Flags &= 0xFFFFFCFF;
  }
  if ( (v7 & 4) != 0 )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( (v7 & 2) != 0 )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
  if ( (v7 & 1) != 0 )
    this->Flags |= 0x4000u;
  else
    this->Flags &= ~0x4000u;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(in) )
  {
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v10);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v11);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)(this->Flags & 1));
    if ( tagType == Tag_DefineFontInfo2 )
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v12);
  }
  Scaleform::GFx::FontData::ReadCodeTable(this, in);
}
