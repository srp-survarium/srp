void __cdecl Scaleform::GFx::AS2::LoadVarsProto::Decode(Scaleform::String fn)
{
  Scaleform::GFx::AS2::FnCall *pData; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  const char *v5; // ebx
  unsigned int Length; // eax
  Scaleform::GFx::AS2::ObjectInterface *v7; // eax
  void *v8; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-1Ch]
  Scaleform::GFx::ASConstString v11; // [esp+4h] [ebp-4h] BYREF

  pData = (Scaleform::GFx::AS2::FnCall *)fn.pData;
  if ( fn.pData[2].RefCount > 0 )
  {
    if ( *(_DWORD *)fn.pData->Data
      && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 27 )
    {
      ThisPtr = pData->ThisPtr;
      if ( ThisPtr )
        p_pProto = &ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      Env = pData->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(pData, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&v11, Env, -1, 0);
      Scaleform::String::String(&fn);
      v5 = v11.pNode->pData;
      Length = Scaleform::GFx::ASConstString::GetLength(&v11);
      Scaleform::GFx::ASUtils::Unescape(v5, Length, &fn);
      if ( p_pProto )
        v7 = (Scaleform::GFx::AS2::ObjectInterface *)&p_pProto[4];
      else
        v7 = 0;
      Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(pData->Env, v7, &fn);
      v8 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      pNode = v11.pNode;
      --v11.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        pData->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "LoadVars");
    }
  }
}
