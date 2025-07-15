char __thiscall Scaleform::GFx::MovieImpl::SetFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        Scaleform::Ptr<Scaleform::GFx::Sprite> controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::Sprite *pObject; // ebx
  Scaleform::GFx::Sprite *v6; // esi

  pObject = controllerIdx.pObject;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[*((unsigned __int8 *)&controllerIdx.pObject[86].pRenNode.pObject
                                                                     + (unsigned int)this)].LastFocused,
    &controllerIdx);
  v6 = controllerIdx.pObject;
  if ( controllerIdx.pObject )
  {
    ++controllerIdx.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(v6);
  }
  if ( v6 == ch )
  {
    if ( !v6 )
      return 0;
LABEL_5:
    Scaleform::RefCountNTSImpl::Release(v6);
    return 0;
  }
  this->FocusRectChanged = 1;
  if ( v6 && v6->pParent && !v6->OnLosingKeyboardFocus(v6, ch, (unsigned int)pObject, fmt) )
    goto LABEL_5;
  Scaleform::GFx::MovieImpl::TransferFocus(this, ch, (unsigned int)pObject, fmt);
  if ( ch )
    ch->OnGettingKeyboardFocus(ch, (unsigned int)pObject, fmt);
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  return 1;
}
