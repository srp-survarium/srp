void __thiscall Scaleform::GFx::AS2::DateObject::DateObject(
        Scaleform::GFx::AS2::DateObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::DateObject_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::DateObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Date = 0;
  this->Time = 0;
  this->Year = 0;
  this->JDate = 0;
  this->LDate = 0;
  this->LTime = 0;
  this->LYear = 0;
  this->LJDate = 0;
  this->LocalOffset = 0;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Date);
  this->Set__proto__(&this->Scaleform::GFx::AS2::ObjectInterface, &penv->StringContext, Prototype);
}
