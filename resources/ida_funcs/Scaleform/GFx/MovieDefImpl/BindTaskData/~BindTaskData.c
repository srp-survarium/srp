void __thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::~BindTaskData(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::GFx::LoadUpdateSync *pObject; // eax
  Scaleform::GFx::LoadUpdateSync *v3; // eax
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::MovieDataDef *v5; // ecx

  pObject = this->pBindUpdate.pObject;
  this->__vftable = (Scaleform::GFx::MovieDefImpl::BindTaskData_vtbl *)&Scaleform::GFx::MovieDefImpl::BindTaskData::`vftable';
  if ( pObject )
    Scaleform::Mutex::DoLock(&pObject->mMutex);
  Scaleform::GFx::ResourceBinding::Destroy(&this->ResourceBinding);
  v3 = this->pBindUpdate.pObject;
  if ( v3 )
    Scaleform::Mutex::Unlock(&v3->mMutex);
  v4 = (Scaleform::RefCountVImpl *)this->pBindUpdate.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ShapeMeshProvider *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>,Scaleform::HashNode<Scaleform::Render::ShapeMeshProvider *,Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider>,Scaleform::FixedSizeHash<Scaleform::Render::ShapeMeshProvider *>>::NodeHashF>>::Clear(&this->BoundShapeMeshProviders.mHash);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>(&this->ResourceImports.Data);
  Scaleform::Lock::~Lock(&this->ImportSourceLock);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>(&this->ImportSourceMovies.Data);
  Scaleform::GFx::ResourceBinding::~ResourceBinding(&this->ResourceBinding);
  v5 = this->pDataDef.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
