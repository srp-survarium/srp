Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateTempRenderTarget(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        const Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::Render::RenderBuffer *pBuffer; // esi
  Scaleform::Render::ImageFormat DefImageFormat; // ebp
  unsigned int v6; // ebx
  Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult v7; // eax
  Scaleform::RefCountVImpl *v8; // eax
  Scaleform::Render::RBGenericImpl::RenderTarget *v9; // eax
  _DWORD *v10; // esi
  unsigned int Width; // eax
  unsigned int v12; // ecx
  unsigned int Height; // ecx
  Scaleform::Render::RBGenericImpl::CacheData *pdata; // [esp+14h] [ebp-10h] BYREF
  Scaleform::RefCountVImpl *v15; // [esp+18h] [ebp-Ch]
  Scaleform::Render::Size<unsigned long> result; // [esp+1Ch] [ebp-8h] BYREF

  pBuffer = 0;
  if ( !this->pTextureManager.pObject )
    return 0;
  pdata = 0;
  Scaleform::Render::RBGenericImpl::RenderBufferManager::RoundUpImageSize(this, &result, size);
  DefImageFormat = this->DefImageFormat;
  v15 = (Scaleform::RefCountVImpl *)(result.Width * result.Height);
  v6 = ((unsigned int)v15 * Scaleform::Render::ImageData::GetFormatBitsPerPixel(DefImageFormat, 0)) >> 3;
  v7 = Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
         this,
         &pdata,
         &result,
         RBuffer_Temporary,
         DefImageFormat,
         v6);
  if ( v7 == RS_Match )
  {
    pBuffer = pdata->pBuffer;
    ((void (__thiscall *)(Scaleform::Render::RenderBuffer *, int))pBuffer->__vftable[1].Release)(pBuffer, 1);
    Height = size->Height;
    pBuffer[1].Type = size->Width;
    pBuffer[1].pManager = (Scaleform::Render::RenderBufferManager *)Height;
    pBuffer[1].__vftable = 0;
    pBuffer[1].RefCount = 0;
    pBuffer->AddRef(pBuffer);
    return (Scaleform::Render::RenderTarget *)pBuffer;
  }
  if ( v7 != RS_Alloc )
    return (Scaleform::Render::RenderTarget *)pBuffer;
  v8 = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject->CreateTexture(
                                     this->pTextureManager.pObject,
                                     DefImageFormat,
                                     1,
                                     &result,
                                     1024,
                                     0,
                                     0);
  v15 = v8;
  if ( !v8 )
    return (Scaleform::Render::RenderTarget *)pBuffer;
  v9 = Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(
         this,
         &result,
         RBuffer_Temporary,
         DefImageFormat,
         (Scaleform::GFx::Resource *)v8);
  v10 = &v9->__vftable;
  if ( v9 )
  {
    v9->ListType = RBCL_InUse;
    v9->pNext = this->BufferCache[1].Root.pNext;
    v9->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1];
    this->BufferCache[1].Root.pNext->pPrev = &v9->Scaleform::Render::RBGenericImpl::CacheData;
    this->BufferCache[1].Root.pNext = &v9->Scaleform::Render::RBGenericImpl::CacheData;
    Width = size->Width;
    v12 = size->Height;
    v10[7] = 0;
    v10[8] = 0;
    v10[9] = Width;
    v10[10] = v12;
    v10[16] = v6;
    this->AllocSize += v6;
  }
  Scaleform::RefCountImpl::Release(v15);
  return (Scaleform::Render::RenderTarget *)v10;
}
