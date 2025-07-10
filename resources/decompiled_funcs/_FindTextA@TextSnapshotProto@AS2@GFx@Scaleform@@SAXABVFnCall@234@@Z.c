void __cdecl Scaleform::GFx::AS2::TextSnapshotProto::FindTextA(Scaleform::String fn)
{
  const Scaleform::GFx::AS2::FnCall *pData; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v4; // eax
  signed int v5; // ebx
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  char v8; // al
  Scaleform::GFx::ASStringNode *pNode; // edi
  unsigned int Size; // edx
  int TextA; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  int v13; // ebx
  void *v14; // esi
  Scaleform::GFx::AS2::Environment *v16; // [esp-18h] [ebp-24h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-1Ch]
  const Scaleform::GFx::AS2::Environment *v18; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::ASString text; // [esp+4h] [ebp-8h] BYREF
  const char *bcaseSensitive; // [esp+8h] [ebp-4h]

  pData = (const Scaleform::GFx::AS2::FnCall *)fn.pData;
  if ( *(_DWORD *)fn.pData->Data
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 43 )
  {
    ThisPtr = pData->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && pData->NArgs >= 3 )
      {
        Env = pData->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(pData, 0);
        v5 = Scaleform::GFx::AS2::Value::ToUInt32(v4, Env);
        v16 = pData->Env;
        v6 = Scaleform::GFx::AS2::FnCall::Arg(pData, 1);
        Scaleform::GFx::AS2::Value::ToStringImpl(v6, &text, v16, -1, 0);
        v18 = pData->Env;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(pData, 2);
        v8 = Scaleform::GFx::AS2::Value::ToBool(v7, v18);
        pNode = text.pNode;
        Size = text.pNode->Size;
        LOBYTE(bcaseSensitive) = v8;
        Scaleform::String::String(&fn, (char *)text.pNode->pData, Size);
        TextA = Scaleform::GFx::StaticTextSnapshotData::FindTextA(
                  (Scaleform::GFx::StaticTextSnapshotData *)&p_pProto[13],
                  v5,
                  (const char *)((fn.HeapTypeBits & 0xFFFFFFFC) + 8),
                  bcaseSensitive);
        Result = pData->Result;
        v13 = TextA;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 4;
        Result->NV.Int32Value = v13;
        v14 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
        if ( pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      pData->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "TextSnapshot");
  }
}
