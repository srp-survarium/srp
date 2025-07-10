bool __thiscall Scaleform::GFx::AS2::AvmSprite::GetMember(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  return Scaleform::GFx::AS2::AvmSprite::GetMember(
           (Scaleform::GFx::AS2::AvmSprite *)((char *)this - 4),
           penv,
           0,
           name,
           pval);
}
