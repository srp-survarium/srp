char __thiscall Scaleform::GFx::MovieImpl::QueueSetFocusTo(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        Scaleform::GFx::InteractiveObject *ptopMostCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  Scaleform::GFx::Sprite *pObject; // edi
  Scaleform::GFx::Sprite *v8; // esi
  Scaleform::GFx::State *v10; // eax
  Scaleform::RefCountVImpl *v11; // ebx
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+24h] [ebp-4h] BYREF

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused,
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
  v8 = ch;
  if ( pObject == ch )
  {
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    return 0;
  }
  this->FocusRectChanged = 1;
  v10 = this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
  v11 = (Scaleform::RefCountVImpl *)v10;
  if ( v10 )
  {
    v8 = (Scaleform::GFx::Sprite *)(*((int (__thiscall **)(Scaleform::GFx::State_vtbl *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::Sprite *, Scaleform::GFx::Sprite *, Scaleform::GFx::InteractiveObject *))v10[1].~Scaleform::GFx::State
                                    + 16))(
                                     v10[1].__vftable,
                                     this,
                                     pObject,
                                     ch,
                                     ptopMostCh);
    if ( pObject == v8 )
      goto LABEL_11;
  }
  if ( !this->pASMovieRoot.pObject->NotifyOnFocusChange(
          this->pASMovieRoot.pObject,
          pObject,
          v8,
          controllerIdx,
          fmt,
          pfocusKeyInfo) )
  {
    if ( !v11 )
    {
LABEL_12:
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      return 0;
    }
LABEL_11:
    Scaleform::RefCountImpl::Release(v11);
    goto LABEL_12;
  }
  if ( v8 && !v8->IsFocusEnabled(v8, fmt) )
    v8 = 0;
  if ( pObject && pObject->pParent && !pObject->OnLosingKeyboardFocus(pObject, v8, controllerIdx, fmt) )
  {
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    Scaleform::RefCountNTSImpl::Release(pObject);
    return 0;
  }
  else
  {
    if ( v8 )
      v8->OnGettingKeyboardFocus(v8, controllerIdx, fmt);
    this->pASMovieRoot.pObject->NotifyQueueSetFocus(this->pASMovieRoot.pObject, v8, controllerIdx, fmt);
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    return 1;
  }
}
