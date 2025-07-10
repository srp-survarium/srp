void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ColorTransformObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::Render::Cxform::Cxform(&this->mColorTransform);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
  this->Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
  this->Constructor.Flags = 0;
  this->Constructor.Function = 0;
  this->Constructor.pLocalFrame = 0;
  this->__Constructor__.Flags = 0;
  this->__Constructor__.Function = 0;
  this->__Constructor__.pLocalFrame = 0;
  this->pInterfaces = 0;
  this->Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable';
  Scaleform::GFx::AS2::GASPrototypeBase::Init(&this->Scaleform::GFx::AS2::GASPrototypeBase, this, psc, constructor);
}
