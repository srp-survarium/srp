char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  volatile int *p_RefCount; // esi
  bool v8; // zf
  Scaleform::GFx::ASMovieRootBase *v9; // esi
  bool v10; // zf
  bool namea; // [esp+18h] [ebp+8h]

  pNode = name->pNode;
  p_RefCount = &psc->pContext->pMovieRoot->pASMovieRoot.pObject[24].RefCount;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    pNode = name->pNode;
    v8 = *(Scaleform::GFx::ASStringNode **)(*p_RefCount + 8) == name->pNode->pLower;
  }
  else
  {
    v8 = *p_RefCount == (_DWORD)pNode;
  }
  namea = v8;
  if ( v8 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.pLocalFrame,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  v9 = psc->pContext->pMovieRoot->pASMovieRoot.pObject + 24;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v10 = v9->AdvanceFrame == (void (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, bool))name->pNode->pLower;
  }
  else
  {
    v10 = v9->__vftable == (Scaleform::GFx::ASMovieRootBase_vtbl *)pNode;
  }
  if ( v10 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.pLocalFrame,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AmpMarker,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}
