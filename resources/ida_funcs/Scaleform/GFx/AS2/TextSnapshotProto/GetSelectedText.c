void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::GetSelectedText(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v7; // zf
  void *v8; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-10h]
  Scaleform::String selectedText; // [esp+4h] [ebp-4h] BYREF
  char binclLineEndings; // [esp+Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        if ( fn->NArgs <= 0 )
        {
          binclLineEndings = 0;
        }
        else
        {
          Env = fn->Env;
          v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          binclLineEndings = Scaleform::GFx::AS2::Value::ToBool(v4, Env);
        }
        Scaleform::GFx::StaticTextSnapshotData::GetSelectedText(
          (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
          &selectedText,
          binclLineEndings);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       (char *)((selectedText.HeapTypeBits & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(selectedText.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        Result = fn->Result;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 5;
        Result->NV.Int32Value = (int)StringNode;
        v7 = ++StringNode->RefCount == 1;
        --StringNode->RefCount;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        v8 = (void *)(selectedText.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((selectedText.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "TextSnapshot");
  }
}
