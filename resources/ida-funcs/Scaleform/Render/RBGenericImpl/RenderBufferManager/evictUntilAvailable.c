BOOL __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::RBCacheListType ltype,
        unsigned int requestSize)
{
  unsigned int AllocSize; // eax
  unsigned int v5; // ecx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v6; // ebp
  Scaleform::Render::RBGenericImpl::CacheData *pPrev; // eax
  unsigned int DataSize; // ecx
  Scaleform::Render::RenderBuffer *pBuffer; // esi
  Scaleform::Render::RenderBufferType Type; // eax
  Scaleform::RefCountVImpl *pManager; // ecx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx
  volatile int RefCount; // ecx

  AllocSize = this->AllocSize;
  v5 = requestSize;
  if ( requestSize + AllocSize > this->ReuseLimit )
  {
    v6 = &this->BufferCache[ltype];
    do
    {
      pPrev = v6->Root.pPrev;
      if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v6->Root.pPrev == v6 )
        return this->ReuseLimit >= v5 + this->AllocSize;
      pPrev->pPrev->pNext = pPrev->pNext;
      pPrev->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$33C6E2185EE5619ED4522D9BD84BBA53::pPrev = pPrev->pPrev;
      DataSize = pPrev->DataSize;
      pPrev->ListType = RBCL_Uncached;
      this->AllocSize -= DataSize;
      pBuffer = pPrev->pBuffer;
      pPrev->DataSize = 0;
      Type = pBuffer->Type;
      if ( Type == RBuffer_Temporary )
      {
        pManager = (Scaleform::RefCountVImpl *)pBuffer[2].pManager;
        if ( pManager )
          Scaleform::RefCountImpl::Release(pManager);
        pBuffer[2].pManager = 0;
        pRenderTargetData = pBuffer->pRenderTargetData;
        if ( pRenderTargetData )
        {
          ((void (__thiscall *)(Scaleform::Render::RenderBuffer::RenderTargetData *, int))pRenderTargetData->~Scaleform::Render::RenderBuffer::RenderTargetData)(
            pRenderTargetData,
            1);
          pBuffer->pRenderTargetData = 0;
        }
        RefCount = pBuffer->RefCount;
        pBuffer[2].pRenderTargetData = (Scaleform::Render::RenderBuffer::RenderTargetData *)3;
        if ( RefCount )
          goto LABEL_14;
      }
      else if ( Type != RBuffer_DepthStencil || !pBuffer )
      {
        goto LABEL_14;
      }
      ((void (__thiscall *)(Scaleform::Render::RenderBuffer *, int))pBuffer->~Scaleform::Render::RenderBuffer)(
        pBuffer,
        1);
LABEL_14:
      v5 = requestSize;
    }
    while ( requestSize + this->AllocSize > this->ReuseLimit );
  }
  return this->ReuseLimit >= v5 + this->AllocSize;
}
