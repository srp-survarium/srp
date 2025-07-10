char __thiscall Scaleform::GFx::AS2::MovieClipObject::SetMember(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(
    (Scaleform::GFx::AS2::MovieClipObject *)((char *)this - 16),
    &penv->StringContext,
    name,
    val);
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
}
