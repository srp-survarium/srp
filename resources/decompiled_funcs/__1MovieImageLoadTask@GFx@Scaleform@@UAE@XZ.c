void __thiscall Scaleform::GFx::MovieImageLoadTask::~MovieImageLoadTask(Scaleform::GFx::MovieImageLoadTask *this)
{
  Scaleform::GFx::ImageResource *pObject; // ecx
  Scaleform::File *v3; // ecx
  Scaleform::GFx::MovieDefImpl *v4; // ecx
  Scaleform::GFx::MovieDataDef *v5; // ecx
  Scaleform::GFx::LoadStates *v6; // eax
  Scaleform::RefCountVImpl *v7; // ecx

  pObject = this->pImageRes.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  v3 = this->pImageFile.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
  v4 = this->pDefImpl.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  v5 = this->pDef.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  v6 = this->pLoadStates.pObject;
  this->__vftable = (Scaleform::GFx::MovieImageLoadTask_vtbl *)&Scaleform::GFx::LoaderTask::`vftable';
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(v6->pLoaderImpl.pObject, this);
  v7 = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->__vftable = (Scaleform::GFx::MovieImageLoadTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
