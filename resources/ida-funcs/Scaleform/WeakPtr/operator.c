Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__thiscall Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
        Scaleform::WeakPtr<Scaleform::GFx::Sprite> *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result)
{
  Scaleform::WeakPtrProxy *pObject; // eax
  Scaleform::GFx::Sprite *v4; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v5; // eax

  pObject = this->pProxy.pObject;
  if ( !this->pProxy.pObject )
  {
LABEL_8:
    v5 = result;
    result->pObject = 0;
    return v5;
  }
  if ( !pObject->pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    this->pProxy.pObject = 0;
    goto LABEL_8;
  }
  v4 = (Scaleform::GFx::Sprite *)pObject->pObject;
  if ( v4->RefCount )
  {
    ++v4->RefCount;
    result->pObject = v4;
    return result;
  }
  else
  {
    v5 = result;
    result->pObject = 0;
  }
  return v5;
}
