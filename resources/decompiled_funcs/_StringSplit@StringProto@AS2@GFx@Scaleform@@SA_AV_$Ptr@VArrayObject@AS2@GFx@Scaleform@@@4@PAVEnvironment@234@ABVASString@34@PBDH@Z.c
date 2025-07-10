Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *__cdecl Scaleform::GFx::AS2::StringProto::StringSplit(
        Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> *result,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *str,
        const char *delimiters,
        Scaleform::String limit)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::ArrayObject *v6; // eax
  bool v7; // sf
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::Environment *pData; // edx
  const char *v10; // esi
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
  char *start; // [esp+10h] [ebp-24h]
  const char *s2; // [esp+14h] [ebp-20h] BYREF
  const char *end; // [esp+18h] [ebp-1Ch]
  Scaleform::GFx::ASString v31; // [esp+1Ch] [ebp-18h] BYREF
  const char *prev; // [esp+20h] [ebp-14h]
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
      start = (char *)pData;
      while ( 2 )
      {
        s2 = v10;
        end = (const char *)pData;
        v18 = 0;
        while ( 1 )
        {
          prev = (const char *)pData;
          Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&penv);
          if ( !Char_Advance0 )
            penv = (Scaleform::GFx::AS2::Environment *)((char *)penv - 1);
          v20 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&s2);
          v21 = v20;
          if ( !v20 )
            --s2;
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
        v22 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(&v31, p_StringContext, start, end)->pNode;
        pObject = result->pObject;
        ++v22->RefCount;
        val.T.Type = 5;
        val.NV.Int32Value = (int)v22;
        Scaleform::GFx::AS2::ArrayObject::PushBack(pObject, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v24 = v31.pNode;
        --v31.pNode->RefCount;
        if ( !v24->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        pData = (Scaleform::GFx::AS2::Environment *)prev;
        str = (const Scaleform::GFx::ASString *)((char *)str + 1);
        start = (char *)prev;
        penv = (Scaleform::GFx::AS2::Environment *)prev;
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
                  start,
                  0)->pNode;
        else
          v25 = Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
                  (Scaleform::GFx::ASString *)&limit,
                  p_StringContext,
                  start,
                  end)->pNode;
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
                       (char *)((limit.HeapTypeBits & 0xFFFFFFFC) + 8),
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
