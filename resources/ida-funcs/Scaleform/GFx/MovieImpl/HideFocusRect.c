void __thiscall Scaleform::GFx::MovieImpl::HideFocusRect(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> controllerIdx)
{
  Scaleform::GFx::Sprite *pObject; // ebx
  int v4; // eax
  char *v5; // ebp
  Scaleform::GFx::Sprite *v6; // esi

  pObject = controllerIdx.pObject;
  v4 = *((unsigned __int8 *)&controllerIdx.pObject[86].pRenNode.pObject + (unsigned int)this) << 6;
  v5 = (char *)this->FocusGroups + v4;
  if ( *(&this->FocusGroups[0].FocusRectShown + v4) )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)((char *)&this->FocusGroups[0].LastFocused + v4),
      &controllerIdx);
    v6 = controllerIdx.pObject;
    if ( controllerIdx.pObject )
    {
      ++controllerIdx.pObject->RefCount;
      Scaleform::RefCountNTSImpl::Release(v6);
      if ( v6->pParent && !v6->OnLosingKeyboardFocus(v6, 0, (unsigned int)pObject, GFx_FocusMovedByKeyboard) )
      {
        Scaleform::RefCountNTSImpl::Release(v6);
        return;
      }
      Scaleform::RefCountNTSImpl::Release(v6);
    }
  }
  v5[48] = 0;
  this->FocusRectChanged = 1;
}
