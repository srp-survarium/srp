void __cdecl Scaleform::GFx::AS2::StringProto::StringSplit(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // esi
  char *pData; // ebx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::ASStringNode *RefCount; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // ebx
  bool v7; // zf
  int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // ebx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v13; // [esp-8h] [ebp-14h]
  Scaleform::GFx::ASStringNode *v14; // [esp+8h] [ebp-4h] BYREF

  v1 = fn;
  pData = 0;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      fn = (Scaleform::GFx::AS2::FnCall *)&ThisPtr[-2].pProto;
    else
      fn = 0;
    RefCount = (Scaleform::GFx::ASStringNode *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    ++RefCount->RefCount;
    if ( v1->NArgs >= 1 )
    {
      Env = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v14, Env, -1, 0);
      v6 = v14;
      ++v14->RefCount;
      v7 = RefCount->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
      v7 = v6->RefCount-- == 1;
      RefCount = v6;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      pData = (char *)v6->pData;
    }
    v8 = 0x3FFFFFFF;
    if ( v1->NArgs >= 2 )
    {
      v13 = v1->Env;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v8 = (int)Scaleform::GFx::AS2::Value::ToNumber(v9, v13);
      if ( v8 < 0 )
        v8 = 0;
    }
    Scaleform::GFx::AS2::StringProto::StringSplit(
      (Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *)&fn,
      v1->Env,
      (const Scaleform::GFx::ASString *)&fn[1].ThisFunctionRef.pLocalFrame,
      pData,
      (Scaleform::String)v8);
    v10 = (Scaleform::GFx::AS2::Object *)fn;
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)fn);
    if ( v10 )
    {
      v11 = v10->RefCount;
      if ( (v11 & 0x3FFFFFF) != 0 )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    v7 = RefCount->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}


Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *__cdecl Scaleform::GFx::AS2::StringProto::StringSplit(
        Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *result,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *str,
        char *delimiters,
        Scaleform::String limit)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::ArrayObject *v6; // eax
  bool v7; // sf
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::Environment *pData; // edx
  char *v10; // esi
  unsigned int v12; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS2::ArrayObject *v14; // ecx
  Scaleform::GFx::ASStringNode *v15; // esi
  void *v17; // esi
  Scaleform::GFx::AS2::Environment *v18; // esi
  unsigned int Char_Advance0; // ebp
  unsigned int v20; // eax
  unsigned int v21; // ebx
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS2::ArrayObject *pObject; // ecx
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::AS2::ArrayObject *v26; // ecx
  Scaleform::GFx::ASStringNode *v27; // eax
  __m128i *v28; // [esp+10h] [ebp-24h]
  char *putf8Buffer; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Environment *v30; // [esp+18h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v31; // [esp+1Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS2::Environment *v32; // [esp+20h] [ebp-14h]
  Scaleform::GFx::AS2::Value val; // [esp+24h] [ebp-10h] BYREF

  p_StringContext = &penv->StringContext;
  v6 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                             penv,
                                             penv->StringContext.pContext->pGlobal.pObject,
                                             (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                             0,
                                             -1);
  v7 = (int)limit.pData < 0;
  pNode = str->pNode;
  pData = (Scaleform::GFx::AS2::Environment *)str->pNode->pData;
  result->pObject = v6;
  penv = pData;
  if ( v7 )
    limit.pData = 0;
  v10 = delimiters;
  if ( delimiters )
  {
    if ( *delimiters )
    {
      str = 0;
      v28 = (__m128i *)pData;
      while ( 2 )
      {
        putf8Buffer = v10;
        v30 = pData;
        v18 = 0;
        while ( 1 )
        {
          v32 = pData;
          Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&penv);
          if ( !Char_Advance0 )
            penv = (Scaleform::GFx::AS2::Environment *)((char *)penv - 1);
          v20 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          v21 = v20;
          if ( !v20 )
            --putf8Buffer;
          pData = penv;
          if ( !v18 )
            v18 = penv;
          if ( !Char_Advance0 )
            break;
          if ( !v20 )
            goto LABEL_29;
          if ( Char_Advance0 != v20 )
          {
            pData = v18;
            penv = v18;
            break;
          }
        }
        if ( v20 )
          goto LABEL_35;
LABEL_29:
        if ( (int)str >= (int)limit.pData )
          return result;
        v22 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
                (Scaleform::GFx::ASString *)&v31,
                p_StringContext,
                v28,
                (const char *)v30)->pNode;
        pObject = result->pObject;
        ++v22->RefCount;
        val.T.Type = 5;
        val.NV.Int32Value = (int)v22;
        Scaleform::GFx::AS2::ArrayObject::PushBack(pObject, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v24 = v31;
        --v31->RefCount;
        if ( !v24->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        pData = v32;
        str = (const Scaleform::GFx::ASString *)((char *)str + 1);
        v28 = (__m128i *)v32;
        penv = v32;
LABEL_35:
        if ( Char_Advance0 )
        {
          v10 = delimiters;
          continue;
        }
        break;
      }
      if ( (int)str < (int)limit.pData )
      {
        if ( v21 )
          v25 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
                  (Scaleform::GFx::ASString *)&limit,
                  p_StringContext,
                  v28,
                  0)->pNode;
        else
          v25 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
                  (Scaleform::GFx::ASString *)&limit,
                  p_StringContext,
                  v28,
                  (const char *)v30)->pNode;
        v26 = result->pObject;
        ++v25->RefCount;
        val.NV.Int32Value = (int)v25;
        val.T.Type = 5;
        Scaleform::GFx::AS2::ArrayObject::PushBack(v26, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v27 = (Scaleform::GFx::ASStringNode *)limit.pData;
        --limit.pData[1].Size;
        if ( !v27->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
    }
    else
    {
      Scaleform::String::String(&limit);
      while ( 1 )
      {
        v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&penv);
        if ( !v12 )
          break;
        Scaleform::String::Clear(&limit);
        Scaleform::String::AppendChar(&limit, v12);
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       (__m128i *)((limit.HeapTypeBits & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(limit.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        v14 = result->pObject;
        v15 = StringNode;
        ++StringNode->RefCount;
        ++StringNode->RefCount;
        val.T.Type = 5;
        val.NV.Int32Value = (int)StringNode;
        Scaleform::GFx::AS2::ArrayObject::PushBack(v14, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        if ( v15->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      }
      penv = (Scaleform::GFx::AS2::Environment *)((char *)penv - 1);
      v17 = (void *)(limit.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((limit.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
        return result;
      }
    }
  }
  else
  {
    ++pNode->RefCount;
    val.NV.Int32Value = (int)pNode;
    val.T.Type = 5;
    Scaleform::GFx::AS2::ArrayObject::PushBack(v6, &val);
    if ( val.T.Type >= 5u )
    {
      Scaleform::GFx::AS2::Value::DropRefs(&val);
      return result;
    }
  }
  return result;
}
