void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v3; // edi
  Scaleform::GFx::ASMovieRootBase *pObject; // esi
  volatile int RefCount; // eax
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  bool v9; // zf
  Scaleform::StringBuffer sbuffer; // [esp+10h] [ebp-18h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( (int)++p_pProto[18].pObject < 255 )
    {
      Scaleform::StringBuffer::StringBuffer(&sbuffer, fn->Env->StringContext.pContext->pHeap);
      Scaleform::GFx::AS2::ArrayObject::JoinToString(
        (Scaleform::GFx::AS2::ArrayObject *)p_pProto,
        fn->Env,
        &sbuffer,
        ",");
      pData = sbuffer.pData;
      if ( !sbuffer.pData )
        pData = (char *)&buf;
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     pData,
                     sbuffer.Size);
      ++StringNode->RefCount;
      Result = fn->Result;
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 5;
      Result->NV.Int32Value = (int)StringNode;
      v9 = ++StringNode->RefCount == 1;
      --StringNode->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sbuffer);
      --p_pProto[18].pObject;
    }
    else
    {
      Scaleform::GFx::LogState::LogMessageByType(
        (Scaleform::GFx::LogState *)p_pProto[13].pObject,
        (Scaleform::LogMessageId)&loc_34000,
        "256 levels of recursion is reached\n");
      v3 = fn->Result;
      pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( v3->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v3);
      v3->T.Type = 5;
      RefCount = pObject[8].RefCount;
      v3->NV.Int32Value = RefCount;
      ++*(_DWORD *)(RefCount + 12);
      --p_pProto[18].pObject;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
