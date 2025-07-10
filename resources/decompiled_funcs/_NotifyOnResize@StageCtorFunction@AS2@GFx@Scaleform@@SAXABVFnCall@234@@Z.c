void __cdecl Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Object *v2; // eax
  Scaleform::GFx::AS2::ObjectInterface *v3; // eax
  Scaleform::GFx::AS2::Value stageCtorVal; // [esp+Ch] [ebp-10h] BYREF

  Env = fn->Env;
  stageCtorVal.T.Type = 0;
  if ( Env->StringContext.pContext->pGlobal.pObject->GetMemberRaw(
         &Env->StringContext.pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         &Env->StringContext,
         (const Scaleform::GFx::ASString *)&Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[11].AVMVersion,
         &stageCtorVal)
    && stageCtorVal.T.Type != 11 )
  {
    v2 = Scaleform::GFx::AS2::Value::ToObject(&stageCtorVal, fn->Env);
    if ( v2 )
    {
      v3 = &v2->Scaleform::GFx::AS2::ObjectInterface;
      if ( v3 )
        Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(
          (Scaleform::GFx::AS2::StageCtorFunction *)&v3[-2].pProto,
          fn->Env);
    }
  }
  if ( stageCtorVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&stageCtorVal);
}
