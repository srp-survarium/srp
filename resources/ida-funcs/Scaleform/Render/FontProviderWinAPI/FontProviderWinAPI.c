void __thiscall Scaleform::Render::FontProviderWinAPI::FontProviderWinAPI(
        Scaleform::Render::FontProviderWinAPI *this,
        HDC__ *dc)
{
  Scaleform::Array<Scaleform::Render::Font::NativeHintingType,2,Scaleform::ArrayDefaultPolicy> *p_NativeHinting; // edi
  Scaleform::String *p_Typeface; // edi
  void *v4; // edi
  unsigned int v5; // [esp-4h] [ebp-24h]
  Scaleform::String src; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+10h] [ebp-10h]
  unsigned int v8; // [esp+14h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-8h]
  int v10; // [esp+1Ch] [ebp-4h]

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
  Scaleform::String::String(&src);
  v5 = p_NativeHinting->Data.Size + 1;
  v7 = 1;
  v8 = 0;
  v9 = 24;
  v10 = 24;
  Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_NativeHinting->Data,
    p_NativeHinting,
    v5);
  p_Typeface = &p_NativeHinting->Data.Data[p_NativeHinting->Data.Size - 1].Typeface;
  if ( p_Typeface )
  {
    Scaleform::String::String(p_Typeface, &src);
    p_Typeface[1].HeapTypeBits = v7;
    p_Typeface[2].HeapTypeBits = v8;
    p_Typeface[3].HeapTypeBits = v9;
    p_Typeface[4].HeapTypeBits = v10;
  }
  v4 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
}
