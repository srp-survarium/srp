void __cdecl Scaleform::GFx::AS2::StringProto::StringCharAt(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::ASConstString *p_pProto; // ebx
  Scaleform::GFx::AS2::Environment *Env; // eax
  int v5; // esi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // eax
  Scaleform::GFx::ASConstString *v7; // ebx
  Scaleform::GFx::AS2::Value *v8; // ecx
  char *v9; // esi
  unsigned int CharAt; // eax
  const Scaleform::GFx::AS2::FnCall *appended; // esi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::ASStringNode *v15; // eax

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::ASConstString *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    fn = (const Scaleform::GFx::AS2::FnCall *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    ++fn->ThisFunctionRef.Function;
    Env = v1->Env;
    v5 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
    p_Stack = &Env->Stack;
    v7 = p_pProto + 13;
    v8 = 0;
    if ( v1->FirstArgBottomIndex <= 32 * (p_Stack->Pages.Data.Size - 1) + (v5 >> 4) )
      v8 = &p_Stack->Pages.Data.Data[(unsigned int)v1->FirstArgBottomIndex >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
    v9 = (char *)(int)Scaleform::GFx::AS2::Value::ToNumber(v8, v1->Env);
    if ( (int)v9 >= 0 && (int)v9 < (int)Scaleform::GFx::ASConstString::GetLength(v7) )
    {
      CharAt = Scaleform::GFx::ASConstString::GetCharAt(v7, v9);
      appended = (const Scaleform::GFx::AS2::FnCall *)Scaleform::GFx::ASConstString::AppendCharNode(
                                                        (Scaleform::GFx::ASConstString *)&fn,
                                                        CharAt);
      appended->ThisFunctionRef.Function = (Scaleform::GFx::AS2::FunctionObject *)((char *)appended->ThisFunctionRef.Function
                                                                                 + 2);
      v12 = (Scaleform::GFx::ASStringNode *)fn;
      --fn->ThisFunctionRef.Function;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      fn = appended;
      if ( appended->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)appended);
    }
    Result = v1->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)fn;
    ++fn->ThisFunctionRef.Function;
    v15 = (Scaleform::GFx::ASStringNode *)fn;
    --fn->ThisFunctionRef.Function;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
