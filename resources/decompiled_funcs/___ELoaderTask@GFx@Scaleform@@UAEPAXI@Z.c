Scaleform::GFx::LoaderTask *__thiscall Scaleform::GFx::LoaderTask::`vector deleting destructor'(
        Scaleform::GFx::LoaderTask *this,
        char a2)
{
  Scaleform::GFx::LoadStates *pObject; // eax
  Scaleform::RefCountVImpl *v4; // ecx

  pObject = this->pLoadStates.pObject;
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::LoaderTask::`vftable';
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(pObject->pLoaderImpl.pObject, this);
  v4 = (Scaleform::RefCountVImpl *)this->pLoadStates.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
