bool __thiscall Scaleform::GFx::MovieImpl::IsFocused(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InteractiveObject *ch,
        unsigned int controllerIdx)
{
  Scaleform::GFx::InteractiveObject *v3; // esi

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
  v3 = (Scaleform::GFx::InteractiveObject *)controllerIdx;
  if ( controllerIdx )
  {
    ++*(_DWORD *)(controllerIdx + 4);
    Scaleform::RefCountNTSImpl::Release(v3);
  }
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  return v3 == ch;
}
