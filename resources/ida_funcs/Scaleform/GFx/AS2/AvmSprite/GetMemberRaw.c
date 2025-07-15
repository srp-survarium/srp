bool __thiscall Scaleform::GFx::AS2::AvmSprite::GetMemberRaw(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMember(
           (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 4),
           0,
           psc,
           name,
           pval);
}
