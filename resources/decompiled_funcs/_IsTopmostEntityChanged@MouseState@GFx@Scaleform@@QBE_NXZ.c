char __thiscall Scaleform::GFx::MouseState::IsTopmostEntityChanged(Scaleform::GFx::MouseState *this)
{
  Scaleform::GFx::Sprite *pObject; // edi
  char v3; // bl
  Scaleform::GFx::Sprite *v4; // esi
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)this,
    &result);
  pObject = result.pObject;
  v3 = 1;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->PrevTopmostEntity,
    &result);
  v4 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    Scaleform::RefCountNTSImpl::Release(v4);
  }
  if ( pObject == v4 && (pObject || (*((_BYTE *)this + 52) & 1) != 0) && (v4 || (*((_BYTE *)this + 52) & 2) != 0) )
    v3 = 0;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  return v3;
}
