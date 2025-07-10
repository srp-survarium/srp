void __thiscall Scaleform::GFx::ResourceKey::~ResourceKey(Scaleform::GFx::ResourceKey *this)
{
  if ( this->pKeyInterface )
    this->pKeyInterface->Release(this->pKeyInterface, this->hKeyData);
}
