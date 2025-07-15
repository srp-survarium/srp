void __thiscall Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap(Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::MovieDefImpl *pObject; // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // edi
  Scaleform::GFx::ImageResource *v4; // ecx
  Scaleform::GFx::MovieDefImpl *v5; // ecx

  pObject = this->pDefImpl.pObject;
  v3 = &this->Scaleform::GFx::AS3::AvmDisplayObj;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS3::AvmBitmap_vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable';
  if ( pObject )
    Scaleform::GFx::MovieImpl::AddMovieDefToKillList(this->pASRoot->pMovieImpl, pObject);
  this->AvmObjOffset = 0;
  v4 = this->pImage.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  v5 = this->pDefImpl.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(v3);
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
}
