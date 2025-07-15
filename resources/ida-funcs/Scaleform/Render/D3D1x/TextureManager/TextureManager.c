void __thiscall Scaleform::Render::D3D1x::TextureManager::TextureManager(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::TextureManager *pdevice,
        Scaleform::Render::TextureManager_vtbl *pcontext,
        ID3D11Device_vtbl *renderThreadId,
        Scaleform::Render::ThreadCommandQueue *commandQueue,
        Scaleform::Render::ThreadCommandQueue *texCache)
{
  Scaleform::Render::D3D1x::MappedTexture *v7; // ecx
  Scaleform::Render::D3D1x::TextureManager *v8; // ecx
  Scaleform::Render::TextureManager_vtbl *v9; // eax
  unsigned __int8 dst[52]; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::Render::TextureManager *v11; // [esp+48h] [ebp+8h]
  Scaleform::Render::ThreadCommandQueue *commandQueuea; // [esp+58h] [ebp+18h]

  Scaleform::Render::TextureManager::TextureManager(pdevice, commandQueue, texCache, 0);
  pdevice[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = pcontext;
  pdevice->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::TextureManager_vtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>'};
  pdevice->Scaleform::Render::ImageUpdateSync::__vftable = (Scaleform::Render::ImageUpdateSync_vtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable'{for `Scaleform::Render::ImageUpdateSync'};
  pdevice[1].RefCount = (volatile int)renderThreadId;
  Scaleform::Render::D3D1x::MappedTexture::MappedTexture(v7, (int)&pdevice[1].Scaleform::Render::ImageUpdateSync);
  pdevice[2].TextureFormats.Data.Size = 0;
  pdevice[2].TextureFormats.Data.Policy.Capacity = 0;
  pdevice[2].Textures.Root.pPrev = 0;
  pdevice[2].Textures.Root.pNext = 0;
  pdevice[2].TextureInitQueue.Root.pPrev = 0;
  pdevice[2].TextureInitQueue.Root.pNext = 0;
  Scaleform::Render::D3D1x::TextureManager::initTextureFormats(v8, (int)pdevice);
  v11 = 0;
  pdevice[2].DepthStencilInitQueue.Root.pPrev = 0;
  pdevice[2].DepthStencilInitQueue.Root.pNext = 0;
  pdevice[3].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = 0;
  pdevice[3].RefCount = 0;
  do
  {
    for ( commandQueuea = 0;
          (unsigned int)commandQueuea < 2;
          commandQueuea = (Scaleform::Render::ThreadCommandQueue *)((char *)commandQueuea + 1) )
    {
      memset((int)dst, 0, sizeof(dst));
      if ( 2 * (_DWORD)commandQueuea == 2 )
        *(_DWORD *)dst = 21;
      else
        *(_DWORD *)dst = 0;
      if ( v11 )
      {
        *(_DWORD *)&dst[8] = 3;
        *(_DWORD *)&dst[4] = 3;
      }
      else
      {
        *(_DWORD *)&dst[8] = 1;
        *(_DWORD *)&dst[4] = 1;
      }
      *(_DWORD *)&dst[12] = 3;
      v9 = pdevice[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
      *(float *)&dst[48] = FLOAT_3_4028235e38;
      *(_DWORD *)&dst[24] = 8;
      *(float *)&dst[16] = FLOAT_N0_75;
      *(_DWORD *)&dst[20] = 1;
      (*((void (__stdcall **)(Scaleform::Render::TextureManager_vtbl *, unsigned __int8 *, char *))v9->~Scaleform::Render::TextureManager
       + 23))(
        v9,
        dst,
        (char *)&pdevice[2].DepthStencilInitQueue.Root.pPrev
      + 4 * ((unsigned __int8)v11 | (unsigned __int8)(2 * (_BYTE)commandQueuea)));
    }
    v11 = (Scaleform::Render::TextureManager *)((char *)v11 + 1);
  }
  while ( (unsigned int)v11 < 2 );
}
