void __thiscall Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::ASString *fullPath,
        const Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::AS2::GlobalContext *pObject; // esi
  Scaleform::GFx::ASStringNode *RefCount; // eax
  char v7; // al
  Scaleform::GFx::ASStringNode *pNode; // ebx
  Scaleform::GFx::ASStringNode *pMovieImpl; // esi
  Scaleform::GFx::ASStringNode *v10; // eax
  const char *Length; // eax
  const Scaleform::GFx::ASString *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASString *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // esi
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // ecx
  const Scaleform::GFx::ASString *v19; // eax
  void *v20; // eax
  Scaleform::GFx::MovieImpl::StickyVarNode *v21; // esi
  const Scaleform::GFx::AS2::Value *v22; // edx
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASString path; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASString name; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+18h] [ebp-8h] BYREF

  pObject = this->pGlobalContext.pObject;
  path.pNode = (Scaleform::GFx::ASStringNode *)pObject->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++path.pNode->RefCount;
  RefCount = (Scaleform::GFx::ASStringNode *)pObject->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++RefCount->RefCount;
  name.pNode = RefCount;
  sc.pContext = pObject;
  sc.SWFVersion = 8;
  v7 = Scaleform::GFx::AS2::Environment::ParsePath(&sc, fullPath, &path, &name);
  pNode = name.pNode;
  if ( v7 )
  {
    if ( path.pNode->Size < 5 )
      goto LABEL_16;
    if ( *(_DWORD *)path.pNode->pData == 1869574751 && *((_BYTE *)path.pNode->pData + 4) == 116 )
    {
      Length = (const char *)Scaleform::GFx::ASConstString::GetLength(&path);
      fullPath = (Scaleform::GFx::ASString *)Scaleform::GFx::ASConstString::SubstringNode(
                                               &path,
                                               (const char *)5,
                                               Length);
      ++fullPath[3].pNode;
      v12 = Scaleform::GFx::ASString::operator+(
              (Scaleform::GFx::ASString *)&pObject->pMovieRoot->pASMovieRoot.pObject[21].pMovieImpl,
              &name,
              (const Scaleform::GFx::ASString *)&fullPath);
      Scaleform::GFx::ASString::operator=(&path, v12);
      v13 = name.pNode;
      --name.pNode->RefCount;
      if ( !v13->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      v14 = (Scaleform::GFx::ASStringNode *)fullPath;
      --fullPath[3].pNode;
      if ( !v14->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    if ( *(_DWORD *)path.pNode->pData != 1986358367
      || *((_BYTE *)path.pNode->pData + 4) != 101
      || *((_BYTE *)path.pNode->pData + 5) != 108 )
    {
LABEL_16:
      v15 = Scaleform::GFx::ASString::operator+(
              (Scaleform::GFx::ASString *)&pObject->pMovieRoot->pASMovieRoot.pObject[21].pASSupport,
              (Scaleform::GFx::ASString *)&fullPath,
              &path);
      v16 = v15->pNode;
      ++v15->pNode->RefCount;
      v17 = path.pNode;
      --path.pNode->RefCount;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      v18 = (Scaleform::GFx::ASStringNode *)fullPath;
      v19 = fullPath + 3;
      path.pNode = v16;
      --fullPath[3].pNode;
      if ( !v19->pNode )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  else
  {
    if ( !name.pNode->Size )
      goto LABEL_22;
    pMovieImpl = (Scaleform::GFx::ASStringNode *)pObject->pMovieRoot->pASMovieRoot.pObject[21].pMovieImpl;
    ++pMovieImpl->RefCount;
    v10 = path.pNode;
    --path.pNode->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    path.pNode = pMovieImpl;
  }
  v20 = this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 32, 0);
  v21 = (Scaleform::GFx::MovieImpl::StickyVarNode *)v20;
  if ( v20 )
  {
    v22 = val;
    *(_DWORD *)v20 = &Scaleform::GFx::MovieImpl::StickyVarNode::`vftable';
    *((_DWORD *)v20 + 1) = pNode;
    ++pNode->RefCount;
    *((_BYTE *)v20 + 12) = setType == SV_Permanent;
    *((_DWORD *)v20 + 2) = 0;
    *(_DWORD *)v20 = &Scaleform::GFx::AS2::MovieRoot::StickyVarNode::`vftable';
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v20 + 1, v22);
    Scaleform::GFx::MovieImpl::AddStickyVariableNode(this->pMovieImpl, &path, v21);
  }
LABEL_22:
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v24 = path.pNode;
  --path.pNode->RefCount;
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
}
