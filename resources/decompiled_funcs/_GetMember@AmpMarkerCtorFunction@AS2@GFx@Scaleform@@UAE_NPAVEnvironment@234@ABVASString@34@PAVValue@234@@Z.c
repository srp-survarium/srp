char __thiscall Scaleform::GFx::AS2::AmpMarkerCtorFunction::GetMember(
        Scaleform::GFx::AS2::AmpMarkerCtorFunction *this,
        Scaleform::GFx::AS2::Environment *env,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  const Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value v6; // [esp+4h] [ebp-10h] BYREF

  if ( strcmp(name->pNode->pData, "addMarker") )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::AmpMarkerCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             &env->StringContext,
             name,
             val);
  Scaleform::GFx::AS2::Value::Value(&v6, &env->StringContext, Scaleform::GFx::AS2::AmpMarkerCtorFunction::AddMarker);
  Scaleform::GFx::AS2::Value::operator=(val, v4);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  return 1;
}
