void __cdecl Scaleform::GFx::AS2::StringProto::StringSubstr(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  const Scaleform::GFx::ASString *p_pProto; // ebp
  const char *v4; // ebx
  int v5; // edi
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::ASString *v8; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASString *v10; // edi
  int pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v14; // [esp-10h] [ebp-14h]

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = (const Scaleform::GFx::ASString *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v4 = 0;
    v5 = -1;
    if ( v1->NArgs >= 1 )
    {
      Env = v1->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v4 = (const char *)(int)Scaleform::GFx::AS2::Value::ToNumber(v6, Env);
      if ( (int)v4 < 0 )
        v4 += Scaleform::GFx::ASConstString::GetLength(&p_pProto[13].Scaleform::GFx::ASConstString);
    }
    if ( v1->NArgs >= 2 )
    {
      v14 = v1->Env;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v7, v14);
      if ( v5 < 0 )
        v5 = 0;
    }
    v8 = Scaleform::GFx::AS2::StringProto::StringSubstring((Scaleform::GFx::ASString *)&fn, p_pProto + 13, v4, v5);
    Result = v1->Result;
    v10 = v8;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    pNode = (int)v10->pNode;
    Result->NV.Int32Value = (int)v10->pNode;
    ++*(_DWORD *)(pNode + 12);
    v12 = (Scaleform::GFx::ASStringNode *)fn;
    --fn->ThisFunctionRef.Function;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
