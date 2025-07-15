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
  Scaleform::GFx::Range *v15; // edi
  bool rangeStarted; // [esp+Fh] [ebp-19h]
  unsigned __int16 rangeStart; // [esp+10h] [ebp-18h]
  Scaleform::GFx::Range range; // [esp+14h] [ebp-14h]
  unsigned __int16 prevValue; // [esp+18h] [ebp-10h]
  Scaleform::GFx::Range prevValuea; // [esp+18h] [ebp-10h]
  Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> ranges; // [esp+1Ch] [ebp-Ch] BYREF

  GetGlyphShapeCount = font->GetGlyphShapeCount;
  v4 = 0;
  memset(&ranges, 0, sizeof(ranges));
  rangeStart = 0;
  prevValue = 0;
  rangeStarted = 0;
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
    if ( !rangeStarted )
    {
      rangeStart = v8[v10] | v9;
      rangeStarted = 1;
LABEL_4:
      v11 = 8 * v4 + font->CompactedFontValue.GlyphInfoTablePos;
      v12 = font->CompactedFontValue.Decoder.Data->Pages[v11 >> 12][v11 & 0xFFF]
          | (font->CompactedFontValue.Decoder.Data->Pages[(v11 + 1) >> 12][(v11 + 1) & 0xFFF] << 8);
      prevValue = v12;
      ++v4;
      continue;
    }
    v12 = prevValue;
    if ( prevValue == (v8[v10] | v9) - 1 )
      goto LABEL_4;
    v14 = ranges.Data.Size + 1;
    range.start = rangeStart;
    range.end = prevValue;
    if ( ranges.Data.Size + 1 >= ranges.Data.Size )
    {
      if ( v14 >= ranges.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
          &ranges,
          v14 + (v14 >> 2));
    }
    else if ( v14 < ranges.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
        &ranges,
        ranges.Data.Size + 1);
    }
    ranges.Data.Size = v14;
    v15 = &ranges.Data.Data[v14 - 1];
    if ( v15 )
      *v15 = range;
    rangeStarted = 0;
  }
  while ( v4 < font->GetGlyphShapeCount(font) );
  if ( rangeStarted )
  {
    v13 = ranges.Data.Size + 1;
    prevValuea.start = rangeStart;
    prevValuea.end = v12;
    if ( ranges.Data.Size + 1 >= ranges.Data.Size )
    {
      if ( v13 >= ranges.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
          &ranges,
          v13 + (v13 >> 2));
    }
    else if ( v13 < ranges.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
        &ranges,
        ranges.Data.Size + 1);
    }
    ranges.Data.Size = v13;
    if ( &ranges.Data.Data[v13] != (Scaleform::GFx::Range *)4 )
      ranges.Data.Data[v13 - 1] = prevValuea;
  }
LABEL_23:
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace'::Range,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace'::RangeLess>(
    &ranges,
    0,
    ranges.Data.Size);
  Scaleform::GFx::BuildStringFromRanges(&ranges, a2);
  if ( ranges.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ranges.Data.Data);
  return a2;
}
