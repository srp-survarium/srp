void __thiscall Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::State *v5; // eax
  unsigned int v6; // ebx
  Scaleform::GFx::InteractiveObject *v7; // ebp
  Scaleform::GFx::Sprite *pParent; // edi
  Scaleform::GFx::FocusGroupDescr *v9; // ebp
  Scaleform::GFx::FocusMovedType v10; // [esp-4h] [ebp-18h]
  Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> pIMEManager; // [esp+10h] [ebp-4h]

  v5 = this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
  v6 = controllerIdx;
  pIMEManager.pObject = (Scaleform::GFx::IMEManagerBase *)v5;
  if ( v5 && v5[1].__vftable )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused,
      (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
    v7 = (Scaleform::GFx::InteractiveObject *)controllerIdx;
    if ( controllerIdx )
    {
      ++*(_DWORD *)(controllerIdx + 4);
      Scaleform::RefCountNTSImpl::Release(v7);
    }
    pParent = ch;
    if ( v7 != ch )
      pParent = (Scaleform::GFx::Sprite *)pIMEManager.pObject->pASIMEManager.pObject->HandleFocus(
                                            pIMEManager.pObject->pASIMEManager.pObject,
                                            this,
                                            v7,
                                            ch,
                                            0);
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
  }
  else
  {
    pParent = ch;
  }
  v9 = &this->FocusGroups[this->FocusGroupIndexes[v6]];
  if ( pParent && pParent->GetType(pParent) == MouseWheel )
  {
    if ( v9->FocusRectShown )
      this->FocusRectChanged = 1;
    v9->FocusRectShown = 0;
  }
  else
  {
    if ( !v9->FocusRectShown )
      this->FocusRectChanged = 1;
    v9->FocusRectShown = 1;
  }
  v10 = fmt;
  v9->LastFocusKeyCode = 0;
  if ( Scaleform::GFx::MovieImpl::SetFocusTo(this, pParent, v6, v10) && v9->FocusRectShown )
  {
    for ( ; pParent; pParent = (Scaleform::GFx::Sprite *)pParent->pParent )
    {
      if ( !pParent->GetVisible(pParent) )
        break;
    }
    if ( v9->FocusRectShown != (pParent == 0) )
      this->FocusRectChanged = 1;
    v9->FocusRectShown = pParent == 0;
  }
  if ( pIMEManager.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pIMEManager.pObject);
}
