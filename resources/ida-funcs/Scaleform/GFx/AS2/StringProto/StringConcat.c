void __cdecl Scaleform::GFx::AS2::StringProto::StringConcat(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  char ***p_pProto; // eax
  int i; // ebx
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Value *v7; // ecx
  Scaleform::GFx::ASStringNode *v8; // edi
  bool v9; // zf
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::StringBuffer retVal; // [esp+4h] [ebp-18h] BYREF

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = (char ***)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Scaleform::StringBuffer::StringBuffer(
      &retVal,
      *p_pProto[13],
      (unsigned int)p_pProto[13][5],
      Scaleform::Memory::pGlobalHeap);
    for ( i = 0; i < v1->NArgs; ++i )
    {
      Env = v1->Env;
      v6 = v1->FirstArgBottomIndex - i;
      v7 = 0;
      if ( v6 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
        v7 = &Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      Scaleform::GFx::AS2::Value::ToStringImpl(v7, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v8 = (Scaleform::GFx::ASStringNode *)fn;
      Scaleform::StringBuffer::AppendString(&retVal, (char *)fn->__vftable, 0xFFFFFFFF);
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    pData = retVal.pData;
    if ( !retVal.pData )
      pData = (char *)&buf;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   pData,
                   retVal.Size);
    ++StringNode->RefCount;
    Result = v1->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)StringNode;
    v9 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&retVal);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
