Scaleform::GFx::FontDataCompactedSwf *__thiscall Scaleform::GFx::FontDataCompactedSwf::`vector deleting destructor'(
        Scaleform::GFx::FontDataCompactedSwf *this,
        char a2)
{
  Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_CompactedFontValue; // edi
  char *Data; // eax

  p_CompactedFontValue = &this->CompactedFontValue;
  this->__vftable = (Scaleform::GFx::FontDataCompactedSwf_vtbl *)&Scaleform::GFx::FontDataCompactedSwf::`vftable';
  Data = this->CompactedFontValue.Name.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(p_CompactedFontValue);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->Container);
  this->__vftable = (Scaleform::GFx::FontDataCompactedSwf_vtbl *)&Scaleform::Render::Font::`vftable';
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
