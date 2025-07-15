void __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::RBCacheListType ltype)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v3; // ebp
  Scaleform::Render::RBGenericImpl::CacheData *pPrev; // eax
  unsigned int DataSize; // edx
  Scaleform::Render::RenderBuffer *pBuffer; // esi
  Scaleform::Render::RenderBufferType Type; // eax
  Scaleform::RefCountVImpl *pManager; // ecx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // ecx
  volatile int RefCount; // eax

  if ( this->AllocSize > this->ReuseLimit )
  {
    v3 = &this->BufferCache[ltype];
    do
    {
      pPrev = v3->Root.pPrev;
      if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v3->Root.pPrev == v3 )
        return;
      pPrev->pPrev->pNext = pPrev->pNext;
      pPrev->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$EA02E2A925554C6B16FA29F8B6C1D51A::pPrev = pPrev->pPrev;
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
          continue;
      }
      else if ( Type != RBuffer_DepthStencil || !pBuffer )
      {
        continue;
      }
      ((void (__thiscall *)(Scaleform::Render::RenderBuffer *, int))pBuffer->~Scaleform::Render::RenderBuffer)(
        pBuffer,
        1);
    }
    while ( this->AllocSize > this->ReuseLimit );
  }
}
