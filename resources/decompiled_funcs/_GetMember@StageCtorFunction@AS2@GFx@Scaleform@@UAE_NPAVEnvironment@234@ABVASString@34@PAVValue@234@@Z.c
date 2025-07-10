char __thiscall Scaleform::GFx::AS2::StageCtorFunction::GetMember(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  bool v6; // bl
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  bool v9; // zf
  bool v10; // bl
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  const Scaleform::GFx::AS2::Value *v12; // eax
  bool v14; // bl
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // esi
  bool v17; // zf
  bool v18; // bl
  Scaleform::GFx::AS2::Environment *v19; // esi
  Scaleform::GFx::MovieImpl *v20; // ecx
  Scaleform::GFx::MovieImpl *v21; // ecx
  const Scaleform::Render::Rect<float> *v22; // eax
  const Scaleform::GFx::AS2::Value *RectangleObject; // eax
  bool v24; // bl
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // esi
  bool v27; // zf
  bool v28; // bl
  Scaleform::GFx::MovieImpl *v29; // ecx
  int v30; // eax
  Scaleform::GFx::AS2::StageCtorFunction *v31; // [esp+5Ch] [ebp-24h]
  Scaleform::GFx::AS2::Value result; // [esp+60h] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> rect; // [esp+70h] [ebp-10h] BYREF

  pContext = penv->StringContext.pContext;
  p_StringContext = &penv->StringContext;
  v31 = this;
  if ( pContext->GFxExtensions.Value != 1 )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::StageCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             p_StringContext,
             name,
             val);
  v6 = penv->StringContext.SWFVersion > 6u;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "visibleRect",
                      0xBu,
                      0);
  v8 = ConstStringNode;
  ++ConstStringNode->RefCount;
  if ( v6 )
  {
    v9 = ConstStringNode == name->pNode;
  }
  else
  {
    if ( !ConstStringNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(ConstStringNode);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v9 = v8->pLower == name->pNode->pLower;
  }
  v10 = v9;
  v9 = v8->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v10 )
  {
    pMovieImpl = penv->Target->pASRoot->pMovieImpl;
    pMovieImpl->GetVisibleFrameRect(pMovieImpl, &rect);
    v12 = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(&result, penv, &rect);
    Scaleform::GFx::AS2::Value::operator=(val, v12);
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
    return 1;
  }
  v14 = penv->StringContext.SWFVersion > 6u;
  v15 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "safeRect",
          8u,
          0);
  v16 = v15;
  ++v15->RefCount;
  if ( v14 )
  {
    v17 = v15 == name->pNode;
  }
  else
  {
    if ( !v15->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v15);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v17 = v16->pLower == name->pNode->pLower;
  }
  v18 = v17;
  v9 = v16->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( v18 )
  {
    v19 = penv;
    v20 = penv->Target->pASRoot->pMovieImpl;
    v20->GetSafeRect(v20, (Scaleform::Render::Rect<float> *)&result);
    if ( *(float *)&result.V.FunctionValue.pLocalFrame <= (double)*(float *)&result.T.Type
      || *((float *)&result.NV + 3) <= (double)*(float *)&result.V.pStringNode )
    {
      v21 = penv->Target->pASRoot->pMovieImpl;
      v22 = v21->GetVisibleFrameRect(v21, &rect);
      Scaleform::Render::Rect<float>::operator=((Scaleform::Render::Rect<float> *)&result, v22);
    }
    goto LABEL_28;
  }
  v24 = penv->StringContext.SWFVersion > 6u;
  v25 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "originalRect",
          0xCu,
          0);
  v26 = v25;
  ++v25->RefCount;
  if ( v24 )
  {
    v27 = v25 == name->pNode;
  }
  else
  {
    if ( !v25->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v25);
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v27 = v26->pLower == name->pNode->pLower;
  }
  v28 = v27;
  v9 = v26->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  if ( !v28 )
  {
    this = v31;
    return ((int (__thiscall *)(Scaleform::GFx::AS2::StageCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             p_StringContext,
             name,
             val);
  }
  v19 = penv;
  v29 = penv->Target->pASRoot->pMovieImpl;
  v30 = (int)v29->GetMovieDef(v29);
  (*(void (__thiscall **)(int, Scaleform::GFx::AS2::Value *))(*(_DWORD *)v30 + 40))(v30, &result);
LABEL_28:
  RectangleObject = Scaleform::GFx::AS2::StageCtorFunction::CreateRectangleObject(
                      (Scaleform::GFx::AS2::Value *)&rect,
                      v19,
                      (const Scaleform::Render::Rect<float> *)&result);
  Scaleform::GFx::AS2::Value::operator=(val, RectangleObject);
  if ( LOBYTE(rect.x1) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&rect);
  return 1;
}
