void __thiscall Scaleform::GFx::FontDataCompactedGfx::~FontDataCompactedGfx(Scaleform::GFx::FontDataCompactedGfx *this)
{
  Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *p_CompactedFontValue; // edi
  char *Data; // eax

  p_CompactedFontValue = &this->CompactedFontValue;
  this->__vftable = (Scaleform::GFx::FontDataCompactedGfx_vtbl *)&Scaleform::GFx::FontDataCompactedGfx::`vftable';
  Data = this->CompactedFontValue.Name.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(p_CompactedFontValue);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Container.Data);
  this->__vftable = (Scaleform::GFx::FontDataCompactedGfx_vtbl *)&Scaleform::Render::Font::`vftable';
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
