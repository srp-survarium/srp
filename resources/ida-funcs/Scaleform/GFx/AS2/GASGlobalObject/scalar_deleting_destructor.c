Scaleform::GFx::AS2::GASGlobalObject *__thiscall Scaleform::GFx::AS2::GASGlobalObject::`scalar deleting destructor'(
        Scaleform::GFx::AS2::GASGlobalObject *this,
        char a2)
{
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::GASGlobalObject_vtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
