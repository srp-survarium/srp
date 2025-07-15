void __thiscall Scaleform::Render::DrawableImage::~DrawableImage(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // edi
  void *RenderThreadID; // edi
  Scaleform::Lock *p_QueueLock; // edi
  Scaleform::Render::UnmapTextureThreadCommand *v5; // eax
  Scaleform::Render::ThreadCommand *v6; // eax
  Scaleform::Render::ThreadCommand *v7; // edi
  Scaleform::Lock *v8; // edi
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::Render::Fence *v10; // ecx
  Scaleform::Render::RenderTarget *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::Render::ImageBase *v13; // ecx
  Scaleform::Render::DrawableImage *v14; // ecx
  Scaleform::Render::DrawableImage *v15; // ecx
  Scaleform::Render::Palette *v16; // edi
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::Render::TextureManager *pTextureManager; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::HAL *pHAL; // [esp+14h] [ebp-Ch]
  Scaleform::Render::Renderer2D *pRenderer2D; // [esp+18h] [ebp-8h]
  void *v21; // [esp+1Ch] [ebp-4h]

  this->__vftable = (Scaleform::Render::DrawableImage_vtbl *)&Scaleform::Render::DrawableImage::`vftable';
  if ( (this->DrawableImageState & 3) != 0 )
  {
    pObject = this->pContext.pObject;
    pTextureManager = 0;
    pHAL = 0;
    pRenderer2D = 0;
    v21 = 0;
    pObject->pRTCommandQueue->GetRenderInterfaces(
      pObject->pRTCommandQueue,
      (Scaleform::Render::Interfaces *)&pTextureManager);
    if ( pObject->IDefaults.pTextureManager )
      pTextureManager = pObject->IDefaults.pTextureManager;
    if ( pObject->IDefaults.pHAL )
      pHAL = pObject->IDefaults.pHAL;
    if ( pObject->IDefaults.pRenderer2D )
      pRenderer2D = pObject->IDefaults.pRenderer2D;
    RenderThreadID = pObject->IDefaults.RenderThreadID;
    if ( RenderThreadID )
      v21 = RenderThreadID;
    if ( v21 == (void *)Scaleform::GetCurrentThreadId() )
    {
      p_QueueLock = &this->pQueue.pObject->QueueLock;
      EnterCriticalSection(&p_QueueLock->cs);
      if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
      {
        this->pTexture.Value->Unmap(this->pTexture.Value);
        this->DrawableImageState &= 0xFFFFFFFC;
      }
      LeaveCriticalSection(&p_QueueLock->cs);
    }
    else
    {
      v5 = (Scaleform::Render::UnmapTextureThreadCommand *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             12,
                                                             0);
      if ( v5 )
      {
        Scaleform::Render::UnmapTextureThreadCommand::UnmapTextureThreadCommand(
          v5,
          (Scaleform::GFx::Resource *)this->pTexture.Value);
        v7 = v6;
      }
      else
      {
        v7 = 0;
      }
      this->pContext.pObject->pRTCommandQueue->PushThreadCommand(this->pContext.pObject->pRTCommandQueue, v7);
      if ( v7 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
    }
  }
  v8 = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&v8->cs);
  this->pPrev->pNext = this->pNext;
  this->pNext->pPrev = this->pPrev;
  LeaveCriticalSection(&v8->cs);
  v9 = (Scaleform::RefCountVImpl *)this->pQueue.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  this->pQueue.pObject = 0;
  v10 = this->pFence.pObject;
  if ( v10 )
    Scaleform::Render::Fence::Release(v10);
  v11 = this->pRT.pObject;
  if ( v11 )
    v11->Release(v11);
  v12 = (Scaleform::RefCountVImpl *)this->pContext.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v13 = this->pDelegateImage.pObject;
  if ( v13 )
    v13->Release(v13);
  v14 = this->pGPUModifiedNext.pObject;
  if ( v14 )
    v14->Release(v14);
  v15 = this->pCPUModifiedNext.pObject;
  if ( v15 )
    v15->Release(v15);
  Scaleform::Render::ImageData::freePlanes(&this->MappedData);
  v16 = this->MappedData.pPalette.pObject;
  if ( v16 && InterlockedExchangeAdd(&v16->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
  v17 = (Scaleform::RefCountVImpl *)this->pQueue.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  Scaleform::Render::Image::~Image(this);
}
