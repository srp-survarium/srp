void __thiscall Scaleform::Render::ContextImpl::RTHandle::~RTHandle(Scaleform::Render::ContextImpl::RTHandle *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
}
