void __thiscall Scaleform::GFx::AS2::XmlObject::XmlObject(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(this, penv);
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::XmlObject_vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_XML);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  this->BytesLoadedCurrent = -1.0;
  this->BytesLoadedTotal = -1.0;
  Scaleform::GFx::AS2::AsBroadcaster::Initialize(
    (unsigned __int8 *)&penv->StringContext,
    (Scaleform::GFx::AS2::LocalFrame **)penv,
    &penv->StringContext,
    &this->Scaleform::GFx::AS2::ObjectInterface);
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    penv,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &this->Scaleform::GFx::AS2::ObjectInterface);
}
