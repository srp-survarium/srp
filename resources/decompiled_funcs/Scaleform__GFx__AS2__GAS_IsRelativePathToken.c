BOOL __usercall Scaleform::GFx::AS2::GAS_IsRelativePathToken@<eax>(
        Scaleform::GFx::AS2::ASStringContext *psc@<eax>,
        const Scaleform::GFx::ASString *pathComponent@<edi>)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASMovieRootBase *pObject; // esi

  pNode = pathComponent->pNode;
  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( (Scaleform::GFx::ASStringNode *)pObject[18].RefCount == pathComponent->pNode )
    return 1;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    return *(Scaleform::GFx::ASStringNode **)(pObject[21].RefCount + 8) == pathComponent->pNode->pLower;
  }
  else
  {
    return pObject[21].RefCount == (_DWORD)pNode;
  }
}
