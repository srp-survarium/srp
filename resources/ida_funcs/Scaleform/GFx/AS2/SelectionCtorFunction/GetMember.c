char __thiscall Scaleform::GFx::AS2::SelectionCtorFunction::GetMember(
        Scaleform::GFx::AS2::SelectionCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::AS2::Value *v6; // eax
  int v8; // eax
  int v9; // edi
  int v10; // eax
  Scaleform::GFx::Sprite *ModalClip; // eax
  int FocusGroupsCnt; // edx
  Scaleform::GFx::AS2::Value v14; // [esp+14h] [ebp-10h] BYREF

  p_StringContext = &penv->StringContext;
  if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::SelectionCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             p_StringContext,
             name,
             pval);
  pMovieImpl = penv->Target->pASRoot->pMovieImpl;
  if ( strcmp(name->pNode->pData, "captureFocus") )
  {
    if ( !strcmp(name->pNode->pData, "disableFocusAutoRelease") )
    {
      v8 = (pMovieImpl->Flags >> 22) & 3;
      if ( v8 == 3 )
      {
        v9 = -1;
        goto LABEL_12;
      }
      if ( v8 )
      {
        v9 = (pMovieImpl->Flags >> 22) & 3;
LABEL_12:
        Scaleform::GFx::AS2::Value::DropRefs(pval);
        pval->T.Type = 2;
        pval->V.BooleanValue = v9 == 1;
        return 1;
      }
LABEL_13:
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 0;
      return 1;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "alwaysEnableArrowKeys") )
    {
      v10 = HIBYTE(pMovieImpl->Flags) & 3;
      goto LABEL_16;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "alwaysEnableKeyboardPress") )
    {
      v10 = (pMovieImpl->Flags >> 26) & 3;
      if ( v10 == 3 )
      {
        v10 = -1;
      }
      else if ( !v10 )
      {
        goto LABEL_13;
      }
      goto LABEL_30;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "disableFocusRolloverEvent") )
    {
      v10 = (pMovieImpl->Flags >> 28) & 3;
      if ( v10 == 3 )
      {
        v10 = -1;
      }
      else if ( !v10 )
      {
        goto LABEL_13;
      }
      goto LABEL_30;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "disableFocusKeys") )
    {
      v10 = pMovieImpl->Flags >> 30;
LABEL_16:
      if ( v10 == 3 )
      {
        v10 = -1;
      }
      else if ( !v10 )
      {
        goto LABEL_13;
      }
LABEL_30:
      Scaleform::GFx::AS2::Value::SetBool(pval, v10 == 1);
      return 1;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "modalClip") )
    {
      ModalClip = Scaleform::GFx::MovieImpl::GetModalClip(pMovieImpl, 0);
      Scaleform::GFx::AS2::Value::SetAsCharacter(pval, ModalClip);
      return 1;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "moveFocus") )
    {
      Scaleform::GFx::AS2::Value::Value(&v14, p_StringContext, Scaleform::GFx::AS2::SelectionCtorFunction::MoveFocus);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "findFocus") )
    {
      Scaleform::GFx::AS2::Value::Value(&v14, p_StringContext, Scaleform::GFx::AS2::SelectionCtorFunction::FindFocus);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "setModalClip") )
    {
      Scaleform::GFx::AS2::Value::Value(&v14, p_StringContext, Scaleform::GFx::AS2::SelectionCtorFunction::SetModalClip);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "getModalClip") )
    {
      Scaleform::GFx::AS2::Value::Value(&v14, p_StringContext, Scaleform::GFx::AS2::SelectionCtorFunction::GetModalClip);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "setControllerFocusGroup") )
    {
      Scaleform::GFx::AS2::Value::Value(
        &v14,
        p_StringContext,
        (void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *))Scaleform::GFx::AS2::SelectionCtorFunction::SetControllerFocusGroup);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "getControllerFocusGroup") )
    {
      Scaleform::GFx::AS2::Value::Value(
        &v14,
        p_StringContext,
        Scaleform::GFx::AS2::SelectionCtorFunction::GetControllerFocusGroup);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "getFocusBitmask") )
    {
      Scaleform::GFx::AS2::Value::Value(
        &v14,
        p_StringContext,
        Scaleform::GFx::AS2::SelectionCtorFunction::GetFocusBitmask);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "numFocusGroups") )
    {
      FocusGroupsCnt = pMovieImpl->FocusGroupsCnt;
      v14.T.Type = 4;
      v14.NV.Int32Value = FocusGroupsCnt;
      v6 = &v14;
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "getControllerMaskByFocusGroup") )
    {
      Scaleform::GFx::AS2::Value::Value(
        &v14,
        p_StringContext,
        Scaleform::GFx::AS2::SelectionCtorFunction::GetControllerMaskByFocusGroup);
      goto LABEL_4;
    }
    if ( Scaleform::GFx::ASString::operator==(name, "getFocusArray") )
    {
      Scaleform::GFx::AS2::Value::Value(
        &v14,
        p_StringContext,
        Scaleform::GFx::AS2::SelectionCtorFunction::GetFocusArray);
      goto LABEL_4;
    }
    return ((int (__thiscall *)(Scaleform::GFx::AS2::SelectionCtorFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->IsNull)(
             this,
             p_StringContext,
             name,
             pval);
  }
  Scaleform::GFx::AS2::Value::Value(&v14, p_StringContext, Scaleform::GFx::AS2::SelectionCtorFunction::CaptureFocus);
LABEL_4:
  Scaleform::GFx::AS2::Value::operator=(pval, v6);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  return 1;
}
