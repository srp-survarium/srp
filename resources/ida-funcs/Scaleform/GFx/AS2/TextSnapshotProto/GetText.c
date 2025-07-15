void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::GetText(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // ebx
  Scaleform::GFx::AS2::Value *v7; // eax
  unsigned int v8; // esi
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *v11; // edi
  bool v12; // zf
  void *v13; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v15; // [esp-10h] [ebp-18h]
  Scaleform::GFx::AS2::Environment *v16; // [esp-10h] [ebp-18h]
  Scaleform::String result; // [esp+4h] [ebp-4h] BYREF
  bool v18; // [esp+Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs >= 2 )
      {
        Env = fn->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v5 = Scaleform::GFx::AS2::Value::ToUInt32(v4, Env);
        v15 = fn->Env;
        v6 = v5;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v8 = Scaleform::GFx::AS2::Value::ToUInt32(v7, v15);
        if ( fn->NArgs >= 3 )
        {
          v16 = fn->Env;
          v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v18 = Scaleform::GFx::AS2::Value::ToBool(v9, (int)fn, v16);
        }
        else
        {
          v18 = 0;
        }
        if ( v8 <= v6 )
          v8 = v6 + 1;
        Scaleform::GFx::StaticTextSnapshotData::GetSubString(
          (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
          &result,
          v6,
          v8,
          v18);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       (__m128i *)((result.HeapTypeBits & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(result.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        v11 = fn->Result;
        if ( v11->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v11);
        v11->T.Type = 5;
        v11->NV.Int32Value = (int)StringNode;
        v12 = ++StringNode->RefCount == 1;
        --StringNode->RefCount;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        v13 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
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
