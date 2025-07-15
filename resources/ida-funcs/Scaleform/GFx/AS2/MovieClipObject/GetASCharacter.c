Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::AS2::MovieClipObject::GetASCharacter(
        Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::GFx::Sprite *pObject; // esi
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+4h] [ebp-4h] BYREF

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->pTextField,
    (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(pObject);
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
  return pObject;
}
