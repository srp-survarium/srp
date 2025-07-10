Scaleform::GFx::FontProviderWin32 *__thiscall Scaleform::GFx::FontProviderWin32::`scalar deleting destructor'(
        Scaleform::GFx::FontProviderWin32 *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::FontProviderWin32_vtbl *)&Scaleform::GFx::FontProvider::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pFontProvider.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::FontProviderWin32_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
