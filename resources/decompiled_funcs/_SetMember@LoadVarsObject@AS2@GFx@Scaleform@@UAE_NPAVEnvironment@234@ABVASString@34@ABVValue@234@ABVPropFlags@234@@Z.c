char __thiscall Scaleform::GFx::AS2::LoadVarsObject::SetMember(
        Scaleform::GFx::AS2::LoadVarsObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  const Scaleform::GFx::ASString *v5; // edi

  v5 = name;
  Scaleform::GFx::AS2::Object::SetMemberFlags(this, &penv->StringContext, name, 0);
  LOBYTE(name) = 0;
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, v5, val, (const Scaleform::GFx::AS2::PropFlags *)&name);
}
