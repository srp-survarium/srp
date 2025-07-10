void __thiscall Scaleform::GFx::AS2::StyleSheetObject::StyleSheetObject(
        Scaleform::GFx::AS2::StyleSheetObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StyleSheetObject_vtbl *)&Scaleform::GFx::AS2::StyleSheetObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StyleSheetObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->CSS.__vftable = (Scaleform::GFx::Text::StyleManager_vtbl *)&Scaleform::GFx::Text::StyleManager::`vftable';
  this->CSS.Styles.mHash.pTable = 0;
  this->CSS.TempKey.Type = CSS_None;
  Scaleform::StringLH::StringLH(&this->CSS.TempKey.Value);
  this->CSS.State = Ready;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
}
