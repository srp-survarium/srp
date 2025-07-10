Scaleform::GFx::AS2::MovieClipProto *__thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::`scalar deleting destructor'(
        Scaleform::GFx::AS2::MovieClipProto *this,
        char a2)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v3; // ecx
  Scaleform::WeakPtrProxy *pObject; // eax

  v3 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::MovieClipObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MovieClipProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::MovieClipObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::`vftable';
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v3);
  pObject = this->pSprite.pProxy.pObject;
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
