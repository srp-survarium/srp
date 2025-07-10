void __thiscall Scaleform::GFx::LoaderTask::~LoaderTask(Scaleform::GFx::LoaderTask *this)
{
  Scaleform::GFx::LoadStates *pObject; // eax
  Scaleform::RefCountVImpl *v3; // ecx

  pObject = this->pLoadStates.pObject;
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::LoaderTask::`vftable';
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(pObject->pLoaderImpl.pObject, this);
  v3 = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
