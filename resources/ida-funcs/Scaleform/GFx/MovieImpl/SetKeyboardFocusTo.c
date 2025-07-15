void __thiscall Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        Scaleform::Ptr<Scaleform::GFx::Sprite> controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::State *v5; // eax
  Scaleform::Ptr<Scaleform::GFx::Sprite> v6; // ebx
  Scaleform::GFx::Sprite *pObject; // ebp
  Scaleform::GFx::Sprite *pParent; // edi
  Scaleform::GFx::FocusGroupDescr *v9; // ebp
  Scaleform::GFx::FocusMovedType v10; // [esp-4h] [ebp-18h]
  Scaleform::RefCountVImpl *v11; // [esp+10h] [ebp-4h]

  v5 = this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
  v6.pObject = controllerIdx.pObject;
  v11 = (Scaleform::RefCountVImpl *)v5;
  if ( v5 && v5[1].__vftable )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[*((unsigned __int8 *)&controllerIdx.pObject[86].pRenNode.pObject
                                                                       + (unsigned int)this)].LastFocused,
      &controllerIdx);
    pObject = controllerIdx.pObject;
    if ( controllerIdx.pObject )
    {
      ++controllerIdx.pObject->RefCount;
      Scaleform::RefCountNTSImpl::Release(pObject);
    }
    pParent = ch;
    if ( pObject != ch )
      pParent = (Scaleform::GFx::Sprite *)(*(int (__thiscall **)(volatile int, Scaleform::GFx::MovieImpl *, Scaleform::GFx::Sprite *, Scaleform::GFx::Sprite *, _DWORD))(*(_DWORD *)v11[1].RefCount + 64))(
                                            v11[1].RefCount,
                                            this,
                                            pObject,
                                            ch,
                                            0);
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
  else
  {
    pParent = ch;
  }
  v9 = &this->FocusGroups[*((unsigned __int8 *)&v6.pObject[86].pRenNode.pObject + (unsigned int)this)];
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
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
}
