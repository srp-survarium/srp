void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::GetSelectedText(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *v6; // edi
  bool v7; // zf
  void *v8; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-10h]
  Scaleform::String result; // [esp+4h] [ebp-4h] BYREF
  bool v11; // [esp+Ch] [ebp+4h]

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
          v11 = 0;
        }
        else
        {
          Env = fn->Env;
          v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          v11 = Scaleform::GFx::AS2::Value::ToBool(v4, (int)fn, Env);
        }
        Scaleform::GFx::StaticTextSnapshotData::GetSelectedText(
          (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
          &result,
          v11);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       (__m128i *)((result.HeapTypeBits & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(result.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        v6 = fn->Result;
        if ( v6->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 5;
        v6->NV.Int32Value = (int)StringNode;
        v7 = ++StringNode->RefCount == 1;
        --StringNode->RefCount;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        v8 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
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
