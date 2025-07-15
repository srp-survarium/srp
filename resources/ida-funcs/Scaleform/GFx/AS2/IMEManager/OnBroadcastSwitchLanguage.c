void __cdecl Scaleform::GFx::AS2::IMEManager::OnBroadcastSwitchLanguage(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::ASStringNode *v4; // eax

  v1 = fn;
  Env = fn->Env;
  if ( Env )
  {
    v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
    Scaleform::GFx::AS2::GASIme::BroadcastOnSwitchLanguage(
      (Scaleform::GFx::ASStringNode *)v1->Env,
      (const Scaleform::GFx::ASString *)&fn);
    v4 = (Scaleform::GFx::ASStringNode *)fn;
    --fn->ThisFunctionRef.Function;
    if ( !v4->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  }
}
