void __thiscall Scaleform::Render::ContextImpl::RTHandle::~RTHandle(Scaleform::Render::ContextImpl::RTHandle *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // ecx

  pObject = this->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
}
