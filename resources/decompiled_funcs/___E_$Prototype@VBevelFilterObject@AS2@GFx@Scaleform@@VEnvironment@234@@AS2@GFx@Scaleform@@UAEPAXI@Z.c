Scaleform::GFx::AS2::BevelFilterProto *__thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment>::`vector deleting destructor'(
        Scaleform::GFx::AS2::BevelFilterProto *this,
        char a2)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v3; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx

  v3 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BevelFilterObject::Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BevelFilterProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BevelFilterObject::Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::BevelFilterProto::`vftable';
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v3);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BevelFilterObject::Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BevelFilterProto_vtbl *)&Scaleform::GFx::AS2::BlurFilterObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BevelFilterObject::Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapFilterObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  pObject = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
