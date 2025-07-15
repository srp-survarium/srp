void __cdecl Scaleform::GFx::AS2::RectangleProto::ToString(Scaleform::String fn)
{
  const Scaleform::GFx::AS2::FnCall *pData; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // edi
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v6; // zf
  void *v7; // esi
  Scaleform::GFx::ASString ps[4]; // [esp+4h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value params[4]; // [esp+14h] [ebp-40h] BYREF

  pData = (const Scaleform::GFx::AS2::FnCall *)fn.pData;
  if ( *(_DWORD *)fn.pData->Data
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 17 )
  {
    ThisPtr = pData->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        `vector constructor iterator'(
          (char *)params,
          0x10u,
          4,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, &pData->Env->StringContext, params);
        Scaleform::GFx::AS2::Value::ToStringImpl(params, ps, pData->Env, 6, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(&params[1], &ps[1], pData->Env, 6, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(&params[2], &ps[2], pData->Env, 6, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(&params[3], &ps[3], pData->Env, 6, 0);
        Scaleform::String::String(&fn);
        Scaleform::String::AppendString(&fn, "(x=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (char *)ps[0].pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, ", y=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (char *)ps[1].pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, ", width=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (char *)ps[2].pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, ", height=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, (char *)ps[3].pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&fn, ")", 0xFFFFFFFF);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)pData->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       (char *)((fn.HeapTypeBits & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(fn.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        Result = pData->Result;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 5;
        Result->NV.Int32Value = (int)StringNode;
        v6 = ++StringNode->RefCount == 1;
        --StringNode->RefCount;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        v7 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
        `vector destructor iterator'(
          (char *)ps,
          4u,
          4,
          (void (__thiscall *)(void *))Scaleform::GFx::ASString::~ASString);
        `vector destructor iterator'(
          (char *)params,
          0x10u,
          4,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      pData->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}
