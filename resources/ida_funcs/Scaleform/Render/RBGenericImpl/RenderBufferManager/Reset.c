void __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::Reset(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_ThisFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_PrevFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_LRU);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_Reuse_ThisFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_Reuse_LRU);
}
