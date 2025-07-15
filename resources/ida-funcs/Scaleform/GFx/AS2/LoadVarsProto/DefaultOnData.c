void __cdecl Scaleform::GFx::AS2::LoadVarsProto::DefaultOnData(Scaleform::GFx::ASStringNode *a1)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::LoadVarsObject *p_pProto; // ebx
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v5; // ecx
  Scaleform::GFx::ASStringNode *v6; // edi
  bool v7; // zf
  Scaleform::GFx::AS2::Environment *v8; // edx
  Scaleform::GFx::AS2::Value *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // ebp
  Scaleform::GFx::AS2::ObjectInterface *v11; // eax
  unsigned __int8 Variables; // al
  void *v13; // esi
  void *v14; // esi
  Scaleform::GFx::ASStringNode *v15; // [esp+4h] [ebp-8h] BYREF
  Scaleform::String v16; // [esp+8h] [ebp-4h] BYREF

  v1 = (const Scaleform::GFx::AS2::FnCall *)a1;
  if ( a1->pLower
    && (*((int (__thiscall **)(Scaleform::GFx::ASStringNode *))a1->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + 2))(a1->pLower) == 27 )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::LoadVarsObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Env = v1->Env;
    v5 = 0;
    if ( v1->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v5 = &Env->Stack.Pages.Data.Data[(unsigned int)v1->FirstArgBottomIndex >> 5]->Values[v1->FirstArgBottomIndex
                                                                                         & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&a1, Env, -1, 0);
    v6 = a1;
    Scaleform::String::String(&v16, (const __m128i *)a1->pData);
    v7 = v6->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    v8 = v1->Env;
    v9 = 0;
    if ( v1->FirstArgBottomIndex <= 32 * (v8->Stack.Pages.Data.Size - 1) + v8->Stack.pCurrent - v8->Stack.pPageStart )
      v9 = &v8->Stack.Pages.Data.Data[(unsigned int)v1->FirstArgBottomIndex >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v9, (Scaleform::GFx::ASString *)&v15, v8, -1, 0);
    v10 = v15;
    Scaleform::String::String((Scaleform::String *)&a1, (const __m128i *)v15->pData);
    if ( p_pProto )
      v11 = &p_pProto->Scaleform::GFx::AS2::ObjectInterface;
    else
      v11 = 0;
    Variables = Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(v1->Env, v11, (Scaleform::String *)&a1);
    Scaleform::GFx::AS2::LoadVarsObject::NotifyOnLoad(p_pProto, v1->Env, (Scaleform::GFx::ASStringNode *)Variables);
    v13 = (void *)((unsigned int)a1 & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)a1 & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
    v7 = v10->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v14 = (void *)(v16.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v16.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}
