void __thiscall Scaleform::GFx::AS2::ArrayObject::ArrayObject(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ArrayObject_vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->LogPtr = 0;
  this->Elements.Data.Data = 0;
  this->Elements.Data.Size = 0;
  this->Elements.Data.Policy.Capacity = 0;
  Scaleform::StringLH::StringLH(&this->StringValue);
  this->RecursionCount = 0;
  this->LengthValueOverriden = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Array);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
}
