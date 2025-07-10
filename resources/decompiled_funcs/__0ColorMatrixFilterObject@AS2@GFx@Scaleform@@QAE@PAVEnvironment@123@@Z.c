void __thiscall Scaleform::GFx::AS2::ColorMatrixFilterObject::ColorMatrixFilterObject(
        Scaleform::GFx::AS2::ColorMatrixFilterObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::ColorMatrixFilter *v4; // eax
  Scaleform::Render::Filter *v5; // eax
  Scaleform::Render::Filter *v6; // edi
  Scaleform::RefCountVImpl *v7; // ecx

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ColorMatrixFilterObject_vtbl *)&Scaleform::GFx::AS2::BlurFilterObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapFilterObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFilter.pObject = 0;
  pObject = (Scaleform::RefCountVImpl *)this->pFilter.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFilter.pObject = 0;
  v4 = (Scaleform::Render::ColorMatrixFilter *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(
                                                 0x60u,
                                                 (Scaleform::MemAddressStub *)this);
  if ( v4 )
  {
    Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v4);
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
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ColorMatrixFilterObject_vtbl *)&Scaleform::GFx::AS2::BlurFilterObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::BitmapFilterObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ColorMatrixFilterObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
}
