void __thiscall Scaleform::GFx::FontDataCompactedGfx::Read(
        Scaleform::GFx::FontDataCompactedGfx *this,
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::FontDataCompactedGfx *v3; // esi
  unsigned int v4; // ebp
  Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *p_Container; // edi
  unsigned __int8 *Data; // ebx
  signed int v7; // ebp
  signed int i; // edx
  unsigned int Size; // esi
  unsigned __int8 *v10; // ecx
  unsigned __int8 v11; // al
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *v12; // edi
  unsigned int NominalSize; // eax
  const char *v14; // eax
  double v15; // st7
  const char *(__thiscall *GetName)(struct Scaleform::GFx::FontDataCompactedGfx *); // eax
  const char *v17; // eax
  unsigned int v18; // [esp+8h] [ebp-18h]
  signed int v19; // [esp+Ch] [ebp-14h]
  Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2> > v21; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::Stream *v22; // [esp+24h] [ebp+4h]
  float v23; // [esp+24h] [ebp+4h]
  signed int v24; // [esp+28h] [ebp+8h]

  v3 = this;
  if ( p[213].__vftable )
    v22 = (Scaleform::GFx::Stream *)p[213].__vftable;
  else
    v22 = (Scaleform::GFx::Stream *)&p[12];
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(v22, "reading DefineCompactedFont:\n");
  v4 = tagInfo->TagLength - 2;
  v19 = v4;
  memset(&v21, 0, sizeof(v21));
  Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>>::Reserve(&v21, 0x1000u, 0);
  p_Container = &v3->Container;
  Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,261>>::Reserve(
    &v3->Container,
    v4,
    0);
  v24 = 0;
  Data = v21.Data;
  while ( 1 )
  {
    v18 = 4096;
    if ( (int)(v4 - v24) <= 4096 )
      v18 = v4 - v24;
    v7 = Scaleform::GFx::Stream::ReadToBuffer(v22, Data, v18);
    v24 += v7;
    if ( v7 > 0 )
    {
      for ( i = 0; i < v7; ++i )
      {
        Size = p_Container->Size;
        v10 = &p_Container->Data[Size];
        p_Container->Size = Size + 1;
        v11 = Data[i];
        *v10 = v11;
      }
      v3 = this;
    }
    if ( v7 != v18 )
    {
      v12 = v22;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
        v22,
        "Could not read tag DefineCompactedFont. Broken gfx file.");
      goto LABEL_16;
    }
    if ( v24 >= v19 )
      break;
    v4 = v19;
  }
  v12 = v22;
LABEL_16:
  Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::AcquireFont(
    &v3->CompactedFontValue,
    0);
  NominalSize = v3->CompactedFontValue.NominalSize;
  if ( NominalSize )
  {
    v15 = (double)NominalSize;
    GetName = v3->GetName;
    v23 = 1024.0 / v15;
    v3->Leading = v3->CompactedFontValue.Leading * v23;
    v3->Ascent = v3->CompactedFontValue.Ascent * v23;
    v3->Descent = v23 * v3->CompactedFontValue.Descent;
    v17 = GetName(v3);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(v12, "read font \"%s\"\n", v17);
    v3->Flags = v3->CompactedFontValue.Flags;
  }
  else
  {
    v14 = v3->GetName(v3);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      v12,
      "Invalid nominal size for DefineCompactedFont, font %s. Broken gfx file.",
      v14);
    v3->Leading = 0.0;
    v3->Ascent = 960.0;
    v3->Descent = 64.0;
  }
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
