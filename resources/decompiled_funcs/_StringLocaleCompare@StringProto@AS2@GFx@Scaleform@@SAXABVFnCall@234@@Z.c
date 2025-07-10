void __cdecl Scaleform::GFx::AS2::StringProto::StringLocaleCompare(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::ASConstString *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::FnCall_vtbl *v7; // edi
  unsigned int Length; // eax
  int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // esi
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-1Ch]
  const Scaleform::GFx::AS2::Environment *v13; // [esp-8h] [ebp-14h]
  bool caseSensitive; // [esp+8h] [ebp-4h]
  int caseSensitivea; // [esp+8h] [ebp-4h]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( v1->Env->StringContext.pContext->GFxExtensions.Value == 1 )
  {
    if ( v1->ThisPtr && v1->ThisPtr->GetObjectType(v1->ThisPtr) == Object_String )
    {
      ThisPtr = v1->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::GFx::ASConstString *)&ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      if ( v1->NArgs >= 1 )
      {
        Env = v1->Env;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
        caseSensitive = 1;
        if ( v1->NArgs >= 2 )
        {
          v13 = v1->Env;
          v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          caseSensitive = Scaleform::GFx::AS2::Value::ToBool(v6, v13) == 0;
        }
        v7 = fn->__vftable;
        Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&fn);
        v9 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
               p_pProto + 13,
               (const char *)v7,
               Length,
               caseSensitive);
        v10 = v1->Result;
        caseSensitivea = v9;
        if ( v10->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v10);
        v10->T.Type = 3;
        v10->NV.NumberValue = (double)caseSensitivea;
        v11 = (Scaleform::GFx::ASStringNode *)fn;
        --fn->ThisFunctionRef.Function;
        if ( !v11->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      }
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "String");
    }
  }
}
