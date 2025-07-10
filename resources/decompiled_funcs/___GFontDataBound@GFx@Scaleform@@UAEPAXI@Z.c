Scaleform::GFx::FontDataBound *__thiscall Scaleform::GFx::FontDataBound::`scalar deleting destructor'(
        Scaleform::GFx::FontDataBound *this,
        char a2)
{
  Scaleform::GFx::TextureGlyphData *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  pObject = this->pTGData.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pFont.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->__vftable = (Scaleform::GFx::FontDataBound_vtbl *)&Scaleform::Render::Font::`vftable';
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
