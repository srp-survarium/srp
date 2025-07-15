void __cdecl Scaleform::GFx::AS2::MatrixProto::ToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // edi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Environment *v5; // edi
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // edi
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS2::Environment *v9; // edi
  Scaleform::GFx::AS2::Value *v10; // eax
  Scaleform::GFx::AS2::Environment *v11; // edi
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Environment *v13; // edi
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *v16; // esi
  bool v17; // zf
  void *v18; // esi
  Scaleform::String v19; // [esp+4h] [ebp-8Ch] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+8h] [ebp-88h] BYREF
  Scaleform::GFx::ASString v21; // [esp+18h] [ebp-78h] BYREF
  Scaleform::GFx::ASString v22; // [esp+1Ch] [ebp-74h] BYREF
  Scaleform::GFx::ASString v23; // [esp+20h] [ebp-70h] BYREF
  Scaleform::GFx::ASString v24; // [esp+24h] [ebp-6Ch] BYREF
  Scaleform::GFx::ASString v25; // [esp+28h] [ebp-68h] BYREF
  Scaleform::GFx::ASString v26; // [esp+2Ch] [ebp-64h] BYREF
  Scaleform::GFx::AS2::Value v27[6]; // [esp+30h] [ebp-60h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        `vector constructor iterator'(
          (char *)v27,
          0x10u,
          6,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::MatrixObject::GetMatrixAsValuesArray(
          p_pProto,
          (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
          (Scaleform::GFx::AS2::Value (*)[6])v27);
        Env = fn->Env;
        v4 = Scaleform::GFx::AS2::Value::ToPrimitive(v27, &result, Env, NoHint);
        Scaleform::GFx::AS2::Value::ToStringImpl(v4, &v21, Env, 6, 0);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        v5 = fn->Env;
        v6 = Scaleform::GFx::AS2::Value::ToPrimitive(&v27[1], &result, v5, NoHint);
        Scaleform::GFx::AS2::Value::ToStringImpl(v6, &v22, v5, 6, 0);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        v7 = fn->Env;
        v8 = Scaleform::GFx::AS2::Value::ToPrimitive(&v27[2], &result, v7, NoHint);
        Scaleform::GFx::AS2::Value::ToStringImpl(v8, &v23, v7, 6, 0);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        v9 = fn->Env;
        v10 = Scaleform::GFx::AS2::Value::ToPrimitive(&v27[3], &result, v9, NoHint);
        Scaleform::GFx::AS2::Value::ToStringImpl(v10, &v24, v9, 6, 0);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        v11 = fn->Env;
        v12 = Scaleform::GFx::AS2::Value::ToPrimitive(&v27[4], &result, v11, NoHint);
        Scaleform::GFx::AS2::Value::ToStringImpl(v12, &v25, v11, 6, 0);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        v13 = fn->Env;
        v14 = Scaleform::GFx::AS2::Value::ToPrimitive(&v27[5], &result, v13, NoHint);
        Scaleform::GFx::AS2::Value::ToStringImpl(v14, &v26, v13, 6, 0);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
        Scaleform::String::String(&v19);
        Scaleform::String::AppendString(&v19, (const __m128i *)"(a=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)v21.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)", b=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)v22.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)", c=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)v23.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)", d=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)v24.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)", tx=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)v25.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)", ty=", 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)v26.pNode->pData, 0xFFFFFFFF);
        Scaleform::String::AppendString(&v19, (const __m128i *)")", 0xFFFFFFFF);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       (__m128i *)((v19.HeapTypeBits & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(v19.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        v16 = fn->Result;
        if ( v16->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v16);
        v16->T.Type = 5;
        v16->NV.Int32Value = (int)StringNode;
        v17 = ++StringNode->RefCount == 1;
        --StringNode->RefCount;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        v18 = (void *)(v19.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v19.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
        `vector destructor iterator'(
          (char *)&v21,
          4u,
          6,
          (void (__thiscall *)(void *))Scaleform::GFx::ASString::~ASString);
        `vector destructor iterator'(
          (char *)v27,
          0x10u,
          6,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Matrix");
  }
}
