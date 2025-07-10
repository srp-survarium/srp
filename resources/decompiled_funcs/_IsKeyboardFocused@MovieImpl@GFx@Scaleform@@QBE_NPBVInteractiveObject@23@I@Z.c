BOOL __thiscall Scaleform::GFx::MovieImpl::IsKeyboardFocused(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InteractiveObject *ch,
        unsigned int controllerIdx)
{
  unsigned int v3; // ebp
  Scaleform::GFx::InteractiveObject *v5; // esi

  v3 = controllerIdx;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
  v5 = (Scaleform::GFx::InteractiveObject *)controllerIdx;
  if ( controllerIdx )
  {
    ++*(_DWORD *)(controllerIdx + 4);
    Scaleform::RefCountNTSImpl::Release(v5);
  }
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  return v5 == ch && this->FocusGroups[this->FocusGroupIndexes[v3]].FocusRectShown;
}
