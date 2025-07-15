char __cdecl Scaleform::GFx::AS2::Environment::ParsePath(
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *varPath,
        Scaleform::GFx::ASString *ppath,
        Scaleform::GFx::ASString *pvar)
{
  char *pData; // esi
  signed int v5; // edi
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::AS2::ASStringContext *v9; // ebx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *v11; // ecx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *RefCount; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v15; // sf
  Scaleform::GFx::ASStringNode *v16; // esi
  Scaleform::GFx::ASStringNode *v17; // ecx
  Scaleform::GFx::ASStringNode *v18; // ebp
  Scaleform::GFx::ASStringNode *v19; // ecx

  pData = (char *)varPath->pNode->pData;
  v5 = -1;
  strchr(pData, 0x3Au);
  if ( !v6 )
  {
    strrchr(pData, 0x2Eu);
    if ( !v6 )
    {
      strrchr(pData, 0x2Fu);
      if ( !v7 )
        return 0;
      goto LABEL_10;
    }
  }
  v5 = v6 - (_DWORD)pData;
  if ( v6 - (int)pData < 0 )
  {
LABEL_10:
    v9 = psc;
    RefCount = (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    ++RefCount->RefCount;
    pNode = pvar->pNode;
    v12 = pvar->pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pvar->pNode = RefCount;
    goto LABEL_13;
  }
  v9 = psc;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 (__m128i *)&varPath->pNode->pData[v5 + 1]);
  StringNode->RefCount += 2;
  v11 = pvar->pNode;
  v12 = pvar->pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  pvar->pNode = StringNode;
  v12 = StringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
LABEL_13:
  v15 = v5 < 0;
  if ( v5 > 0 )
  {
    if ( varPath->pNode->pData[v5 - 1] == 47 )
      --v5;
    v15 = v5 < 0;
  }
  if ( v15 )
  {
    v18 = varPath->pNode;
    ++varPath->pNode->RefCount;
    v19 = ppath->pNode;
    v12 = ppath->pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    ppath->pNode = v18;
  }
  else
  {
    v16 = Scaleform::GFx::ASStringManager::CreateStringNode(
            (Scaleform::GFx::ASStringManager *)v9->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            (__m128i *)varPath->pNode->pData,
            v5);
    v16->RefCount += 2;
    v17 = ppath->pNode;
    v12 = ppath->pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    ppath->pNode = v16;
    v12 = v16->RefCount-- == 1;
    if ( v12 )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      return 1;
    }
  }
  return 1;
}
