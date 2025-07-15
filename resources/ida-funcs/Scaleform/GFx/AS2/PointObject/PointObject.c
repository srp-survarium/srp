void __thiscall Scaleform::GFx::AS2::PointObject::PointObject(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::PointObject_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::PointObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Point);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  Scaleform::GFx::AS2::PointObject::SetProperties(this, &penv->StringContext, Point_DefaultParams);
}
