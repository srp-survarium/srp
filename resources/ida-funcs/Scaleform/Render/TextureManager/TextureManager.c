void __thiscall Scaleform::Render::TextureManager::TextureManager(
        Scaleform::Render::TextureManager *this,
        void *renderThreadId,
        Scaleform::Render::ThreadCommandQueue *commandQueue,
        Scaleform::GFx::Resource *textureCache)
{
  unsigned int *p_Size; // ecx
  Scaleform::Render::Texture *p_Textures; // ecx
  Scaleform::Render::DepthStencilSurface *p_TextureInitQueue; // ecx
  Scaleform::Render::TextureManagerLocks *v8; // eax
  Scaleform::Render::TextureManagerLocks *v9; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  int v11; // [esp+Ch] [ebp-4h] BYREF

  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::TextureManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::ImageUpdateSync::__vftable = (Scaleform::Render::ImageUpdateSync_vtbl *)&Scaleform::GFx::AMP::SocketImplFactory::`vftable';
  this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::TextureManager_vtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>'};
  this->Scaleform::Render::ImageUpdateSync::__vftable = (Scaleform::Render::ImageUpdateSync_vtbl *)&Scaleform::Render::TextureManager::`vftable'{for `Scaleform::Render::ImageUpdateSync'};
  this->ServiceCommandInstance.__vftable = (Scaleform::Render::TextureManager::ServiceCommand_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->ServiceCommandInstance.RefCount = 1;
  this->ServiceCommandInstance.__vftable = (Scaleform::Render::TextureManager::ServiceCommand_vtbl *)&Scaleform::Render::TextureManager::ServiceCommand::`vftable';
  this->ServiceCommandInstance.pManager = this;
  this->RenderThreadId = renderThreadId;
  this->pRTCommandQueue = commandQueue;
  if ( textureCache )
    Scaleform::RefCountImpl::AddRef(textureCache);
  this->pTextureCache.pObject = (Scaleform::Render::TextureCache *)textureCache;
  this->pLocks.pObject = 0;
  this->ImageUpdates.Queue.Data.Data = 0;
  this->ImageUpdates.Queue.Data.Size = 0;
  this->ImageUpdates.Queue.Data.Policy.Capacity = 0;
  this->TextureFormats.Data.Data = 0;
  this->TextureFormats.Data.Size = 0;
  this->TextureFormats.Data.Policy.Capacity = 0;
  if ( this == (Scaleform::Render::TextureManager *)-64 )
    p_Size = 0;
  else
    p_Size = &this->TextureFormats.Data.Size;
  this->Textures.Root.pPrev = (Scaleform::Render::Texture *)p_Size;
  this->Textures.Root.pNext = (Scaleform::Render::Texture *)p_Size;
  if ( this == (Scaleform::Render::TextureManager *)-72 )
    p_Textures = 0;
  else
    p_Textures = (Scaleform::Render::Texture *)&this->Textures;
  this->TextureInitQueue.Root.pPrev = p_Textures;
  this->TextureInitQueue.Root.pNext = p_Textures;
  if ( this == (Scaleform::Render::TextureManager *)-80 )
    p_TextureInitQueue = 0;
  else
    p_TextureInitQueue = (Scaleform::Render::DepthStencilSurface *)&this->TextureInitQueue;
  this->DepthStencilInitQueue.Root.pPrev = p_TextureInitQueue;
  this->DepthStencilInitQueue.Root.pNext = p_TextureInitQueue;
  v11 = 75;
  v8 = (Scaleform::Render::TextureManagerLocks *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   60,
                                                   &v11);
  v9 = v8;
  if ( v8 )
  {
    v8->__vftable = (Scaleform::Render::TextureManagerLocks_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v8->RefCount = 1;
    v8->__vftable = (Scaleform::Render::TextureManagerLocks_vtbl *)&Scaleform::Render::TextureManagerLocks::`vftable';
    v8->pManager = this;
    Scaleform::Lock::Lock(&v8->ImageLock, 0);
    Scaleform::Mutex::Mutex(&v9->TextureMutex, 1, 0);
    Scaleform::WaitCondition::WaitCondition(&v9->TextureInitWC);
  }
  else
  {
    v9 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pLocks.pObject = v9;
}
