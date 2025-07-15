char __thiscall Scaleform::GFx::AS2::AmpMarkerCtorFunction::SetMember(
        Scaleform::GFx::AS2::AmpMarkerCtorFunction *this,
        Scaleform::GFx::AS2::Environment *env,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::ASStringNode *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::ASStringNode *v6; // esi

  pMovieImpl = env->Target->pASRoot->pMovieImpl;
  if ( strcmp(name->pNode->pData, "addMarker") )
    return Scaleform::GFx::AS2::Object::SetMember(this, env, name, (Scaleform::GFx::AS2::Value *)val, flags);
  Scaleform::GFx::AS2::Value::ToStringImpl(
    (Scaleform::GFx::AS2::Value *)val,
    (Scaleform::GFx::ASString *)&val,
    env,
    -1,
    0);
  v6 = val;
  Scaleform::GFx::AMP::ViewStats::AddMarker(pMovieImpl->AdvanceStats.pObject, (Scaleform::String)val->pData);
  if ( v6->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return 1;
}
