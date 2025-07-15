void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::GetEnabled(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  int v3; // eax
  Scaleform::RefCountVImpl *v4; // esi
  char v5; // al
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v7; // bl

  Env = fn->Env;
  if ( Env )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(Env);
    v3 = (int)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    v4 = (Scaleform::RefCountVImpl *)v3;
    if ( v3 )
    {
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 36))(v3);
      Result = fn->Result;
      v7 = v5;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->V.BooleanValue = v7;
      Result->T.Type = 2;
      Scaleform::RefCountImpl::Release(v4);
    }
  }
}
