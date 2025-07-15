void __cdecl Scaleform::GFx::AS2::StringCtorFunction::StringFromCharCode(const Scaleform::GFx::AS2::FnCall *fn)
{
  int i; // edi
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *v7; // esi
  bool v8; // zf
  unsigned int v9[2]; // [esp+8h] [ebp-20h]
  Scaleform::StringBuffer result; // [esp+10h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&result, Scaleform::Memory::pGlobalHeap);
  for ( i = 0; i < fn->NArgs; ++i )
  {
    Env = fn->Env;
    v3 = fn->FirstArgBottomIndex - i;
    v4 = 0;
    if ( v3 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    *(_QWORD *)v9 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v4, fn->Env);
    Scaleform::StringBuffer::AppendChar(&result, v9[0]);
  }
  pData = result.pData;
  if ( !result.pData )
    pData = (char *)&buf;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 pData,
                 result.Size);
  ++StringNode->RefCount;
  v7 = fn->Result;
  if ( v7->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v7);
  v7->T.Type = 5;
  v7->NV.Int32Value = (int)StringNode;
  v8 = ++StringNode->RefCount == 1;
  --StringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&result);
}
