char __cdecl Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pchar,
        Scaleform::String *data)
{
  Scaleform::String *v3; // esi
  char v5; // bl
  unsigned int FirstCharAt; // eax
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  __m128i *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  bool v11; // zf
  Scaleform::StringBuffer *v12; // ecx
  __m128i *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // esi
  __m128i *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  char v17; // [esp+Fh] [ebp-49h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [esp+10h] [ebp-48h] BYREF
  char *v19; // [esp+14h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+18h] [ebp-40h] BYREF
  Scaleform::StringBuffer v21; // [esp+28h] [ebp-30h] BYREF
  Scaleform::StringBuffer v22; // [esp+40h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&v21, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&v22, Scaleform::Memory::pGlobalHeap);
  v3 = data;
  if ( (*(_DWORD *)(data->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
  {
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v22);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v21);
    return 0;
  }
  v5 = 1;
  FirstCharAt = Scaleform::String::GetFirstCharAt(data, 0, &v19);
  if ( FirstCharAt )
  {
    while ( 1 )
    {
      if ( FirstCharAt == 13 )
      {
        FirstCharAt = 10;
      }
      else if ( FirstCharAt == 38 )
      {
        pData = (__m128i *)v22.pData;
        if ( !v22.pData )
          pData = (__m128i *)uri;
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       pData,
                       v22.Size);
        v5 = 1;
        ++StringNode->RefCount;
        v20.T.Type = 5;
        v20.NV.Int32Value = (int)StringNode;
        ++StringNode->RefCount;
        v9 = (__m128i *)v21.pData;
        v17 = 0;
        if ( !v21.pData )
          v9 = (__m128i *)uri;
        v18 = Scaleform::GFx::ASStringManager::CreateStringNode(
                (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                v9,
                v21.Size);
        ++v18->RefCount;
        pchar->SetMember(
          pchar,
          penv,
          (const Scaleform::GFx::ASString *)&v18,
          &v20,
          (const Scaleform::GFx::AS2::PropFlags *)&v17);
        v10 = v18;
        --v18->RefCount;
        if ( !v10->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        if ( v20.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v20);
        v11 = StringNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        Scaleform::StringBuffer::Clear(&v21);
        Scaleform::StringBuffer::Clear(&v22);
        v3 = data;
        goto LABEL_24;
      }
      if ( !v5 )
        break;
      if ( FirstCharAt != 61 )
      {
        v12 = &v21;
LABEL_23:
        Scaleform::StringBuffer::AppendChar(v12, FirstCharAt);
        goto LABEL_24;
      }
      v5 = 0;
LABEL_24:
      FirstCharAt = Scaleform::String::GetNextChar(v3, &v19);
      if ( !FirstCharAt )
        goto LABEL_25;
    }
    v12 = &v22;
    goto LABEL_23;
  }
LABEL_25:
  if ( Scaleform::StringBuffer::GetLength(&v21) )
  {
    v13 = (__m128i *)v22.pData;
    if ( !v22.pData )
      v13 = (__m128i *)uri;
    v14 = Scaleform::GFx::ASStringManager::CreateStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            v13,
            v22.Size);
    ++v14->RefCount;
    v20.T.Type = 5;
    v20.NV.Int32Value = (int)v14;
    ++v14->RefCount;
    v15 = (__m128i *)v21.pData;
    LOBYTE(data) = 0;
    if ( !v21.pData )
      v15 = (__m128i *)uri;
    v18 = Scaleform::GFx::ASStringManager::CreateStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            v15,
            v21.Size);
    ++v18->RefCount;
    pchar->SetMember(
      pchar,
      penv,
      (const Scaleform::GFx::ASString *)&v18,
      &v20,
      (const Scaleform::GFx::AS2::PropFlags *)&data);
    v16 = v18;
    --v18->RefCount;
    if ( !v16->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    if ( v20.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v20);
    v11 = v14->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v22);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v21);
  return 1;
}
