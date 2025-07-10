Scaleform::GFx::ResourceKey *__thiscall Scaleform::GFx::ResourceKey::operator=(
        Scaleform::GFx::ResourceKey *this,
        const Scaleform::GFx::ResourceKey *src)
{
  if ( src->pKeyInterface )
    src->pKeyInterface->AddRef(src->pKeyInterface, src->hKeyData);
  if ( this->pKeyInterface )
    this->pKeyInterface->Release(this->pKeyInterface, this->hKeyData);
  *this = *src;
  return this;
}
