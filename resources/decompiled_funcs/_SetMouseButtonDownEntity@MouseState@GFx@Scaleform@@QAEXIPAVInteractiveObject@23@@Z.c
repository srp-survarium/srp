void __thiscall Scaleform::GFx::MouseState::SetMouseButtonDownEntity(
        Scaleform::GFx::MouseState *this,
        unsigned int buttonIdx,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v4; // esi
  Scaleform::WeakPtrProxy *WeakProxy; // edi
  Scaleform::WeakPtrProxy *pObject; // eax
  bool v7; // zf
  Scaleform::WeakPtrProxy *v8; // eax

  if ( buttonIdx >= this->MouseButtonDownEntities.Data.Size )
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->MouseButtonDownEntities,
      buttonIdx + 1);
  v4 = &this->MouseButtonDownEntities.Data.Data[buttonIdx];
  if ( pch )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pch);
    pObject = v4->pProxy.pObject;
    if ( v4->pProxy.pObject )
    {
      v7 = pObject->RefCount-- == 1;
      if ( v7 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    v4->pProxy.pObject = WeakProxy;
  }
  else
  {
    v8 = v4->pProxy.pObject;
    if ( v4->pProxy.pObject )
    {
      v7 = v8->RefCount-- == 1;
      if ( v7 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
    v4->pProxy.pObject = 0;
  }
}
