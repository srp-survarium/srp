char __thiscall Scaleform::GFx::AS2::MouseCtorFunction::GetMember(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::ASStringNode **pObject; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  long double val; // st7
  const Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Value v12; // [esp+18h] [ebp-10h] BYREF

  pContext = penv->StringContext.pContext;
  p_StringContext = &penv->StringContext;
  if ( pContext->GFxExtensions.Value != 1 )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             p_StringContext,
             name,
             pval);
  pObject = (Scaleform::GFx::ASStringNode **)pContext->pMovieRoot->pASMovieRoot.pObject;
  pNode = name->pNode;
  if ( name->pNode == pObject[177] )
  {
    Scaleform::GFx::AS2::Value::SetAsFunction(
      pval,
      (const Scaleform::GFx::AS2::FunctionRefBase *)&this->pListenersArray);
    return 1;
  }
  if ( pNode == pObject[178] )
  {
    if ( pval->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pval);
    pval->T.Type = 3;
    pval->NV.NumberValue = 1.0;
    return ((int (__thiscall *)(Scaleform::GFx::AS2::MouseCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             p_StringContext,
             name,
             pval);
  }
  if ( pNode == pObject[179] )
  {
    if ( pval->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pval);
    pval->T.Type = 3;
    pval->NV.NumberValue = 2.0;
    return ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->IsNull)(this, p_StringContext, name, pval);
  }
  if ( pNode == pObject[180] )
  {
    val = 3.0;
LABEL_14:
    Scaleform::GFx::AS2::Value::SetNumber(pval, val);
    return ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->IsNull)(this, p_StringContext, name, pval);
  }
  if ( pNode == pObject[181] )
  {
    val = 0.0;
    goto LABEL_14;
  }
  if ( pNode == pObject[182] )
  {
    val = 1.0;
    goto LABEL_14;
  }
  if ( pNode == pObject[183] )
  {
    val = 2.0;
    goto LABEL_14;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "getTopMostEntity") )
  {
    Scaleform::GFx::AS2::Value::Value(&v12, p_StringContext, Scaleform::GFx::AS2::MouseCtorFunction::GetTopMostEntity);
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "getPosition") )
  {
    Scaleform::GFx::AS2::Value::Value(
      &v12,
      p_StringContext,
      (void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *))Scaleform::GFx::AS2::MouseCtorFunction::GetPosition);
  }
  else
  {
    if ( !Scaleform::GFx::ASString::operator==(name, "getButtonsState") )
      return ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->IsNull)(this, p_StringContext, name, pval);
    Scaleform::GFx::AS2::Value::Value(&v12, p_StringContext, Scaleform::GFx::AS2::MouseCtorFunction::GetButtonsState);
  }
  Scaleform::GFx::AS2::Value::operator=(pval, v11);
  if ( v12.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v12);
  return 1;
}
