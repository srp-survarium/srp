char __thiscall Scaleform::GFx::AS2::IMEManager::IsTextFieldFocused(Scaleform::GFx::AS3::IMEManager *this)
{
  Scaleform::GFx::Movie *pMovie; // eax
  Scaleform::GFx::TextField *pObject; // esi
  char IsTextFieldFocused; // bl
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+4h] [ebp-4h] BYREF

  pMovie = this->pMovie;
  if ( !pMovie )
    return 0;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovie[4 * LOBYTE(pMovie[1013].RefCount) + 950].RefCount,
    (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&result);
  pObject = (Scaleform::GFx::TextField *)result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
  IsTextFieldFocused = Scaleform::GFx::AS2::IMEManager::IsTextFieldFocused(this, pObject);
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  return IsTextFieldFocused;
}
