void __usercall Scaleform::Render::DrawableImage::updateStagingTargetRT(
        Scaleform::Render::DrawableImage *this@<ecx>,
        int a2@<edi>)
{
  Scaleform::Render::DrawableImageContext *pObject; // edi
  void *RenderThreadID; // edi
  Scaleform::Lock *p_QueueLock; // edi
  Scaleform::Render::RenderSync *v6; // eax
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *inserted; // eax
  Scaleform::Render::Fence *v8; // edi
  Scaleform::Render::Fence *v9; // ecx
  Scaleform::Lock *v10; // edi
  Scaleform::Render::Interfaces rifs; // [esp+8h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+18h] [ebp+0h]

  if ( this->pTexture.Value )
  {
    pObject = this->pContext.pObject;
    memset(&rifs, 0, sizeof(rifs));
    ((void (__thiscall *)(Scaleform::Render::ThreadCommandQueue *, Scaleform::Render::Interfaces *, int))pObject->pRTCommandQueue->GetRenderInterfaces)(
      pObject->pRTCommandQueue,
      &rifs,
      a2);
    if ( pObject->IDefaults.pTextureManager )
      rifs.pHAL = (Scaleform::Render::HAL *)pObject->IDefaults.pTextureManager;
    if ( pObject->IDefaults.pHAL )
      rifs.pRenderer2D = (Scaleform::Render::Renderer2D *)pObject->IDefaults.pHAL;
    if ( pObject->IDefaults.pRenderer2D )
      rifs.RenderThreadID = pObject->IDefaults.pRenderer2D;
    RenderThreadID = pObject->IDefaults.RenderThreadID;
    if ( RenderThreadID )
      retaddr = RenderThreadID;
    p_QueueLock = &this->pQueue.pObject->QueueLock;
    EnterCriticalSection(&p_QueueLock->cs);
    if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
    {
      this->pTexture.Value->Unmap(this->pTexture.Value);
      this->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(&p_QueueLock->cs);
    this->pTexture.Value->UpdateStagingData(
      this->pTexture.Value,
      (struct Scaleform::Render::RenderTargetData *)this->pRT.pObject->pRenderTargetData);
    if ( rifs.pHAL->GetRenderSync(rifs.pHAL) )
    {
      v6 = rifs.pHAL->GetRenderSync(rifs.pHAL);
      inserted = Scaleform::Render::RenderSync::InsertFence(v6);
      v8 = (Scaleform::Render::Fence *)inserted;
      if ( inserted )
        ++inserted->Data[0].RefCount;
      v9 = this->pFence.pObject;
      if ( v9 )
        Scaleform::Render::Fence::Release(v9);
      this->pFence.pObject = v8;
    }
    if ( (this->DrawableImageState & 0x40) != 0 )
    {
      this->DrawableImageState &= ~0x40u;
      v10 = &this->pQueue.pObject->QueueLock;
      EnterCriticalSection(&v10->cs);
      if ( !this->pDelegateImage.pObject || Scaleform::Render::DrawableImage::ensureRenderableRT(this) )
      {
        if ( this->pTexture.Value )
        {
          if ( this->pTexture.Value->Map(this->pTexture.Value, &this->MappedData, 0, 0) )
            this->DrawableImageState |= 3u;
        }
      }
      LeaveCriticalSection(&v10->cs);
    }
  }
}
