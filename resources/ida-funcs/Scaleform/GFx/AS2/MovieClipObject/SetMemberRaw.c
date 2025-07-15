char __thiscall Scaleform::GFx::AS2::MovieClipObject::SetMemberRaw(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 16),
    psc,
    name,
    *(float *)&val);
  return Scaleform::GFx::AS2::Object::SetMemberRaw(this, psc, name, val, flags);
}
