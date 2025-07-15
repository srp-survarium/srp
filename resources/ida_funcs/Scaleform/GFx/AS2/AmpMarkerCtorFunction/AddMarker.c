void __cdecl Scaleform::GFx::AS2::AmpMarkerCtorFunction::AddMarker(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::ASStringNode *v4; // edi
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-14h]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 1;
  if ( v1->Env && v1->NArgs )
  {
    Env = v1->Env;
    v3 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
    v4 = (Scaleform::GFx::ASStringNode *)fn;
    Scaleform::GFx::AMP::ViewStats::AddMarker(
      v1->Env->Target->pASRoot->pMovieImpl->AdvanceStats.pObject,
      (char *)fn->__vftable);
    if ( v4->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  }
}
