Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS2::Environment::TryDescr::GetCatchName(
        Scaleform::GFx::AS2::Environment::TryDescr *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *RefCount; // eax
  const unsigned __int8 *pTryBlock; // eax
  unsigned __int8 v5; // cl
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *v8; // esi
  bool v9; // zf

  RefCount = (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++RefCount->RefCount;
  result->pNode = RefCount;
  pTryBlock = this->pTryBlock;
  v5 = *this->pTryBlock;
  if ( (v5 & 1) == 0 || (v5 & 4) != 0 )
    return result;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 (char *)pTryBlock + 7);
  pNode = result->pNode;
  v8 = StringNode;
  StringNode->RefCount += 2;
  v9 = pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v9 = v8->RefCount-- == 1;
  result->pNode = v8;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  return result;
}
