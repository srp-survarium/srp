Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__thiscall Scaleform::GFx::MovieImpl::GetFocusedCharacter(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result,
        unsigned int controllerIdx)
{
  Scaleform::GFx::InteractiveObject *v3; // ecx

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[this->FocusGroupIndexes[controllerIdx]].LastFocused,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
  v3 = (Scaleform::GFx::InteractiveObject *)controllerIdx;
  if ( controllerIdx )
    ++*(_DWORD *)(controllerIdx + 4);
  result->pObject = v3;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  return result;
}
