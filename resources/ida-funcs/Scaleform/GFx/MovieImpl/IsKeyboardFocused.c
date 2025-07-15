BOOL __thiscall Scaleform::GFx::MovieImpl::IsKeyboardFocused(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Sprite *ch,
        Scaleform::Ptr<Scaleform::GFx::Sprite> controllerIdx)
{
  Scaleform::GFx::Sprite *pObject; // ebp
  Scaleform::GFx::Sprite *v5; // esi

  pObject = controllerIdx.pObject;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[(unsigned int)controllerIdx.pObject]].LastFocused,
    &controllerIdx);
  v5 = controllerIdx.pObject;
  if ( controllerIdx.pObject )
  {
    ++controllerIdx.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(v5);
  }
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  return v5 == ch
      && this->FocusGroups[*((unsigned __int8 *)&pObject[86].pRenNode.pObject + (_DWORD)this)].FocusRectShown;
}
