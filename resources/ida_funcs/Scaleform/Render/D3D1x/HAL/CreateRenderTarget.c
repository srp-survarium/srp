Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        ID3D11View *pcolor,
        ID3D11View *pdepth)
{
  void (__stdcall *GetResource)(ID3D11View *, ID3D11Resource **); // eax
  Scaleform::Render::RenderBufferManager *pObject; // ecx
  Scaleform::Render::RenderBuffer *v6; // eax
  Scaleform::Render::DepthStencilBuffer *v7; // ebx
  unsigned int Width; // ebx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::Render::DepthStencilBuffer *v10; // eax
  unsigned int Height; // ecx
  Scaleform::Render::RenderBuffer *v12; // esi
  Scaleform::Ptr<ID3D11Texture2D> pdepthStencilTarget; // [esp+3Ch] [ebp-78h] BYREF
  Scaleform::Ptr<ID3D11Texture2D> prenderTarget; // [esp+40h] [ebp-74h] BYREF
  int v16; // [esp+44h] [ebp-70h] BYREF
  Scaleform::Render::RenderBuffer *buffer; // [esp+48h] [ebp-6Ch]
  Scaleform::Render::Size<unsigned long> rtSize; // [esp+4Ch] [ebp-68h] BYREF
  Scaleform::Render::Size<unsigned long> dsSize; // [esp+54h] [ebp-60h]
  D3D11_TEXTURE2D_DESC rtDesc; // [esp+5Ch] [ebp-58h] BYREF
  D3D11_TEXTURE2D_DESC dsDesc; // [esp+88h] [ebp-2Ch] BYREF

  GetResource = pcolor->GetResource;
  prenderTarget.pObject = 0;
  pdepthStencilTarget.pObject = 0;
  rtSize.Width = 0;
  rtSize.Height = 0;
  GetResource(pcolor, &prenderTarget.pObject);
  prenderTarget.pObject->GetDesc(prenderTarget.pObject, &rtDesc);
  rtSize.Width = rtDesc.Width;
  pObject = this->pRenderBufferManager.pObject;
  rtSize.Height = rtDesc.Height;
  v6 = pObject->CreateRenderTarget(pObject, &rtSize, RBuffer_User, Image_R8G8B8A8, 0);
  buffer = v6;
  if ( v6 )
    v6->AddRef(v6);
  v7 = 0;
  if ( pdepth )
  {
    pdepth->GetResource(pdepth, (ID3D11Resource **)&pdepthStencilTarget);
    pdepthStencilTarget.pObject->GetDesc(pdepthStencilTarget.pObject, &dsDesc);
    Width = dsDesc.Width;
    dsSize.Height = dsDesc.Height;
    AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
    v16 = 75;
    v10 = (Scaleform::Render::DepthStencilBuffer *)AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     28u,
                                                     (const Scaleform::AllocInfo *)&v16);
    if ( v10 )
    {
      Height = dsSize.Height;
      v10->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v10->RefCount = 1;
      v10->Type = RBuffer_DepthStencil;
      v10->pManager = 0;
      v10->pRenderTargetData = 0;
      v10->BufferSize.Width = Width;
      v10->BufferSize.Height = Height;
      v10->__vftable = (Scaleform::Render::DepthStencilBuffer_vtbl *)&Scaleform::Render::DepthStencilBuffer::`vftable';
    }
    else
    {
      v10 = 0;
    }
    v7 = v10;
  }
  v12 = buffer;
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v7, buffer, pcolor, pdepth);
  if ( v7 )
    v7->Release(v7);
  if ( v12 )
    v12->Release(v12);
  if ( pdepthStencilTarget.pObject )
    pdepthStencilTarget.pObject->Release(pdepthStencilTarget.pObject);
  if ( prenderTarget.pObject )
    prenderTarget.pObject->Release(prenderTarget.pObject);
  return (Scaleform::Render::RenderTarget *)v12;
}


Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        ID3D11View *texture,
        bool needsStencil)
{
  ID3D11View *v3; // esi
  Scaleform::Render::RenderBufferManager *pObject; // ebx
  Scaleform::Render::ImageFormat (__thiscall *GetPrivateData)(Scaleform::Render::Texture *); // eax
  int (__thiscall **p_CreateRenderTarget)(Scaleform::Render::RenderBufferManager *, unsigned int *, int, int); // edi
  int v8; // eax
  Scaleform::Render::RenderBuffer *v9; // ebx
  Scaleform::Render::DepthStencilBuffer *v10; // edi
  ID3D11Device *pDevice; // eax
  ID3D11View_vtbl *v12; // edx
  ID3D11View_vtbl *v13; // edx
  Scaleform::Render::RenderBufferManager *v14; // ebp
  int v15; // eax
  ID3D11DepthStencilView *pdsView; // [esp+24h] [ebp-14h]
  unsigned int v18; // [esp+2Ch] [ebp-Ch] BYREF
  _DWORD v19[2]; // [esp+30h] [ebp-8h] BYREF

  v3 = texture;
  if ( !texture || BYTE1(texture[9].lpVtbl) != 1 )
    return 0;
  pObject = this->pRenderBufferManager.pObject;
  GetPrivateData = (Scaleform::Render::ImageFormat (__thiscall *)(Scaleform::Render::Texture *))texture->GetPrivateData;
  v18 = (unsigned int)texture[7].lpVtbl;
  p_CreateRenderTarget = (int (__thiscall **)(Scaleform::Render::RenderBufferManager *, unsigned int *, int, int))&pObject->CreateRenderTarget;
  v8 = ((int (__thiscall *)(ID3D11View *, ID3D11View *))GetPrivateData)(texture, texture);
  v9 = (Scaleform::Render::RenderBuffer *)(*p_CreateRenderTarget)(pObject, &v18, 4, v8);
  v10 = 0;
  if ( !v9 )
    return 0;
  pDevice = this->pDevice;
  v12 = v3[13].lpVtbl;
  texture = 0;
  pdsView = 0;
  if ( pDevice->CreateRenderTargetView(pDevice, (ID3D11Resource *)v12->Release, 0, (ID3D11RenderTargetView **)&texture) < 0 )
  {
    if ( texture )
      texture->Release(texture);
    return 0;
  }
  if ( needsStencil )
  {
    v13 = v3[7].lpVtbl;
    v14 = this->pRenderBufferManager.pObject;
    v19[0] = v3[6].lpVtbl;
    v19[1] = v13;
    v10 = v14->CreateDepthStencilBuffer(v14, (const Scaleform::Render::Size<unsigned long> *)v19);
    if ( v10 )
    {
      v15 = (int)v10->GetSurface(v10);
      if ( v15 )
        pdsView = *(ID3D11DepthStencilView **)(v15 + 36);
    }
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v10, v9, texture, pdsView);
  if ( v10 )
    v10->Release(v10);
  if ( texture )
    texture->Release(texture);
  return (Scaleform::Render::RenderTarget *)v9;
}
