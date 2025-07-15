void __thiscall Scaleform::GFx::AS2::BitmapData::BitmapData(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BitmapData_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pImageRes.pObject = 0;
  this->pMovieDef.pObject = 0;
  Scaleform::GFx::AS2::BitmapData::commonInit(this, penv);
}
