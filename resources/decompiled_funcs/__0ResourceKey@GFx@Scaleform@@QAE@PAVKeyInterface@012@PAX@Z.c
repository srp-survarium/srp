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
