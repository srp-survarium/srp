void __thiscall Scaleform::Render::FontProviderWinAPI::~FontProviderWinAPI(Scaleform::Render::FontProviderWinAPI *this)
{
  this->__vftable = (Scaleform::Render::FontProviderWinAPI_vtbl *)&Scaleform::Render::FontProviderWinAPI::`vftable';
  Scaleform::Lock::~Lock(&this->FontLock);
  Scaleform::ConstructorMov<Scaleform::Render::Font::NativeHintingType>::DestructArray(
    this->NativeHinting.Data.Data,
    this->NativeHinting.Data.Size);
  if ( this->NativeHinting.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->NativeHinting.Data.Data);
  if ( this->SysData.GlyphBuffer.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->SysData.GlyphBuffer.Data.Data);
  this->__vftable = (Scaleform::Render::FontProviderWinAPI_vtbl *)&Scaleform::GFx::AS2::ASCSSFileLoader::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
