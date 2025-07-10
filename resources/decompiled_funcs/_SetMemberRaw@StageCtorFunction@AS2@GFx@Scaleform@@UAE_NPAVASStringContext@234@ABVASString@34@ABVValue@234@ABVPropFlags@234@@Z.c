char __thiscall Scaleform::GFx::AS2::StageCtorFunction::SetMemberRaw(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::MovieImpl **p_pMovieImpl; // esi
  bool v7; // zf
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *p_pASSupport; // esi
  bool v9; // zf

  pNode = name->pNode;
  p_pMovieImpl = &psc->pContext->pMovieRoot->pASMovieRoot.pObject[33].pMovieImpl;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    pNode = name->pNode;
    v7 = (*p_pMovieImpl)->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable == (Scaleform::GFx::StateBag_vtbl *)name->pNode->pLower;
  }
  else
  {
    v7 = *p_pMovieImpl == (Scaleform::GFx::MovieImpl *)pNode;
  }
  if ( v7 )
    return 1;
  p_pASSupport = &psc->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v9 = (Scaleform::GFx::ASStringNode *)p_pASSupport->pObject->SType == name->pNode->pLower;
  }
  else
  {
    v9 = p_pASSupport->pObject == (Scaleform::GFx::ASSupport *)pNode;
  }
  if ( v9 )
    return 1;
  else
    return Scaleform::GFx::AS2::Object::SetMemberRaw(this, psc, name, val, flags);
}
