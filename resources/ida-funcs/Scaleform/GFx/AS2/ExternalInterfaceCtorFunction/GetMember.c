char __thiscall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GetMember(
        Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  bool v5; // bl
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  const Scaleform::GFx::ASString *v8; // ebx
  bool v9; // zf
  Scaleform::GFx::ExternalInterface *pObject; // edi
  bool namea; // [esp+18h] [ebp+8h]

  v5 = penv->StringContext.SWFVersion > 6u;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "available",
                      9u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  if ( v5 )
  {
    v8 = name;
    v9 = ConstStringNode == name->pNode;
  }
  else
  {
    if ( !ConstStringNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(ConstStringNode);
    v8 = name;
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v9 = v7->pLower == name->pNode->pLower;
  }
  namea = v9;
  v9 = v7->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( !namea )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             &penv->StringContext,
             v8,
             val);
  pObject = penv->Target->pASRoot->pMovieImpl->pExtIntfHandler.pObject;
  Scaleform::GFx::AS2::Value::DropRefs(val);
  val->V.BooleanValue = pObject != 0;
  val->T.Type = 2;
  return 1;
}
