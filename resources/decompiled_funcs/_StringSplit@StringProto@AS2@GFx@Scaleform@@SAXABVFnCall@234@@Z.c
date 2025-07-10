void __cdecl Scaleform::GFx::AS2::StringProto::StringSplit(Scaleform::GFx::AS2::Object *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // esi
  const char *pData; // ebx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::ASStringNode *RefCount; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // ebx
  bool v7; // zf
  int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // ebx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v13; // [esp-8h] [ebp-14h]
  Scaleform::GFx::ASString result; // [esp+8h] [ebp-4h] BYREF

  v1 = (Scaleform::GFx::AS2::FnCall *)fn;
  pData = 0;
  if ( fn->RootIndex && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)fn->RootIndex + 8))(fn->RootIndex) == 8 )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      fn = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
    else
      fn = 0;
    RefCount = (Scaleform::GFx::ASStringNode *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    ++RefCount->RefCount;
    if ( v1->NArgs >= 1 )
    {
      Env = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v5, &result, Env, -1, 0);
      pNode = result.pNode;
      ++result.pNode->RefCount;
      v7 = RefCount->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
      v7 = pNode->RefCount-- == 1;
      RefCount = pNode;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      pData = pNode->pData;
    }
    v8 = 0x3FFFFFFF;
    if ( v1->NArgs >= 2 )
    {
      v13 = v1->Env;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v8 = (int)Scaleform::GFx::AS2::Value::ToNumber(v9, v13);
      if ( v8 < 0 )
        v8 = 0;
    }
    Scaleform::GFx::AS2::StringProto::StringSplit(
      (Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *)&fn,
      v1->Env,
      (const Scaleform::GFx::ASString *)&fn[1],
      pData,
      (Scaleform::String)v8);
    v10 = fn;
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, fn);
    if ( v10 )
    {
      v11 = v10->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v11) != 0 )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    v7 = RefCount->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
