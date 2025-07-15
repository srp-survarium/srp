void __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::RenderBufferManager(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        bool requireExactDepthStencil,
        unsigned int memReuseLimit,
        unsigned int memAbsoluteLimit)
{
  this->__vftable = (Scaleform::Render::RBGenericImpl::RenderBufferManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::RBGenericImpl::RenderBufferManager_vtbl *)&Scaleform::Render::RBGenericImpl::RenderBufferManager::`vftable';
  this->pTextureManager.pObject = 0;
  this->ReuseLimit = 0;
  this->AllocSize = 0;
  this->DefImageFormat = Image_None;
  this->RequirePow2 = 0;
  this->CtorReuseLimit = memReuseLimit;
  this->RequireExactDepthStencil = requireExactDepthStencil;
  this->AbsoluteLimit = memAbsoluteLimit;
  this->BufferCache[1].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1];
  this->BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1];
  this->BufferCache[2].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[2];
  this->BufferCache[2].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[2];
  this->BufferCache[3].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[3];
  this->BufferCache[3].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[3];
  this->BufferCache[4].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[4];
  this->BufferCache[4].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[4];
  this->BufferCache[5].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[5];
  this->BufferCache[5].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[5];
  this->BufferCache[0].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)this->BufferCache;
  this->BufferCache[0].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)this->BufferCache;
  this->BufferCache[6].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[6];
  this->BufferCache[6].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[6];
}
