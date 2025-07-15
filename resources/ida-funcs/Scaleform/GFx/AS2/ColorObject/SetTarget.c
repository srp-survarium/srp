void __thiscall Scaleform::GFx::AS2::ColorObject::SetTarget(
        Scaleform::GFx::AS2::ColorObject *this,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::WeakPtrProxy *WeakProxy; // edi
  Scaleform::WeakPtrProxy *pObject; // eax
  bool v5; // zf
  Scaleform::WeakPtrProxy *v6; // eax

  if ( pcharacter )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pcharacter);
    pObject = this->pCharacter.pProxy.pObject;
    if ( pObject )
    {
      v5 = pObject->RefCount-- == 1;
      if ( v5 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pCharacter.pProxy.pObject = WeakProxy;
  }
  else
  {
    v6 = this->pCharacter.pProxy.pObject;
    if ( v6 )
    {
      v5 = v6->RefCount-- == 1;
      if ( v5 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    }
    this->pCharacter.pProxy.pObject = 0;
  }
}
