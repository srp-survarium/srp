Scaleform::GFx::AS2::BitmapDataProto *__thiscall Scaleform::GFx::AS2::BitmapDataProto::`scalar deleting destructor'(
        Scaleform::GFx::AS2::BitmapDataProto *this,
        char a2)
{
  Scaleform::GFx::AS2::GASPrototypeBase *v3; // ecx
  Scaleform::GFx::MovieDef *pObject; // ecx
  Scaleform::GFx::ImageResource *v5; // ecx

  v3 = &this->Scaleform::GFx::AS2::GASPrototypeBase;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BitmapData::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BitmapDataProto_vtbl *)&Scaleform::GFx::AS2::BitmapDataProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BitmapData::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapDataProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::BitmapDataProto::`vftable';
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(v3);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BitmapData::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BitmapDataProto_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::BitmapData::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  pObject = this->pMovieDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  v5 = this->pImageRes.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
