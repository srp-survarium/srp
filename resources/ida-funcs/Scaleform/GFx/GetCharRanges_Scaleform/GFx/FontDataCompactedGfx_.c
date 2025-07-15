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
  Scaleform::GFx::AS3::Instances::fl::Object **v10; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v11; // esi
  char v13; // [esp+13h] [ebp-15h]
  __int16 v14; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::Instances::fl::Object *v15; // [esp+18h] [ebp-10h]
  Scaleform::GFx::AS3::Instances::fl::Object *v16; // [esp+18h] [ebp-10h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+1Ch] [ebp-Ch] BYREF

  GetGlyphShapeCount = font->GetGlyphShapeCount;
  Size = 0;
  v5 = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  v14 = 0;
  v13 = 0;
  v6 = 0;
  if ( !GetGlyphShapeCount(font) )
    goto LABEL_23;
  do
  {
    v7 = &font->CompactedFontValue.Decoder.Data->Data[8 * v6 + font->CompactedFontValue.GlyphInfoTablePos];
    if ( !v13 )
    {
      v14 = *(_WORD *)v7;
      v13 = 1;
LABEL_4:
      v5 = *(_WORD *)&font->CompactedFontValue.Decoder.Data->Data[8 * v6++ + font->CompactedFontValue.GlyphInfoTablePos];
      continue;
    }
    if ( v5 == (*v7 | (unsigned __int16)(v7[1] << 8)) - 1 )
      goto LABEL_4;
    v9 = Size + 1;
    LOWORD(v16) = v14;
    HIWORD(v16) = v5;
    if ( v9 >= pheapAddr.Size )
    {
      if ( v9 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v9 + (v9 >> 2));
    }
    else if ( v9 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v9);
    }
    pheapAddr.Size = v9;
    v10 = &pheapAddr.Data[v9 - 1];
    if ( v10 )
      *v10 = v16;
    Size = pheapAddr.Size;
    v13 = 0;
  }
  while ( v6 < font->GetGlyphShapeCount(font) );
  if ( v13 )
  {
    v8 = Size + 1;
    LOWORD(v15) = v14;
    HIWORD(v15) = v5;
    if ( Size + 1 >= Size )
    {
      if ( v8 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v8 + (v8 >> 2));
    }
    else if ( v8 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        Size + 1);
    }
    pheapAddr.Size = ++Size;
    v11 = &pheapAddr.Data[v8 - 1];
    if ( v11 )
      *v11 = v15;
  }
LABEL_23:
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace'::Range,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace'::RangeLess>(
    (Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    0,
    Size);
  Scaleform::GFx::BuildStringFromRanges(
    (const Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    a2);
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
  return a2;
}
