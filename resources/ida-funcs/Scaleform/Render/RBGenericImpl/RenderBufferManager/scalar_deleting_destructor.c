Scaleform::Render::RBGenericImpl::RenderBufferManager *__thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::`scalar deleting destructor'(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  this->__vftable = (Scaleform::Render::RBGenericImpl::RenderBufferManager_vtbl *)&Scaleform::Render::RBGenericImpl::RenderBufferManager::`vftable';
  Scaleform::Render::RBGenericImpl::RenderBufferManager::Reset(this);
  this->DefImageFormat = Image_None;
  pObject = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pTextureManager.pObject = 0;
  v4 = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->__vftable = (Scaleform::Render::RBGenericImpl::RenderBufferManager_vtbl *)&Scaleform::Render::RenderBufferManager::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
