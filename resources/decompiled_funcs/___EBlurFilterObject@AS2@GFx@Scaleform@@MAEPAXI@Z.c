Scaleform::GFx::AS2::BevelFilterObject *__thiscall Scaleform::GFx::AS2::BlurFilterObject::`vector deleting destructor'(
        Scaleform::GFx::AS2::BevelFilterObject *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BevelFilterObject_vtbl *)&Scaleform::GFx::AS2::BlurFilterObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapFilterObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  pObject = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
