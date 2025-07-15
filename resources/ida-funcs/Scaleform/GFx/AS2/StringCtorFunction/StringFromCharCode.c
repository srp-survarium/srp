void __cdecl Scaleform::GFx::AS2::StringCtorFunction::StringFromCharCode(const Scaleform::GFx::AS2::FnCall *fn)
{
  int i; // edi
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v8; // zf
  unsigned int v9[2]; // [esp+8h] [ebp-20h]
  Scaleform::StringBuffer v10; // [esp+10h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&v10, Scaleform::Memory::pGlobalHeap);
  for ( i = 0; i < fn->NArgs; ++i )
  {
    Env = fn->Env;
    v3 = fn->FirstArgBottomIndex - i;
    v4 = 0;
    if ( v3 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    *(_QWORD *)v9 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v4, fn->Env);
    Scaleform::StringBuffer::AppendChar(&v10, v9[0]);
  }
  pData = (__m128i *)v10.pData;
  if ( !v10.pData )
    pData = (__m128i *)uri;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 pData,
                 v10.Size);
  ++StringNode->RefCount;
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 5;
  Result->NV.Int32Value = (int)StringNode;
  v8 = ++StringNode->RefCount == 1;
  --StringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v10);
}
