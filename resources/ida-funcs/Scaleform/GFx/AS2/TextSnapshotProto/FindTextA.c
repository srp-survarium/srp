void __usercall Scaleform::GFx::AS2::TextSnapshotProto::FindTextA(int a1@<edi>, const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v2; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v5; // eax
  signed int v6; // ebx
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Value *v8; // eax
  bool v9; // al
  Scaleform::GFx::ASStringNode *pNode; // edi
  unsigned int Size; // edx
  int TextA; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  int v14; // ebx
  void *v15; // esi
  Scaleform::GFx::AS2::Environment *v17; // [esp-18h] [ebp-24h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-1Ch]
  const Scaleform::GFx::AS2::Environment *v19; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::ASString v20; // [esp+4h] [ebp-8h] BYREF
  char *v21; // [esp+8h] [ebp-4h]

  v2 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_TextSnapshot )
  {
    ThisPtr = v2->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && v2->NArgs >= 3 )
      {
        Env = v2->Env;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(v2, 0);
        v6 = Scaleform::GFx::AS2::Value::ToUInt32(v5, Env);
        v17 = v2->Env;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(v2, 1);
        Scaleform::GFx::AS2::Value::ToStringImpl(v7, &v20, v17, -1, 0);
        v19 = v2->Env;
        v8 = Scaleform::GFx::AS2::FnCall::Arg(v2, 2);
        v9 = Scaleform::GFx::AS2::Value::ToBool(v8, a1, v19);
        pNode = v20.pNode;
        Size = v20.pNode->Size;
        LOBYTE(v21) = v9;
        Scaleform::String::String((Scaleform::String *)&fn, (const __m128i *)v20.pNode->pData, Size);
        TextA = Scaleform::GFx::StaticTextSnapshotData::FindTextA(
                  (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
                  v6,
                  (char *)(((unsigned int)fn & 0xFFFFFFFC) + 8),
                  v21);
        Result = v2->Result;
        v14 = TextA;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 4;
        Result->NV.Int32Value = v14;
        v15 = (void *)((unsigned int)fn & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)fn & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
        if ( pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v2->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "TextSnapshot");
  }
}
