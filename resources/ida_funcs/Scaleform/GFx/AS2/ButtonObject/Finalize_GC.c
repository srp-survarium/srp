void __thiscall Scaleform::GFx::AS2::ButtonObject::Finalize_GC(Scaleform::GFx::AS2::ColorObject *this)
{
  Scaleform::WeakPtrProxy *pObject; // eax

  pObject = this->pCharacter.pProxy.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
