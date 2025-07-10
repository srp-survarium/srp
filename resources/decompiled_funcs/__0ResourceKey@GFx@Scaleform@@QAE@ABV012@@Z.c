void __thiscall Scaleform::GFx::ResourceKey::ResourceKey(
        Scaleform::GFx::ResourceKey *this,
        const Scaleform::GFx::ResourceKey *src)
{
  if ( src->pKeyInterface )
    src->pKeyInterface->AddRef(src->pKeyInterface, src->hKeyData);
  *this = *src;
}
