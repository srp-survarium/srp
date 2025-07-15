void __thiscall Scaleform::GFx::ResourceKey::ResourceKey(
        Scaleform::GFx::ResourceKey *this,
        const Scaleform::GFx::ResourceKey *src)
{
  if ( src->pKeyInterface )
    src->pKeyInterface->AddRef(src->pKeyInterface, src->hKeyData);
  *this = *src;
}


void __thiscall Scaleform::GFx::ResourceKey::ResourceKey(
        Scaleform::GFx::ResourceKey *this,
        Scaleform::GFx::ResourceKey::KeyInterface *pki,
        void *hk)
{
  if ( pki )
    pki->AddRef(pki, hk);
  this->pKeyInterface = pki;
  this->hKeyData = hk;
}


void __thiscall Scaleform::GFx::ResourceKey::ResourceKey(Scaleform::GFx::AS3::Value *this)
{
  this->Flags = 0;
  this->Bonus.pWeakProxy = 0;
}
