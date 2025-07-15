Scaleform::GFx::StateBagImpl *__thiscall Scaleform::GFx::StateBagImpl::`scalar deleting destructor'(
        Scaleform::GFx::StateBagImpl *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::StateBagImpl_vtbl *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::StateBagImpl,2>'};
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>_vtbl *)&Scaleform::GFx::StateBagImpl::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>'};
  Scaleform::Lock::~Lock(&this->StateLock);
  Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::Clear((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > *)&this->States);
  pObject = (Scaleform::RefCountVImpl *)this->pDelegate.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::StateBagImpl>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
