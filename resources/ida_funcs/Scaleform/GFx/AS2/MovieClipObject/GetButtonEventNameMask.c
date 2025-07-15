int __cdecl Scaleform::GFx::AS2::MovieClipObject::GetButtonEventNameMask(
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  pNode = name->pNode;
  if ( pObject[26].pMovieImpl == (Scaleform::GFx::MovieImpl *)name->pNode )
    return 1;
  if ( (Scaleform::GFx::ASStringNode *)pObject[26].pASSupport.pObject == pNode )
    return 2;
  if ( *(Scaleform::GFx::ASStringNode **)&pObject[26].AVMVersion == pNode )
    return 4;
  if ( (Scaleform::GFx::ASStringNode *)pObject[27].__vftable == pNode )
    return 8;
  if ( (Scaleform::GFx::ASStringNode *)pObject[27].RefCount == pNode )
    return 16;
  if ( (Scaleform::GFx::ASStringNode *)pObject[27].pMovieImpl == pNode )
    return 32;
  if ( (Scaleform::GFx::ASStringNode *)pObject[27].pASSupport.pObject == pNode )
    return 64;
  if ( (Scaleform::GFx::ASStringNode *)pObject[32].pMovieImpl == pNode )
    return 128;
  if ( (Scaleform::GFx::ASStringNode *)pObject[32].pASSupport.pObject == pNode )
    return 256;
  if ( *(Scaleform::GFx::ASStringNode **)&pObject[32].AVMVersion == pNode )
    return 512;
  if ( (Scaleform::GFx::ASStringNode *)pObject[33].__vftable == pNode )
    return 1024;
  if ( (Scaleform::GFx::ASStringNode *)pObject[33].RefCount == pNode )
    return 2048;
  return 0;
}
