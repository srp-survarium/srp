Scaleform::GFx::FontResource *__thiscall Scaleform::GFx::FontResource::`vector deleting destructor'(
        Scaleform::GFx::FontResource *this,
        char a2)
{
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx

  this->__vftable = (Scaleform::GFx::FontResource_vtbl *)&Scaleform::GFx::FontResource::`vftable';
  pKeyInterface = this->FontKey.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->Release(pKeyInterface, this->FontKey.hKeyData);
  pObject = (Scaleform::RefCountVImpl *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::FontResource_vtbl *)&Scaleform::GFx::Resource::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
