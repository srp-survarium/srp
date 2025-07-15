Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__thiscall Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
        Scaleform::GFx::MouseState *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result,
        Scaleform::Ptr<Scaleform::GFx::Sprite> buttonIdx)
{
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v3; // eax
  Scaleform::GFx::Sprite *pObject; // ecx

  if ( (unsigned int)buttonIdx.pObject < this->MouseButtonDownEntities.Data.Size )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->MouseButtonDownEntities.Data.Data[(int)buttonIdx.pObject],
      &buttonIdx);
    pObject = buttonIdx.pObject;
    if ( buttonIdx.pObject )
      ++buttonIdx.pObject->RefCount;
    result->pObject = pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    return result;
  }
  else
  {
    v3 = result;
    result->pObject = 0;
  }
  return v3;
}
