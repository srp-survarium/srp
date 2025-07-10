void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::~Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v2; // ecx
  Scaleform::GFx::Text::IMEStyle *pIMECompositionStringStyles; // edx
  Scaleform::WeakPtrProxy *pObject; // eax

  v2 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  this->Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v2->__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::`vftable';
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v2);
  pIMECompositionStringStyles = this->pIMECompositionStringStyles;
  this->Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pIMECompositionStringStyles);
  pObject = this->pTextField.pProxy.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  Scaleform::GFx::AS2::Object::~Object(this);
}
