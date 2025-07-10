char __thiscall Scaleform::GFx::AS2::AvmButton::GetMember(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  int StandardMemberConstant; // eax
  Scaleform::GFx::AvmButtonBase_vtbl *v7; // eax
  Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *pUserDataHolder; // ebx
  Scaleform::GFx::AS2::GlobalContext *pContext; // esi
  Scaleform::GFx::AS2::ButtonObject *namea; // [esp+18h] [ebp+8h]

  if ( (name->pNode->HashFlags & 0x20000000) != 0 )
  {
    namea = this[-1].ASButtonObj.pObject;
    StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                               (Scaleform::GFx::AS2::AvmButton *)((char *)this - 4),
                               name);
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::ButtonObject> *, int, Scaleform::GFx::AS2::Value *, _DWORD))namea[2].ResolveHandler.Function)(
           &this[-1].ASButtonObj,
           StandardMemberConstant,
           pval,
           0) )
    {
      return 1;
    }
  }
  v7 = this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
  if ( v7 )
    return (*((int (__thiscall **)(Scaleform::GFx::AvmTextFieldBase *(__thiscall **)(Scaleform::GFx::AvmDisplayObjBase *), Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v7->ToAvmTextFieldBase
            + 4))(
             &v7->ToAvmTextFieldBase,
             penv,
             name,
             pval);
  if ( penv
    && name->pNode == *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].AVMVersion )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(pval, (Scaleform::GFx::AS2::Object *)this->pUserDataHolder);
    return 1;
  }
  pUserDataHolder = this->pUserDataHolder;
  if ( pUserDataHolder
    && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))pUserDataHolder[2].pMovieView[1].Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable)(
         &pUserDataHolder[2],
         penv,
         name,
         pval) )
  {
    return 1;
  }
  if ( !penv )
    return 0;
  pContext = penv->StringContext.pContext;
  if ( name->pNode != *(Scaleform::GFx::ASStringNode **)&pContext->pMovieRoot->pASMovieRoot.pObject[20].AVMVersion )
    return 0;
  Scaleform::GFx::AS2::Value::SetAsObject(pval, pContext->pGlobal.pObject);
  return 1;
}
