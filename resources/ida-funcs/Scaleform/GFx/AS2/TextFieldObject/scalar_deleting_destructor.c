Scaleform::GFx::AS2::TextFieldObject *__thiscall Scaleform::GFx::AS2::TextFieldObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::TextFieldObject *this,
        char a2)
{
  Scaleform::GFx::Text::IMEStyle *pIMECompositionStringStyles; // edx
  Scaleform::WeakPtrProxy *pObject; // eax

  pIMECompositionStringStyles = this->pIMECompositionStringStyles;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TextFieldObject_vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pIMECompositionStringStyles);
  pObject = this->pTextField.pProxy.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
