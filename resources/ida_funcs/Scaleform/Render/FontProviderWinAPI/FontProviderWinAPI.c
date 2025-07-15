void __thiscall Scaleform::Render::FontProviderWinAPI::FontProviderWinAPI(
        Scaleform::Render::FontProviderWinAPI *this,
        HDC__ *dc)
{
  Scaleform::Array<Scaleform::Render::Font::NativeHintingType,2,Scaleform::ArrayDefaultPolicy> *p_NativeHinting; // edi
  Scaleform::String *p_Typeface; // edi
  void *v4; // edi
  unsigned int v5; // [esp-4h] [ebp-24h]
  Scaleform::Render::Font::NativeHintingType nhAllFonts; // [esp+Ch] [ebp-14h] BYREF

  this->__vftable = (Scaleform::Render::FontProviderWinAPI_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::FontProviderWinAPI_vtbl *)&Scaleform::Render::FontProviderWinAPI::`vftable';
  this->SysData.GlyphBuffer.Data.Data = 0;
  this->SysData.GlyphBuffer.Data.Size = 0;
  this->SysData.GlyphBuffer.Data.Policy.Capacity = 0;
  this->SysData.WinHDC = dc;
  p_NativeHinting = &this->NativeHinting;
  this->NativeHinting.Data.Data = 0;
  this->NativeHinting.Data.Size = 0;
  this->NativeHinting.Data.Policy.Capacity = 0;
  Scaleform::Lock::Lock(&this->FontLock, 0);
  Scaleform::String::String(&nhAllFonts.Typeface);
  v5 = p_NativeHinting->Data.Size + 1;
  nhAllFonts.RasterRange = HintCJK;
  nhAllFonts.VectorRange = DontHint;
  nhAllFonts.MaxRasterHintedSize = 24;
  nhAllFonts.MaxVectorHintedSize = 24;
  Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_NativeHinting->Data,
    p_NativeHinting,
    v5);
  p_Typeface = &p_NativeHinting->Data.Data[p_NativeHinting->Data.Size - 1].Typeface;
  if ( p_Typeface )
  {
    Scaleform::String::String(p_Typeface, &nhAllFonts.Typeface);
    p_Typeface[1].pData = (Scaleform::String::DataDesc *)nhAllFonts.RasterRange;
    p_Typeface[2].pData = (Scaleform::String::DataDesc *)nhAllFonts.VectorRange;
    p_Typeface[3].pData = (Scaleform::String::DataDesc *)nhAllFonts.MaxRasterHintedSize;
    p_Typeface[4].pData = (Scaleform::String::DataDesc *)nhAllFonts.MaxVectorHintedSize;
  }
  v4 = (void *)(nhAllFonts.Typeface.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((nhAllFonts.Typeface.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
}
