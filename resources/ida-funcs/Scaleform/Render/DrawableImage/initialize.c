void __thiscall Scaleform::Render::DrawableImage::initialize(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        Scaleform::GFx::Resource *dicontext)
{
  unsigned int NextImageId; // eax
  Scaleform::GFx::Resource *v6; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::RenderTarget *v8; // ecx
  Scaleform::Render::DrawableImageContext *v9; // edi
  void *RenderThreadID; // edi
  unsigned int Height; // ecx
  Scaleform::Render::DrawableImage *v12; // ecx
  Scaleform::Render::DrawableImage *v13; // ecx
  Scaleform::Render::DICommandQueue *v14; // eax
  int v15; // eax
  int v16; // edi
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::Render::ImageBase *v18; // ecx
  Scaleform::Render::DrawableImage *v19; // eax
  Scaleform::Render::DICommand_CreateTexture cmd; // [esp+10h] [ebp-18h] BYREF
  Scaleform::Render::TextureManager *tmanager; // [esp+18h] [ebp-10h] BYREF
  Scaleform::Render::HAL *phal; // [esp+1Ch] [ebp-Ch]
  Scaleform::Render::Renderer2D *pRenderer2D; // [esp+20h] [ebp-8h]
  void *v24; // [esp+24h] [ebp-4h]

  NextImageId = Scaleform::Render::ImageBase::GetNextImageId();
  v6 = dicontext;
  this->ImageId = NextImageId;
  if ( v6 )
    Scaleform::RefCountImpl::AddRef(v6);
  pObject = (Scaleform::RefCountVImpl *)this->pContext.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pContext.pObject = (Scaleform::Render::DrawableImageContext *)v6;
  v8 = this->pRT.pObject;
  if ( v8 )
    v8->Release(v8);
  this->pRT.pObject = 0;
  v9 = this->pContext.pObject;
  tmanager = 0;
  phal = 0;
  pRenderer2D = 0;
  v24 = 0;
  v9->pRTCommandQueue->GetRenderInterfaces(v9->pRTCommandQueue, (Scaleform::Render::Interfaces *)&tmanager);
  if ( v9->IDefaults.pTextureManager )
    tmanager = v9->IDefaults.pTextureManager;
  if ( v9->IDefaults.pHAL )
    phal = v9->IDefaults.pHAL;
  if ( v9->IDefaults.pRenderer2D )
    pRenderer2D = v9->IDefaults.pRenderer2D;
  RenderThreadID = v9->IDefaults.RenderThreadID;
  if ( RenderThreadID )
    v24 = RenderThreadID;
  this->Format = format;
  Height = size->Height;
  this->ISize.Width = size->Width;
  this->ISize.Height = Height;
  v12 = this->pCPUModifiedNext.pObject;
  if ( v12 )
    v12->Release(v12);
  this->pCPUModifiedNext.pObject = 0;
  v13 = this->pGPUModifiedNext.pObject;
  if ( v13 )
    v13->Release(v13);
  this->pGPUModifiedNext.pObject = 0;
  if ( !this->pQueue.pObject )
  {
    dicontext = (Scaleform::GFx::Resource *)2;
    v14 = (Scaleform::Render::DICommandQueue *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 140,
                                                 &dicontext);
    if ( v14 )
    {
      Scaleform::Render::DICommandQueue::DICommandQueue(v14, v6);
      v16 = v15;
    }
    else
    {
      v16 = 0;
    }
    v17 = (Scaleform::RefCountVImpl *)this->pQueue.pObject;
    if ( v17 )
      Scaleform::RefCountImpl::Release(v17);
    this->pQueue.pObject = (Scaleform::Render::DICommandQueue *)v16;
    this->pPrev = *(Scaleform::Render::DrawableImage **)(v16 + 44);
    this->pNext = (Scaleform::Render::DrawableImage *)(v16 + 24);
    *(_DWORD *)(*(_DWORD *)(v16 + 44) + 24) = this;
    *(_DWORD *)(v16 + 44) = this;
  }
  v18 = this->pDelegateImage.pObject;
  if ( v18 )
  {
    if ( v18->GetImageType(v18) == Type_DrawableImage )
    {
      v19 = (Scaleform::Render::DrawableImage *)this->pDelegateImage.pObject->GetAsImage(this->pDelegateImage.pObject);
      Scaleform::Render::DrawableImage::mergeQueueWith(this, v19);
    }
  }
  else if ( tmanager && tmanager->CanCreateTextureCurrentThread(tmanager) )
  {
    Scaleform::Render::DrawableImage::createTextureFromManager(this, phal, tmanager);
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
