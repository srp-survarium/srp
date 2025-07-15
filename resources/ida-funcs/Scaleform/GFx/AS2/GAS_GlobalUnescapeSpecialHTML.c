void __cdecl Scaleform::GFx::AS2::GAS_GlobalUnescapeSpecialHTML(Scaleform::String fn)
{
  const Scaleform::GFx::AS2::FnCall *pData; // edi
  Scaleform::GFx::AS2::Value *RefCount; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  const char *v5; // esi
  unsigned int Length; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v9; // zf
  void *v10; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString str; // [esp+8h] [ebp-4h] BYREF

  pData = (const Scaleform::GFx::AS2::FnCall *)fn.pData;
  RefCount = (Scaleform::GFx::AS2::Value *)fn.pData->RefCount;
  Scaleform::GFx::AS2::Value::DropRefs(RefCount);
  RefCount->T.Type = 0;
  if ( pData->NArgs == 1 )
  {
    Env = pData->Env;
    v4 = 0;
    if ( pData->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1)
                                     + Env->Stack.pCurrent
                                     - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[(unsigned int)pData->FirstArgBottomIndex >> 5]->Values[pData->FirstArgBottomIndex
                                                                                            & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v4, &str, Env, -1, 0);
    Scaleform::String::String(&fn);
    v5 = str.pNode->pData;
    Length = Scaleform::GFx::ASConstString::GetLength(&str);
    Scaleform::String::UnescapeSpecialHTML(v5, Length, &fn);
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
    v9 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v10 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
    pNode = str.pNode;
    --str.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
