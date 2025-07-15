void __thiscall Scaleform::Render::DrawableImage::initialize(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        int dicontext)
{
  Scaleform::Render::DrawableImageContext *v4; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::RenderTarget *v7; // ecx
  Scaleform::Render::DrawableImageContext *v8; // edi
  void *RenderThreadID; // edi
  unsigned int Height; // ecx
  Scaleform::Render::DrawableImage *v11; // ecx
  Scaleform::Render::DrawableImage *v12; // ecx
  Scaleform::Render::DICommandQueue *v13; // eax
  int v14; // eax
  int v15; // edi
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::Render::ImageBase *v17; // ecx
  Scaleform::Render::DrawableImage *v18; // eax
  Scaleform::Render::DICommand_CreateTexture cmd; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::Interfaces rifs; // [esp+18h] [ebp-10h] BYREF

  v4 = (Scaleform::Render::DrawableImageContext *)dicontext;
  if ( dicontext )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)dicontext);
  pObject = (Scaleform::RefCountVImpl *)this->pContext.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pContext.pObject = v4;
  v7 = this->pRT.pObject;
  if ( v7 )
    v7->Release(v7);
  this->pRT.pObject = 0;
  v8 = this->pContext.pObject;
  memset(&rifs, 0, sizeof(rifs));
  v8->pRTCommandQueue->GetRenderInterfaces(v8->pRTCommandQueue, &rifs);
  if ( v8->IDefaults.pTextureManager )
    rifs.pTextureManager = v8->IDefaults.pTextureManager;
  if ( v8->IDefaults.pHAL )
    rifs.pHAL = v8->IDefaults.pHAL;
  if ( v8->IDefaults.pRenderer2D )
    rifs.pRenderer2D = v8->IDefaults.pRenderer2D;
  RenderThreadID = v8->IDefaults.RenderThreadID;
  if ( RenderThreadID )
    rifs.RenderThreadID = RenderThreadID;
  this->Format = format;
  Height = size->Height;
  this->ISize.Width = size->Width;
  this->ISize.Height = Height;
  v11 = this->pCPUModifiedNext.pObject;
  if ( v11 )
    v11->Release(v11);
  this->pCPUModifiedNext.pObject = 0;
  v12 = this->pGPUModifiedNext.pObject;
  if ( v12 )
    v12->Release(v12);
  this->pGPUModifiedNext.pObject = 0;
  if ( !this->pQueue.pObject )
  {
    dicontext = 2;
    v13 = (Scaleform::Render::DICommandQueue *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 140,
                                                 &dicontext);
    if ( v13 )
    {
      Scaleform::Render::DICommandQueue::DICommandQueue(v13, v4);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    v16 = (Scaleform::RefCountVImpl *)this->pQueue.pObject;
    if ( v16 )
      Scaleform::RefCountImpl::Release(v16);
    this->pQueue.pObject = (Scaleform::Render::DICommandQueue *)v15;
    this->pPrev = *(Scaleform::Render::DrawableImage **)(v15 + 44);
    this->pNext = (Scaleform::Render::DrawableImage *)(v15 + 24);
    *(_DWORD *)(*(_DWORD *)(v15 + 44) + 24) = this;
    *(_DWORD *)(v15 + 44) = this;
  }
  v17 = this->pDelegateImage.pObject;
  if ( v17 )
  {
    if ( v17->GetImageType(v17) == Type_DrawableImage )
    {
      v18 = (Scaleform::Render::DrawableImage *)this->pDelegateImage.pObject->GetAsImage(this->pDelegateImage.pObject);
      Scaleform::Render::DrawableImage::mergeQueueWith(this, v18);
    }
  }
  else if ( rifs.pTextureManager && rifs.pTextureManager->CanCreateTextureCurrentThread(rifs.pTextureManager) )
  {
    Scaleform::Render::DrawableImage::createTextureFromManager(this, rifs.pHAL, rifs.pTextureManager);
  }
  else
  {
    this->AddRef(this);
    cmd.pImage.pObject = this;
    cmd.__vftable = (Scaleform::Render::DICommand_CreateTexture_vtbl *)&Scaleform::Render::DICommand_CreateTexture::`vftable';
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CreateTexture>(this, &cmd);
    cmd.__vftable = (Scaleform::Render::DICommand_CreateTexture_vtbl *)&Scaleform::Render::DICommand::`vftable';
    if ( cmd.pImage.pObject )
      cmd.pImage.pObject->Release(cmd.pImage.pObject);
  }
}
