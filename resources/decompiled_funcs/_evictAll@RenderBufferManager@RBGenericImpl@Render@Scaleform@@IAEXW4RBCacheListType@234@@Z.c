void __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::RBCacheListType ltype)
{
  Scaleform::Render::RBGenericImpl::CacheData *pNext; // eax
  unsigned int DataSize; // ecx
  Scaleform::Render::RenderBuffer *pBuffer; // esi
  Scaleform::Render::RenderBufferType Type; // eax
  Scaleform::RefCountVImpl *pManager; // ecx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx
  volatile int RefCount; // ecx

  while ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)this->BufferCache[ltype].Root.pNext != &this->BufferCache[ltype] )
  {
    pNext = this->BufferCache[ltype].Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$EA02E2A925554C6B16FA29F8B6C1D51A::pPrev = pNext->pPrev;
    DataSize = pNext->DataSize;
    pNext->ListType = RBCL_Uncached;
    this->AllocSize -= DataSize;
    pBuffer = pNext->pBuffer;
    pNext->DataSize = 0;
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
        continue;
    }
    else if ( Type != RBuffer_DepthStencil || !pBuffer )
    {
      continue;
    }
    ((void (__thiscall *)(Scaleform::Render::RenderBuffer *, int))pBuffer->~Scaleform::Render::RenderBuffer)(pBuffer, 1);
  }
}
