bool __thiscall Scaleform::GFx::GFxSystemFontResourceKeyInterface::KeyEquals(
        Scaleform::GFx::GFxSystemFontResourceKeyInterface *this,
        Scaleform::GFx::GFxSystemFontResourceKey *hdata,
        const Scaleform::GFx::ResourceKey *other)
{
  return this == other->pKeyInterface
      && Scaleform::GFx::GFxSystemFontResourceKey::operator==(
           hdata,
           (Scaleform::GFx::GFxSystemFontResourceKey *)other->hKeyData);
}
