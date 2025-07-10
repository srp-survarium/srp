void __thiscall Scaleform::GFx::AS2::BevelFilterObject::BevelFilterObject(
        Scaleform::GFx::AS2::BevelFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::BevelFilter *v4; // eax
  Scaleform::Render::Filter *v5; // eax
  Scaleform::Render::Filter *v6; // edi
  Scaleform::RefCountVImpl *v7; // ecx

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BevelFilterObject_vtbl *)&Scaleform::GFx::AS2::BlurFilterObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapFilterObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFilter.pObject = 0;
  pObject = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFilter.pObject = 0;
  v4 = (Scaleform::Render::BevelFilter *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(
                                           0x3Cu,
                                           (Scaleform::MemAddressStub *)this);
  if ( v4 )
  {
    Scaleform::Render::BevelFilter::BevelFilter(v4, 4.0, 4.0, 1u);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->pFilter.pObject = v6;
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BevelFilterObject_vtbl *)&Scaleform::GFx::AS2::BlurFilterObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BevelFilterObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
}
