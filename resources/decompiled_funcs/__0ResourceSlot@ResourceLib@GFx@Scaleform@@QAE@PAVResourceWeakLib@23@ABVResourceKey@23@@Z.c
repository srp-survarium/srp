void __thiscall Scaleform::GFx::ResourceLib::ResourceSlot::ResourceSlot(
        Scaleform::GFx::ResourceLib::ResourceSlot *this,
        Scaleform::GFx::Resource *plib,
        const Scaleform::GFx::ResourceKey *key)
{
  Scaleform::GFx::ResourceWeakLib *pObject; // ecx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx

  this->__vftable = (Scaleform::GFx::ResourceLib::ResourceSlot_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ResourceLib::ResourceSlot_vtbl *)&Scaleform::GFx::ResourceLib::ResourceSlot::`vftable';
  this->pLib.pObject = 0;
  this->Key.pKeyInterface = 0;
  this->Key.hKeyData = 0;
  Scaleform::String::String(&this->ErrorMessage);
  Scaleform::Event::Event(&this->ResolveComplete, 0, 0);
  if ( plib )
    Scaleform::RefCountImpl::AddRef(plib);
  pObject = this->pLib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->pLib.pObject = (Scaleform::GFx::ResourceWeakLib *)plib;
  this->State = Resolve_InProgress;
  this->pResource = 0;
  if ( key->pKeyInterface )
    key->pKeyInterface->AddRef(key->pKeyInterface, key->hKeyData);
  pKeyInterface = this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->Release(pKeyInterface, this->Key.hKeyData);
  this->Key = *key;
}
