void __thiscall Scaleform::GFx::FontDataCompactedGfx::Read(
        Scaleform::GFx::FontDataCompactedGfx *this,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // ecx
  unsigned int v5; // ebp
  Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *p_Container; // edi
  unsigned __int8 *Data; // ebx
  signed int v8; // ebp
  signed int i; // edx
  unsigned int Size; // esi
  unsigned __int8 *v11; // ecx
  unsigned __int8 v12; // al
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *p_Stream; // edi
  unsigned int NominalSize; // eax
  const char *v15; // eax
  double v16; // st7
  const char *(__thiscall *GetName)(struct Scaleform::GFx::FontDataCompactedGfx *); // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // ecx
  unsigned int bytesToRead; // [esp+8h] [ebp-18h]
  int csize; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::FontDataCompactedGfx *v21; // [esp+10h] [ebp-10h]
  Scaleform::ArrayUnsafePOD<unsigned char,2> buf; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::SWFProcessInfo *scale; // [esp+24h] [ebp+4h]
  float scalea; // [esp+24h] [ebp+4h]
  int bytes; // [esp+28h] [ebp+8h]

  v4 = p;
  v21 = this;
  if ( p[42].pPrev )
  {
    scale = (Scaleform::GFx::SWFProcessInfo *)p[42].pPrev;
  }
  else
  {
    v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)p + 48);
    scale = (Scaleform::GFx::SWFProcessInfo *)&p[2].8;
  }
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v4);
  v5 = tagInfo->TagLength - 2;
  csize = v5;
  memset(&buf, 0, sizeof(buf));
  Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>>::Reserve(&buf, 0x1000u, 0);
  p_Container = &this->Container;
  Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,261>>::Reserve(
    &this->Container,
    v5,
    0);
  bytes = 0;
  Data = buf.Data;
  while ( 1 )
  {
    bytesToRead = 4096;
    if ( (int)(v5 - bytes) <= 4096 )
      bytesToRead = v5 - bytes;
    v8 = Scaleform::GFx::Stream::ReadToBuffer(&scale->Stream, Data, bytesToRead);
    bytes += v8;
    if ( v8 > 0 )
    {
      for ( i = 0; i < v8; ++i )
      {
        Size = p_Container->Size;
        v11 = &p_Container->Data[Size];
        p_Container->Size = Size + 1;
        v12 = Data[i];
        *v11 = v12;
      }
      this = v21;
    }
    if ( v8 != bytesToRead )
    {
      p_Stream = &scale->Stream;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
        &scale->Stream,
        "Could not read tag DefineCompactedFont. Broken gfx file.");
      goto LABEL_16;
    }
    if ( bytes >= csize )
      break;
    v5 = csize;
  }
  p_Stream = &scale->Stream;
LABEL_16:
  Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::AcquireFont(
    &this->CompactedFontValue,
    0);
  NominalSize = this->CompactedFontValue.NominalSize;
  if ( NominalSize )
  {
    v16 = (double)NominalSize;
    GetName = this->GetName;
    scalea = 1024.0 / v16;
    this->Leading = this->CompactedFontValue.Leading * scalea;
    this->Ascent = this->CompactedFontValue.Ascent * scalea;
    this->Descent = scalea * this->CompactedFontValue.Descent;
    GetName(this);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v18);
    this->Flags = this->CompactedFontValue.Flags;
  }
  else
  {
    v15 = this->GetName(this);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      p_Stream,
      "Invalid nominal size for DefineCompactedFont, font %s. Broken gfx file.",
      v15);
    this->Leading = 0.0;
    this->Ascent = 960.0;
    this->Descent = 64.0;
  }
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
