Scaleform::String *__usercall Scaleform::GFx::GetCharRanges_Scaleform::GFx::FontDataCompactedGfx_@<eax>(
        Scaleform::GFx::FontDataCompactedGfx *font@<eax>,
        Scaleform::String *a2)
{
  unsigned int (__thiscall *GetGlyphShapeCount)(struct Scaleform::GFx::FontDataCompactedGfx *); // edx
  unsigned int Size; // edi
  unsigned __int16 v5; // bx
  unsigned int v6; // ebp
  unsigned __int8 *v7; // ecx
  unsigned int v8; // esi
  unsigned int v9; // edi
  Scaleform::GFx::Range *v10; // edi
  Scaleform::GFx::Range *v11; // esi
  bool rangeStarted; // [esp+13h] [ebp-15h]
  unsigned __int16 rangeStart; // [esp+14h] [ebp-14h]
  Scaleform::GFx::Range range; // [esp+18h] [ebp-10h]
  Scaleform::GFx::Range rangea; // [esp+18h] [ebp-10h]
  Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> ranges; // [esp+1Ch] [ebp-Ch] BYREF

  GetGlyphShapeCount = font->GetGlyphShapeCount;
  Size = 0;
  v5 = 0;
  memset(&ranges, 0, sizeof(ranges));
  rangeStart = 0;
  rangeStarted = 0;
  v6 = 0;
  if ( !GetGlyphShapeCount(font) )
    goto LABEL_23;
  do
  {
    v7 = &font->CompactedFontValue.Decoder.Data->Data[8 * v6 + font->CompactedFontValue.GlyphInfoTablePos];
    if ( !rangeStarted )
    {
      rangeStart = *(_WORD *)v7;
      rangeStarted = 1;
LABEL_4:
      v5 = *(_WORD *)&font->CompactedFontValue.Decoder.Data->Data[8 * v6++ + font->CompactedFontValue.GlyphInfoTablePos];
      continue;
    }
    if ( v5 == (*v7 | (unsigned __int16)(v7[1] << 8)) - 1 )
      goto LABEL_4;
    v9 = Size + 1;
    rangea.start = rangeStart;
    rangea.end = v5;
    if ( v9 >= ranges.Data.Size )
    {
      if ( v9 >= ranges.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
          &ranges,
          v9 + (v9 >> 2));
    }
    else if ( v9 < ranges.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
        &ranges,
        v9);
    }
    ranges.Data.Size = v9;
    v10 = &ranges.Data.Data[v9 - 1];
    if ( v10 )
      *v10 = rangea;
    Size = ranges.Data.Size;
    rangeStarted = 0;
  }
  while ( v6 < font->GetGlyphShapeCount(font) );
  if ( rangeStarted )
  {
    v8 = Size + 1;
    range.start = rangeStart;
    range.end = v5;
    if ( Size + 1 >= Size )
    {
      if ( v8 >= ranges.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
          &ranges,
          v8 + (v8 >> 2));
    }
    else if ( v8 < ranges.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
        &ranges,
        Size + 1);
    }
    ranges.Data.Size = ++Size;
    v11 = &ranges.Data.Data[v8 - 1];
    if ( v11 )
      *v11 = range;
  }
LABEL_23:
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace'::Range,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace'::RangeLess>(
    &ranges,
    0,
    Size);
  Scaleform::GFx::BuildStringFromRanges(&ranges, a2);
  if ( ranges.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ranges.Data.Data);
  return a2;
}
