char __thiscall Scaleform::GFx::AS3::MovieRoot::ExtractPathAndName(
        Scaleform::GFx::AS3::MovieRoot *this,
        char *fullPath,
        Scaleform::GFx::ASString *ppath,
        Scaleform::GFx::ASString *pname)
{
  unsigned int v4; // eax
  const char *v6; // eax
  unsigned int v7; // ebx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // esi
  Scaleform::GFx::ASStringNode *v12; // ecx

  v4 = strlen(fullPath);
  if ( !v4 )
    return 0;
  while ( fullPath[v4] != 46 )
  {
    if ( !--v4 )
      return 0;
  }
  v6 = &fullPath[v4];
  if ( !v6 )
    return 0;
  v7 = v6 - fullPath;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, (char *)v6 + 1);
  StringNode->RefCount += 2;
  pNode = pname->pNode;
  v10 = pname->pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  pname->pNode = StringNode;
  v10 = StringNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v11 = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, fullPath, v7);
  v11->RefCount += 2;
  v12 = ppath->pNode;
  v10 = ppath->pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  ppath->pNode = v11;
  v10 = v11->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  return 1;
}
