void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayJoin(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebx
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // esi
  bool v6; // zf
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-30h]
  Scaleform::StringBuffer sbuffer; // [esp+4h] [ebp-18h] BYREF

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    p_pProto->LengthValueOverriden = 0;
    Scaleform::StringBuffer::StringBuffer(&sbuffer, v1->Env->StringContext.pContext->pHeap);
    if ( v1->NArgs )
    {
      Env = v1->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v4, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v5 = (Scaleform::GFx::ASStringNode *)fn;
      Scaleform::GFx::AS2::ArrayObject::JoinToString(p_pProto, v1->Env, &sbuffer, (char *)fn->__vftable);
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    }
    else
    {
      Scaleform::GFx::AS2::ArrayObject::JoinToString(p_pProto, v1->Env, &sbuffer, ",");
    }
    pData = sbuffer.pData;
    if ( !sbuffer.pData )
      pData = (char *)&buf;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   pData,
                   sbuffer.Size);
    ++StringNode->RefCount;
    Result = v1->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)StringNode;
    v6 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sbuffer);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
