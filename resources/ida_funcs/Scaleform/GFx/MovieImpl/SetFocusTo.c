char __thiscall Scaleform::GFx::MovieImpl::SetFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned int v4; // ebx
  Scaleform::GFx::InteractiveObject *v6; // esi

  v4 = controllerIdx;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
  v6 = (Scaleform::GFx::InteractiveObject *)controllerIdx;
  if ( controllerIdx )
  {
    ++*(_DWORD *)(controllerIdx + 4);
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
  if ( v6 && v6->pParent && !v6->OnLosingKeyboardFocus(v6, ch, v4, fmt) )
    goto LABEL_5;
  Scaleform::GFx::MovieImpl::TransferFocus(this, ch, v4, fmt);
  if ( ch )
    ch->OnGettingKeyboardFocus(ch, v4, fmt);
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  return 1;
}
