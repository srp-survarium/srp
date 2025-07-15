char __cdecl Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pchar,
        Scaleform::String *data)
{
  Scaleform::String *v3; // esi
  char v5; // bl
  unsigned int FirstCharAt; // eax
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  char *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  bool v11; // zf
  Scaleform::StringBuffer *p_name; // ecx
  char *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // esi
  char *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  char v17; // [esp+Fh] [ebp-49h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [esp+10h] [ebp-48h] BYREF
  const char *pstr; // [esp+14h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+18h] [ebp-40h] BYREF
  Scaleform::StringBuffer name; // [esp+28h] [ebp-30h] BYREF
  Scaleform::StringBuffer value; // [esp+40h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&name, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&value, Scaleform::Memory::pGlobalHeap);
  v3 = data;
  if ( (*(_DWORD *)(data->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
  {
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&value);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&name);
    return 0;
  }
  v5 = 1;
  FirstCharAt = Scaleform::String::GetFirstCharAt(data, 0, &pstr);
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
        pData = value.pData;
        if ( !value.pData )
          pData = (char *)&buf;
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       pData,
                       value.Size);
        v5 = 1;
        ++StringNode->RefCount;
        v20.T.Type = 5;
        v20.NV.Int32Value = (int)StringNode;
        ++StringNode->RefCount;
        v9 = name.pData;
        v17 = 0;
        if ( !name.pData )
          v9 = (char *)&buf;
        v18 = Scaleform::GFx::ASStringManager::CreateStringNode(
                (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                v9,
                name.Size);
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
        Scaleform::StringBuffer::Clear(&name);
        Scaleform::StringBuffer::Clear(&value);
        v3 = data;
        goto LABEL_24;
      }
      if ( !v5 )
        break;
      if ( FirstCharAt != 61 )
      {
        p_name = &name;
LABEL_23:
        Scaleform::StringBuffer::AppendChar(p_name, FirstCharAt);
        goto LABEL_24;
      }
      v5 = 0;
LABEL_24:
      FirstCharAt = Scaleform::String::GetNextChar(v3, &pstr);
      if ( !FirstCharAt )
        goto LABEL_25;
    }
    p_name = &value;
    goto LABEL_23;
  }
LABEL_25:
  if ( Scaleform::StringBuffer::GetLength(&name) )
  {
    v13 = value.pData;
    if ( !value.pData )
      v13 = (char *)&buf;
    v14 = Scaleform::GFx::ASStringManager::CreateStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            v13,
            value.Size);
    ++v14->RefCount;
    v20.T.Type = 5;
    v20.NV.Int32Value = (int)v14;
    ++v14->RefCount;
    v15 = name.pData;
    LOBYTE(data) = 0;
    if ( !name.pData )
      v15 = (char *)&buf;
    v18 = Scaleform::GFx::ASStringManager::CreateStringNode(
            (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            v15,
            name.Size);
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
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&value);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&name);
  return 1;
}
