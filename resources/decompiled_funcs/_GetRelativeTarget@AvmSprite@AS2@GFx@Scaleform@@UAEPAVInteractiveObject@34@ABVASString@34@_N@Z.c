Scaleform::GFx::Sprite *__userpurge Scaleform::GFx::AS2::AvmSprite::GetRelativeTarget@<eax>(
        Scaleform::GFx::AS2::AvmSprite *this@<ecx>,
        unsigned int a2@<ebx>,
        Scaleform::GFx::ASString *name,
        const char *first_call)
{
  bool v5; // cf
  bool v6; // zf
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::Sprite *result; // eax
  Scaleform::GFx::ASMovieRootBase *v10; // eax
  Scaleform::GFx::StateBag_vtbl *pLower; // edx
  char *pData; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // esi
  bool caseSensitive; // [esp+Ch] [ebp-4h]

  v5 = this->ASEnvironment.StringContext.SWFVersion < 6u;
  v6 = this->ASEnvironment.StringContext.SWFVersion == 6;
  pNode = name->pNode;
  caseSensitive = !v5 && !v6;
  if ( (name->pNode->HashFlags & 0x80000000) != 0 )
  {
    if ( !v5 && !v6 )
    {
      pObject = this->ASEnvironment.StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      if ( (Scaleform::GFx::ASStringNode *)pObject[18].__vftable != pNode
        && (Scaleform::GFx::ASStringNode *)pObject[20].pMovieImpl != pNode )
      {
        if ( (Scaleform::GFx::ASStringNode *)pObject[18].RefCount == pNode
          || (Scaleform::GFx::ASStringNode *)pObject[21].RefCount == pNode )
        {
          return (Scaleform::GFx::Sprite *)this->pDispObj->pParent;
        }
        if ( (Scaleform::GFx::ASStringNode *)pObject[21].__vftable == pNode )
          return (Scaleform::GFx::Sprite *)this->GetTopParent(this, 0);
        goto LABEL_20;
      }
      return (Scaleform::GFx::Sprite *)this->pDispObj;
    }
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v10 = this->ASEnvironment.StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    pNode = name->pNode;
    if ( v10[18].__vftable == (Scaleform::GFx::ASMovieRootBase_vtbl *)name->pNode )
      return (Scaleform::GFx::Sprite *)this->pDispObj;
    pLower = (Scaleform::GFx::StateBag_vtbl *)pNode->pLower;
    if ( v10[20].pMovieImpl->__vftable == pLower )
      return (Scaleform::GFx::Sprite *)this->pDispObj;
    if ( (Scaleform::GFx::ASStringNode *)v10[18].RefCount == pNode
      || *(Scaleform::GFx::StateBag_vtbl **)(v10[21].RefCount + 8) == pLower )
    {
      return (Scaleform::GFx::Sprite *)this->pDispObj->pParent;
    }
    if ( (Scaleform::GFx::StateBag_vtbl *)v10[21].AdvanceFrame == pLower )
      return (Scaleform::GFx::Sprite *)this->GetTopParent(this, 0);
  }
LABEL_20:
  pData = (char *)pNode->pData;
  if ( *pData == 95 )
  {
    if ( (_BYTE)first_call )
    {
      first_call = 0;
      v13 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(pData, a2, pData, (char **)&first_call, caseSensitive);
      if ( v13 != -1 && !*first_call )
        return Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
                 (Scaleform::GFx::AS2::MovieRoot *)this->pDispObj->pASRoot,
                 v13);
    }
  }
  v5 = this->ASEnvironment.StringContext.SWFVersion < 6u;
  v6 = this->ASEnvironment.StringContext.SWFVersion == 6;
  pDispObj = this->pDispObj;
  LOBYTE(first_call) = !v5 && !v6;
  result = (Scaleform::GFx::Sprite *)Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                                       (Scaleform::GFx::DisplayList *)&pDispObj[1],
                                       name,
                                       (bool)first_call);
  if ( !result
    || SLOBYTE(result->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0 )
  {
    return 0;
  }
  return result;
}
