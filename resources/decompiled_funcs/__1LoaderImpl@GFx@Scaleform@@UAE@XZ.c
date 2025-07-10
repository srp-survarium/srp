void __thiscall Scaleform::GFx::LoaderImpl::~LoaderImpl(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::GFx::ResourceWeakLib *pObject; // ecx
  Scaleform::GFx::StateBagImpl *v3; // ecx

  this->Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LoaderImpl_vtbl *)&Scaleform::GFx::LoaderImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::LoaderImpl,2>'};
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::LoaderImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>_vtbl *)&Scaleform::GFx::LoaderImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>'};
  Scaleform::GFx::LoaderImpl::CancelLoading(this);
  Scaleform::Lock::~Lock(&this->LoadProcessesLock);
  pObject = this->pWeakResourceLib.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  v3 = this->pStateBag.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoaderImpl>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
