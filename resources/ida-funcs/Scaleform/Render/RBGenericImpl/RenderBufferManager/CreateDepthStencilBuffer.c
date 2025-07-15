Scaleform::Render::DepthStencilBuffer *__thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateDepthStencilBuffer(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::Render::RenderBuffer *pBuffer; // edi
  bool v5; // zf
  Scaleform::Render::Size<unsigned long> *v6; // eax
  unsigned int Height; // ecx
  unsigned int v8; // ebx
  Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult v9; // eax
  Scaleform::GFx::Resource *v10; // ebp
  Scaleform::Render::RBGenericImpl::DepthStencilBuffer *v11; // eax
  Scaleform::Render::MeshBase *v12; // eax
  Scaleform::Render::MeshBase *v13; // edi
  Scaleform::Render::RBGenericImpl::CacheData *v14; // eax
  Scaleform::Render::RBGenericImpl::CacheData *pdata; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::Render::Size<unsigned long> result; // [esp+Ch] [ebp-8h] BYREF

  pBuffer = 0;
  if ( !this->pTextureManager.pObject )
    return 0;
  v5 = !this->RequireExactDepthStencil;
  v6 = size;
  pdata = 0;
  if ( v5 )
    v6 = Scaleform::Render::RBGenericImpl::RenderBufferManager::RoundUpImageSize(this, &result, size);
  Height = v6->Height;
  result.Width = v6->Width;
  v8 = 4 * Height * result.Width;
  result.Height = Height;
  v9 = Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
         this,
         &pdata,
         &result,
         RBuffer_DepthStencil,
         Image_None,
         v8);
  if ( v9 == RS_Match )
  {
    v14 = pdata;
    pdata->pPrev->pNext = pdata->pNext;
    v14->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$33C6E2185EE5619ED4522D9BD84BBA53::pPrev = v14->pPrev;
    v14->ListType = RBCL_InUse;
    v14->pNext = this->BufferCache[1].Root.pNext;
    v14->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1];
    this->BufferCache[1].Root.pNext->pPrev = v14;
    this->BufferCache[1].Root.pNext = v14;
    pBuffer = v14->pBuffer;
    pBuffer->AddRef(pBuffer);
    return (Scaleform::Render::DepthStencilBuffer *)pBuffer;
  }
  if ( v9 != RS_Alloc )
    return (Scaleform::Render::DepthStencilBuffer *)pBuffer;
  v10 = (Scaleform::GFx::Resource *)this->pTextureManager.pObject->CreateDepthStencilSurface(
                                      this->pTextureManager.pObject,
                                      &result,
                                      0);
  if ( !v10 )
    return (Scaleform::Render::DepthStencilBuffer *)pBuffer;
  v11 = (Scaleform::Render::RBGenericImpl::DepthStencilBuffer *)Scaleform::NewOverrideBase<75>::operator new(
                                                                  0x38u,
                                                                  (Scaleform::MemAddressStub *)this);
  if ( v11 )
  {
    Scaleform::Render::RBGenericImpl::DepthStencilBuffer::DepthStencilBuffer(v11, this, &result);
    v13 = v12;
    if ( v12 )
    {
      Scaleform::Render::MeshBase::SetScale9Grid(v12, v10);
      v13->IndexCount = 1;
      v13->PinCount = (unsigned int)this->BufferCache[1].Root.pNext;
      v13->StagingBufferIndexOffset = (unsigned int)&this->BufferCache[1];
      this->BufferCache[1].Root.pNext->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v13->StagingBufferIndexOffset;
      this->BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v13->StagingBufferIndexOffset;
      v13->pProvider.pObject = (Scaleform::Render::MeshProvider *)v8;
      this->AllocSize += v8;
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
    return (Scaleform::Render::DepthStencilBuffer *)v13;
  }
  else
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
    return 0;
  }
}
