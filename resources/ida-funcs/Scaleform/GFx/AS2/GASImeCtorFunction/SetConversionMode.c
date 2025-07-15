void __cdecl Scaleform::GFx::AS2::GASImeCtorFunction::SetConversionMode(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::MovieImpl *MovieImpl; // eax
  Scaleform::RefCountVImpl *v3; // eax
  Scaleform::RefCountVImpl *v4; // esi
  char v5; // bl
  Scaleform::RefCountVImpl_vtbl *v6; // edi
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *v9; // [esp-10h] [ebp-1Ch]
  __int64 v10; // [esp+4h] [ebp-8h]

  Env = fn->Env;
  if ( Env )
  {
    MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(Env);
    v3 = (Scaleform::RefCountVImpl *)MovieImpl->GetStateAddRef(&MovieImpl->Scaleform::GFx::StateBag, State_IMEManager);
    v4 = v3;
    v5 = 0;
    if ( v3 )
    {
      v9 = fn->Env;
      v6 = v3->__vftable + 2;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v10 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v7, v9);
      v5 = ((int (__thiscall *)(Scaleform::RefCountVImpl *, _DWORD))v6->~Scaleform::RefCountVImpl)(v4, v10);
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v5;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
