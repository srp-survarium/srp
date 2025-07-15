void __thiscall Scaleform::GFx::AS2::MovieRoot::~MovieRoot(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::GlobalContext *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::Render::TreeContainer *v5; // ecx
  Scaleform::RefCountVImpl *v7; // ecx

  this->__vftable = (Scaleform::GFx::AS2::MovieRoot_vtbl *)&Scaleform::GFx::AS2::MovieRoot::`vftable';
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&this->SpritesWithHitArea);
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(
    this->BuiltinsMgr.pStringManager,
    (Scaleform::GFx::ASStringNode *)&this->BuiltinsMgr,
    0x9Cu);
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType::~ActionQueueType(&this->ActionQueue);
  if ( this->ExternalIntfRetVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->ExternalIntfRetVal);
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->MemContext.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::RefCountVImpl *)this->pASSupport.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = this->TopNode.pObject;
  if ( v5 )
  {
    if ( v5->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
  }
  this->__vftable = (Scaleform::GFx::AS2::MovieRoot_vtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  v7 = (Scaleform::RefCountVImpl *)this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
