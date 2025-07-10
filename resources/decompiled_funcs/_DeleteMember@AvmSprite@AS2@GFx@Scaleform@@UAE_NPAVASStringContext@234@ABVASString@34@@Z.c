bool __thiscall Scaleform::GFx::AS2::AvmSprite::DeleteMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  return Scaleform::GFx::AS2::AvmCharacter::DeleteMember(this, psc, name) != 0;
}
