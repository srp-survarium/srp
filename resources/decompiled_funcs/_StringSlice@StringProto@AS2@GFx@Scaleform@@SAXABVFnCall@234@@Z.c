void __cdecl Scaleform::GFx::AS2::StringProto::StringSlice(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  const Scaleform::GFx::ASString *p_pProto; // ebp
  const char *v4; // edi
  int v5; // ebx
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  int v8; // ebx
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  int RefCount; // eax
  Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::AS2::Value *v14; // esi
  Scaleform::GFx::ASString *v15; // edi
  int pNode; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v19; // [esp-10h] [ebp-14h]

  v1 = fn;
  if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_String )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
    return;
  }
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
    v19 = v1->Env;
    v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
    v8 = (int)Scaleform::GFx::AS2::Value::ToNumber(v7, v19);
    if ( v8 < 0 )
      v8 += Scaleform::GFx::ASConstString::GetLength(&p_pProto[13].Scaleform::GFx::ASConstString);
    if ( v8 < (int)v4 )
    {
      pContext = v1->Env->StringContext.pContext;
      Result = v1->Result;
      pObject = pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 5;
      RefCount = pObject[8].RefCount;
      Result->NV.Int32Value = RefCount;
      ++*(_DWORD *)(RefCount + 12);
      return;
    }
    v5 = v8 - (_DWORD)v4;
  }
  v13 = Scaleform::GFx::AS2::StringProto::StringSubstring((Scaleform::GFx::ASString *)&fn, p_pProto + 13, v4, v5);
  v14 = v1->Result;
  v15 = v13;
  if ( v14->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v14);
  v14->T.Type = 5;
  pNode = (int)v15->pNode;
  v14->NV.Int32Value = (int)v15->pNode;
  ++*(_DWORD *)(pNode + 12);
  v17 = (Scaleform::GFx::ASStringNode *)fn;
  --fn->ThisFunctionRef.Function;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}
