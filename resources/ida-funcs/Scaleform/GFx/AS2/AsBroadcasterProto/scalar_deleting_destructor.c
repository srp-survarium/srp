Scaleform::GFx::AS2::AsBroadcasterProto *__thiscall Scaleform::GFx::AS2::AsBroadcasterProto::`scalar deleting destructor'(
        Scaleform::GFx::AS2::AsBroadcasterProto *this,
        char a2)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v3; // ecx

  v3 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::AsBroadcaster::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::AsBroadcasterProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::AsBroadcaster::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AsBroadcasterProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::AsBroadcaster,Scaleform::GFx::AS2::Environment>::`vftable';
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v3);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
