Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__thiscall Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
        Scaleform::GFx::MouseState *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result,
        unsigned int buttonIdx)
{
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v3; // eax
  Scaleform::GFx::InteractiveObject *v4; // ecx

  if ( buttonIdx < this->MouseButtonDownEntities.Data.Size )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->MouseButtonDownEntities.Data.Data[buttonIdx],
      (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&buttonIdx);
    v4 = (Scaleform::GFx::InteractiveObject *)buttonIdx;
    if ( buttonIdx )
      ++*(_DWORD *)(buttonIdx + 4);
    result->pObject = v4;
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
    return result;
  }
  else
  {
    v3 = result;
    result->pObject = 0;
  }
  return v3;
}
