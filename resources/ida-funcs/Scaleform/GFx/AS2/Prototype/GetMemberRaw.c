char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->Elements.Data.Policy,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->Elements.Data.Policy,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ArrayObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::ArrayObject::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)this->mColorTransform.M[1],
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)this->mColorTransform.M[1],
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->LTime,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->LTime,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  bool v4; // bl
  Scaleform::GFx::ASStringNodeHolder *v6; // esi
  bool v7; // zf
  bool v8; // bl
  Scaleform::GFx::ASStringNodeHolder *v9; // esi
  bool v10; // zf
  bool namea; // [esp+1Ch] [ebp+8h]

  v4 = psc->SWFVersion > 6u;
  v6 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[80];
  if ( v4 )
  {
    v7 = v6->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v7 = v6->pNode->pLower == name->pNode->pLower;
  }
  namea = v7;
  if ( v7 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.pLocalFrame,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  v8 = psc->SWFVersion > 6u;
  v9 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[79];
  if ( v8 )
  {
    v10 = v9->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v10 = v9->pNode->pLower == name->pNode->pLower;
  }
  if ( v10 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.pLocalFrame,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GlowFilterObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.Flags,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.Flags,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::SharedObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::SharedObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::SharedObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


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


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.Flags,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.Flags,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::StringObject::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->CSS.TempKey,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->CSS.TempKey,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->mParagraphFormat.pTabStops,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->mParagraphFormat.pTabStops,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment> *this,
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->mValue,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
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
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->mValue,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  bool v4; // bl
  Scaleform::GFx::ASStringNodeHolder *v6; // esi
  bool v7; // zf
  bool v8; // bl
  Scaleform::GFx::ASStringNodeHolder *v9; // esi
  bool v10; // zf
  bool namea; // [esp+1Ch] [ebp+8h]

  v4 = psc->SWFVersion > 6u;
  v6 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[80];
  if ( v4 )
  {
    v7 = v6->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v7 = v6->pNode->pLower == name->pNode->pLower;
  }
  namea = v7;
  if ( v7 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  v8 = psc->SWFVersion > 6u;
  v9 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[79];
  if ( v8 )
  {
    v10 = v9->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v10 = v9->pNode->pLower == name->pNode->pLower;
  }
  if ( v10 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}


char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::GetMemberRaw(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  bool v4; // bl
  Scaleform::GFx::ASStringNodeHolder *v6; // esi
  bool v7; // zf
  bool v8; // bl
  Scaleform::GFx::ASStringNodeHolder *v9; // esi
  bool v10; // zf
  bool namea; // [esp+1Ch] [ebp+8h]

  v4 = psc->SWFVersion > 6u;
  v6 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[80];
  if ( v4 )
  {
    v7 = v6->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v7 = v6->pNode->pLower == name->pNode->pLower;
  }
  namea = v7;
  if ( v7 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->BytesLoadedCurrent,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  v8 = psc->SWFVersion > 6u;
  v9 = &Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext)->Builtins[79];
  if ( v8 )
  {
    v10 = v9->pNode == name->pNode;
  }
  else
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v10 = v9->pNode->pLower == name->pNode->pLower;
  }
  if ( v10 )
    return Scaleform::GFx::AS2::GASPrototypeBase::GetMemberRawConstructor(
             (Scaleform::GFx::AS2::GASPrototypeBase *)&this->BytesLoadedCurrent,
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment> *)((char *)this - 16),
             psc,
             name,
             val,
             namea);
  else
    return Scaleform::GFx::AS2::Object::GetMemberRaw(this, psc, name, val);
}
