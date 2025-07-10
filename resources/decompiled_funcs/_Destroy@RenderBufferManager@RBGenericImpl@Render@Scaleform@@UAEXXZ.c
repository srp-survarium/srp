void __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::Destroy(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->Reset(this);
  this->DefImageFormat = Image_None;
  pObject = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pTextureManager.pObject = 0;
}
