Scaleform::GFx::AS2::BitmapData *__thiscall Scaleform::GFx::AS2::BitmapData::`vector deleting destructor'(
        Scaleform::GFx::AS2::BitmapData *this,
        char a2)
{
  Scaleform::GFx::MovieDef *pObject; // ecx
  Scaleform::GFx::ImageResource *v4; // ecx

  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BitmapData_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  pObject = this->pMovieDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  v4 = this->pImageRes.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
