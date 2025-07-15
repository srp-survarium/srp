void __cdecl Scaleform::GFx::AS2::StringProto::StringSubstring(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  const Scaleform::GFx::ASString *p_pProto; // ebp
  const char *v4; // esi
  int v5; // ebx
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  int v8; // ebx
  const char *v9; // eax
  Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASString *v12; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-14h]
  Scaleform::GFx::AS2::Environment *v16; // [esp-10h] [ebp-14h]

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
  }
  if ( v1->NArgs >= 2 )
  {
    v16 = v1->Env;
    v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
    v8 = (int)Scaleform::GFx::AS2::Value::ToNumber(v7, v16);
    if ( v8 < (int)v4 )
    {
      if ( (int)v4 >= (int)Scaleform::GFx::ASConstString::GetLength(&p_pProto[13].Scaleform::GFx::ASConstString) )
      {
        Scaleform::GFx::AS2::Value::SetString(
          v1->Result,
          (const Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount);
        return;
      }
      v9 = v4;
      v4 = (const char *)v8;
      v8 = (int)v9;
    }
    if ( (int)v4 < 0 )
      v4 = 0;
    v5 = v8 - (_DWORD)v4;
  }
  v10 = Scaleform::GFx::AS2::StringProto::StringSubstring((Scaleform::GFx::ASString *)&fn, p_pProto + 13, v4, v5);
  Result = v1->Result;
  v12 = v10;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
  Result->T.Type = 5;
  pNode = v12->pNode;
  Result->NV.Int32Value = (int)v12->pNode;
  ++pNode->RefCount;
  v14 = (Scaleform::GFx::ASStringNode *)fn;
  --fn->ThisFunctionRef.Function;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}


Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS2::StringProto::StringSubstring(
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *self,
        const char *start,
        int length)
{
  int v4; // edi
  Scaleform::GFx::ASStringManager *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // ecx
  Scaleform::GFx::ASString *v7; // eax
  const char *v8; // esi
  signed int v9; // eax
  Scaleform::GFx::ASStringManager *pManager; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // ecx
  Scaleform::GFx::ASStringNode *v12; // eax

  v4 = length;
  if ( length )
  {
    v8 = start;
    if ( (int)start < 0 )
      v8 = 0;
    v9 = Scaleform::GFx::ASConstString::GetLength(&self->Scaleform::GFx::ASConstString);
    if ( (int)v8 < v9 )
    {
      if ( length < 0 || (int)&v8[length] > v9 )
        v4 = v9 - (_DWORD)v8;
      v12 = Scaleform::GFx::ASConstString::SubstringNode(&self->Scaleform::GFx::ASConstString, v8, &v8[v4]);
      ++v12->RefCount;
      result->pNode = v12;
      return result;
    }
    else
    {
      pManager = self->pNode->pManager;
      ++pManager->EmptyStringNode.RefCount;
      p_EmptyStringNode = &pManager->EmptyStringNode;
      v7 = result;
      result->pNode = p_EmptyStringNode;
    }
  }
  else
  {
    v5 = self->pNode->pManager;
    ++v5->EmptyStringNode.RefCount;
    v6 = &v5->EmptyStringNode;
    v7 = result;
    result->pNode = v6;
  }
  return v7;
}
