Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__thiscall Scaleform::GFx::MovieImpl::GetFocusedCharacter(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result,
        Scaleform::Ptr<Scaleform::GFx::Sprite> controllerIdx)
{
  Scaleform::GFx::Sprite *pObject; // ecx

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->FocusGroups[*((unsigned __int8 *)&controllerIdx.pObject[86].pRenNode.pObject
                                                                     + (unsigned int)this)].LastFocused,
    &controllerIdx);
  pObject = controllerIdx.pObject;
  if ( controllerIdx.pObject )
    ++controllerIdx.pObject->RefCount;
  result->pObject = pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  return result;
}
