Scaleform::String *__usercall Scaleform::GFx::GetCharRanges_Scaleform::GFx::FontDataCompactedSwf_@<eax>(
        Scaleform::GFx::FontDataCompactedSwf *font@<eax>,
        Scaleform::String *a2)
{
  unsigned int (__thiscall *GetGlyphShapeCount)(struct Scaleform::GFx::FontDataCompactedSwf *); // edx
  unsigned int v4; // ebp
  unsigned __int8 **Pages; // edi
  unsigned int v6; // eax
  __int16 v7; // cx
  unsigned __int8 *v8; // edi
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned int v11; // eax
  unsigned __int16 v12; // bx
  unsigned int v13; // esi
  unsigned int v14; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v15; // edi
  char v17; // [esp+Fh] [ebp-19h]
  __int16 v18; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::Instances::fl::Object *v19; // [esp+14h] [ebp-14h]
  unsigned __int16 v20; // [esp+18h] [ebp-10h]
  Scaleform::GFx::AS3::Instances::fl::Object *v21; // [esp+18h] [ebp-10h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+1Ch] [ebp-Ch] BYREF

  GetGlyphShapeCount = font->GetGlyphShapeCount;
  v4 = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  v18 = 0;
  v20 = 0;
  v17 = 0;
  if ( !GetGlyphShapeCount(font) )
    goto LABEL_23;
  do
  {
    Pages = font->CompactedFontValue.Decoder.Data->Pages;
    v6 = 8 * v4 + font->CompactedFontValue.GlyphInfoTablePos;
    v7 = Pages[(v6 + 1) >> 12][(v6 + 1) & 0xFFF];
    v8 = Pages[v6 >> 12];
    v9 = v7 << 8;
    v10 = v6 & 0xFFF;
    if ( !v17 )
    {
      v18 = v8[v10] | v9;
      v17 = 1;
LABEL_4:
      v11 = 8 * v4 + font->CompactedFontValue.GlyphInfoTablePos;
      v12 = font->CompactedFontValue.Decoder.Data->Pages[v11 >> 12][v11 & 0xFFF]
          | (font->CompactedFontValue.Decoder.Data->Pages[(v11 + 1) >> 12][(v11 + 1) & 0xFFF] << 8);
      v20 = v12;
      ++v4;
      continue;
    }
    v12 = v20;
    if ( v20 == (v8[v10] | v9) - 1 )
      goto LABEL_4;
    v14 = pheapAddr.Size + 1;
    LOWORD(v19) = v18;
    HIWORD(v19) = v20;
    if ( pheapAddr.Size + 1 >= pheapAddr.Size )
    {
      if ( v14 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v14 + (v14 >> 2));
    }
    else if ( v14 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
    }
    pheapAddr.Size = v14;
    v15 = &pheapAddr.Data[v14 - 1];
    if ( v15 )
      *v15 = v19;
    v17 = 0;
  }
  while ( v4 < font->GetGlyphShapeCount(font) );
  if ( v17 )
  {
    v13 = pheapAddr.Size + 1;
    LOWORD(v21) = v18;
    HIWORD(v21) = v12;
    if ( pheapAddr.Size + 1 >= pheapAddr.Size )
    {
      if ( v13 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v13 + (v13 >> 2));
    }
    else if ( v13 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
    }
    pheapAddr.Size = v13;
    if ( &pheapAddr.Data[v13] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
      pheapAddr.Data[v13 - 1] = v21;
  }
LABEL_23:
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace'::Range,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace'::RangeLess>(
    (Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    0,
    pheapAddr.Size);
  Scaleform::GFx::BuildStringFromRanges(
    (const Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    a2);
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
  return a2;
}
