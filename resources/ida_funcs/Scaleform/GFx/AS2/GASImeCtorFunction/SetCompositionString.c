void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::SetCompositionString(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  Scaleform::RefCountVImpl *v4; // esi
  char v5; // bl
  Scaleform::GFx::AS2::Environment *v6; // ebx
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS2::Value *Result; // edi

  v1 = fn;
  Env = fn->Env;
  if ( Env )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(Env);
    v4 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    v5 = 0;
    if ( v4 )
    {
      v6 = v1->Env;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v7, (Scaleform::GFx::ASString *)&fn, v6, -1, 0);
      v5 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::AS2::FnCall_vtbl *))v4->__vftable[7].~Scaleform::RefCountVImpl)(
             v4,
             fn->__vftable);
      v8 = (Scaleform::GFx::ASStringNode *)fn;
      --fn->ThisFunctionRef.Function;
      if ( !v8->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    Result = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v5;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
