void __cdecl Scaleform::GFx::AS2::MouseCtorFunction::Show(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::UserEventHandler *pObject; // ecx
  Scaleform::GFx::AS2::Environment *v7; // [esp-4h] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-10h] BYREF
  char v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  unsigned int v11; // [esp+14h] [ebp-4h]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( pMovieImpl->pUserEventHandler.pObject )
  {
    v4 = 0;
    if ( fn->NArgs >= 1 )
    {
      v7 = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToUInt32(v5, v7);
    }
    pObject = pMovieImpl->pUserEventHandler.pObject;
    v11 = v4;
    v9 = 0;
    v8 = 21;
    v10 = 0;
    pObject->HandleEvent(pObject, pMovieImpl, (const Scaleform::GFx::Event *)&v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptWarning(
      Env,
      "No user event handler interface is installed; Mouse.show failed.");
  }
}
