Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::CacheData **pdata,
        const Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType type,
        Scaleform::Render::ImageFormat format,
        unsigned int requestSize)
{
  unsigned int AbsoluteLimit; // eax
  Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult result; // eax
  Scaleform::Render::RBGenericImpl::CacheData *Match; // eax
  Scaleform::Render::RBGenericImpl::CacheData *v10; // eax
  Scaleform::Render::RBGenericImpl::CacheData *v11; // eax
  Scaleform::Render::RBGenericImpl::CacheData *v12; // eax
  Scaleform::Render::RBGenericImpl::CacheData *v13; // eax
  unsigned int v14; // eax
  bool v15; // cc

  AbsoluteLimit = this->AbsoluteLimit;
  if ( AbsoluteLimit && requestSize > AbsoluteLimit )
    return 2;
  Match = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_Reuse_LRU, size, type, format);
  *pdata = Match;
  if ( Match )
    return 0;
  v10 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_Reuse_ThisFrame, size, type, format);
  *pdata = v10;
  if ( v10 )
    return 0;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_Reuse_LRU, requestSize) )
    return 1;
  v11 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_LRU, size, type, format);
  *pdata = v11;
  if ( v11 )
    return 0;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_LRU, requestSize)
    || Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(
         this,
         RBCL_Reuse_ThisFrame,
         requestSize) )
  {
    return 1;
  }
  v12 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_PrevFrame, size, type, format);
  *pdata = v12;
  if ( v12 )
    return 0;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_PrevFrame, requestSize) )
    return 1;
  v13 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_ThisFrame, size, type, format);
  *pdata = v13;
  if ( v13 )
    return 0;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_ThisFrame, requestSize) )
    return 1;
  v14 = this->AbsoluteLimit;
  if ( !v14 )
    return 1;
  v15 = requestSize + this->AllocSize <= v14;
  result = RS_Fail;
  if ( v15 )
    return 1;
  return result;
}
