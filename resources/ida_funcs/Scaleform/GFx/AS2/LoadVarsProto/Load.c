void __cdecl Scaleform::GFx::AS2::LoadVarsProto::Load(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *v2; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebx
  Scaleform::GFx::AS2::LoadVarsObject *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-18h]

  v1 = fn;
  if ( fn->NArgs )
  {
    if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_LoadVars )
    {
      ThisPtr = v1->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::GFx::AS2::LoadVarsObject *)&ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      Env = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v6 = (Scaleform::GFx::ASStringNode *)fn;
      p_pProto->BytesLoadedCurrent = 0.0;
      Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
        p_pProto,
        (char *)v6->pData,
        LM_None);
      Result = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 2;
      Result->V.BooleanValue = 1;
      if ( v6->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "LoadVars");
    }
  }
  else
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v2);
    v2->T.Type = 2;
    v2->V.BooleanValue = 0;
  }
}
