void __thiscall Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(
        Scaleform::GFx::AS2::XmlNodeObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::XmlNodeObject_vtbl *)&Scaleform::GFx::AS2::XmlObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pRootNode.pObject = 0;
  this->pRealNode = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_XMLNode);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}
