void __thiscall Scaleform::GFx::StateBagImpl::StateBagImpl(
        Scaleform::GFx::StateBagImpl *this,
        Scaleform::GFx::Resource *pdelegate)
{
  Scaleform::GFx::StateBagImpl *pObject; // ecx

  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::StateBagImpl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::StateBagImpl_vtbl *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>'};
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>_vtbl *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>'};
  this->pDelegate.pObject = 0;
  this->States.pTable = 0;
  Scaleform::Lock::Lock(&this->StateLock, 0);
  if ( pdelegate )
    Scaleform::RefCountImpl::AddRef(pdelegate);
  pObject = this->pDelegate.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->pDelegate.pObject = (Scaleform::GFx::StateBagImpl *)pdelegate;
}
