void __thiscall Scaleform::Render::ContextImpl::RTHandle::HandleData::HandleData(
        Scaleform::Render::ContextImpl::RTHandle::HandleData *this,
        Scaleform::Render::ContextImpl::Entry *entry,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::ContextLock *pObject; // ecx

  this->__vftable = (Scaleform::Render::ContextImpl::RTHandle::HandleData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::ContextImpl::RTHandle::HandleData_vtbl *)&Scaleform::Render::ContextImpl::RTHandle::HandleData::`vftable';
  pObject = context->pCaptureLock.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
  this->pContextLock.pObject = context->pCaptureLock.pObject;
  this->State = State_PreCapture;
  this->pEntry = entry;
}
