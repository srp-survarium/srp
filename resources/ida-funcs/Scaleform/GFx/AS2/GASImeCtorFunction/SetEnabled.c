void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::SetEnabled(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  Scaleform::RefCountVImpl *v3; // eax
  Scaleform::RefCountVImpl *v4; // esi
  char v5; // bl
  int (__thiscall **p_Release)(Scaleform::RefCountVImpl *, bool); // edi
  Scaleform::GFx::AS2::Value *v7; // eax
  bool v8; // al
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *v10; // [esp-10h] [ebp-14h]

  Env = fn->Env;
  if ( Env )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(Env);
    v3 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    v4 = v3;
    v5 = 0;
    if ( v3 )
    {
      v10 = fn->Env;
      p_Release = (int (__thiscall **)(Scaleform::RefCountVImpl *, bool))&v3->__vftable[2].Release;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v8 = Scaleform::GFx::AS2::Value::ToBool(v7, (int)p_Release, v10);
      v5 = (*p_Release)(v4, v8);
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v5;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
