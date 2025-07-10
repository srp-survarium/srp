Scaleform::Render::Font *__thiscall Scaleform::Render::FontProviderWinAPI::CreateFontA(
        Scaleform::Render::FontProviderWinAPI *this,
        const char *name,
        __int16 fontFlags)
{
  Scaleform::Render::ExternalFontWinAPI *v4; // eax
  Scaleform::RefCountVImpl *v5; // eax
  _DWORD *v6; // esi
  Scaleform::Render::Font::NativeHintingType *NativeHinting; // eax
  Scaleform::Render::Font::NativeHintingType *Data; // edi
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v10 = 79;
  v4 = (Scaleform::Render::ExternalFontWinAPI *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  128,
                                                  &v10);
  if ( v4 )
  {
    Scaleform::Render::ExternalFontWinAPI::ExternalFontWinAPI(
      v4,
      (Scaleform::GFx::Resource *)this,
      &this->SysData,
      name,
      fontFlags & 0x303 | 0x30,
      &this->FontLock);
    v6 = &v5->__vftable;
    if ( v5 && !v5[8].RefCount )
    {
      Scaleform::RefCountImpl::Release(v5);
      return 0;
    }
  }
  else
  {
    v6 = 0;
  }
  NativeHinting = Scaleform::Render::FontProviderWinAPI::findNativeHinting(this, name);
  if ( NativeHinting )
  {
    v6[29] = NativeHinting->MaxRasterHintedSize;
    v6[30] = NativeHinting->MaxVectorHintedSize;
    v6[27] = NativeHinting->RasterRange;
    v6[28] = NativeHinting->VectorRange;
  }
  else
  {
    Data = this->NativeHinting.Data.Data;
    v6[29] = Data->MaxRasterHintedSize;
    v6[30] = Data->MaxVectorHintedSize;
    v6[27] = Data->RasterRange;
    v6[28] = Data->VectorRange;
  }
  return (Scaleform::Render::Font *)v6;
}
