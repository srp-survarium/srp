void __thiscall Scaleform::GFx::AS2::TextFieldObject::Finalize_GC(Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::WeakPtrProxy *pObject; // eax

  pObject = this->pTextField.pProxy.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pIMECompositionStringStyles);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
