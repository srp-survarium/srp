void __cdecl Scaleform::GFx::AS2::LoadVarsProto::ToString(Scaleform::String fn)
{
  const Scaleform::GFx::AS2::FnCall *pData; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  int Length; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v8; // zf
  void *v9; // esi
  Scaleform::GFx::AS2::LoadVarsProto::ToString::__l7::MemberVisitor visitor; // [esp+10h] [ebp-Ch] BYREF

  pData = (const Scaleform::GFx::AS2::FnCall *)fn.pData;
  if ( *(_DWORD *)fn.pData->Data
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 27 )
  {
    ThisPtr = pData->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Scaleform::String::String(&fn);
    Env = pData->Env;
    visitor.pString = &fn;
    visitor.pEnvironment = Env;
    visitor.__vftable = (Scaleform::GFx::AS2::LoadVarsProto::ToString::__l7::MemberVisitor_vtbl *)&`Scaleform::GFx::AS2::LoadVarsProto::ToString'::`7'::MemberVisitor::`vftable';
    ((void (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::LoadVarsProto::ToString::__l7::MemberVisitor *, _DWORD, _DWORD))p_pProto[4].pObject->ResolveHandler.Function)(
      &p_pProto[4],
      &Env->StringContext,
      &visitor,
      0,
      0);
    Length = Scaleform::String::GetLength(&fn);
    Scaleform::String::Remove(&fn, Length - 1, 1);
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
    v8 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v9 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
    visitor.__vftable = (Scaleform::GFx::AS2::LoadVarsProto::ToString::__l7::MemberVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      pData->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}
