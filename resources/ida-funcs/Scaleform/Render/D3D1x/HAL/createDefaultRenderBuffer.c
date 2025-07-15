bool __thiscall Scaleform::Render::D3D1x::HAL::createDefaultRenderBuffer(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderTarget *v2; // eax
  unsigned int v3; // edx
  ID3D11DeviceContext *pDeviceContext; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::Render::RenderTarget *v6; // eax
  Scaleform::Render::RenderTarget *v7; // eax
  Scaleform::Render::RenderTarget *v8; // ebx
  Scaleform::Render::DepthStencilBuffer *v9; // edi
  void *(__thiscall *v10)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::Render::DepthStencilBuffer *v11; // eax
  Scaleform::Render::DepthStencilBuffer *v12; // eax
  Scaleform::Ptr<ID3D11RenderTargetView> prtView; // [esp+5Ch] [ebp-7Ch] BYREF
  Scaleform::Ptr<ID3D11DepthStencilView> pdsView; // [esp+60h] [ebp-78h] BYREF
  Scaleform::Ptr<ID3D11Texture2D> pdepthStencilTarget; // [esp+64h] [ebp-74h] BYREF
  Scaleform::Ptr<ID3D11Texture2D> prenderTarget; // [esp+68h] [ebp-70h] BYREF
  int v18; // [esp+6Ch] [ebp-6Ch] BYREF
  Scaleform::Render::Size<unsigned long> rtSize; // [esp+70h] [ebp-68h] BYREF
  Scaleform::Render::Size<unsigned long> dsSize; // [esp+78h] [ebp-60h] BYREF
  D3D11_TEXTURE2D_DESC rtDesc; // [esp+80h] [ebp-58h] BYREF
  D3D11_TEXTURE2D_DESC dsDesc; // [esp+ACh] [ebp-2Ch] BYREF

  if ( this->GetDefaultRenderTarget(this) )
  {
    v2 = this->GetDefaultRenderTarget(this);
    v3 = v2->ViewRect.x2 - v2->ViewRect.x1;
    rtSize.Height = v2->ViewRect.y2 - v2->ViewRect.y1;
    rtSize.Width = v3;
    return this->pRenderBufferManager.pObject->Initialize(
             this->pRenderBufferManager.pObject,
             this->pTextureManager.pObject,
             Image_R8G8B8A8,
             &rtSize);
  }
  pDeviceContext = this->pDeviceContext;
  prtView.pObject = 0;
  pdsView.pObject = 0;
  prenderTarget.pObject = 0;
  pdepthStencilTarget.pObject = 0;
  pDeviceContext->OMGetRenderTargets(pDeviceContext, 1u, &prtView.pObject, &pdsView.pObject);
  prtView.pObject->GetResource(prtView.pObject, (ID3D11Resource **)&prenderTarget);
  prenderTarget.pObject->GetDesc(prenderTarget.pObject, &rtDesc);
  rtSize.Height = rtDesc.Height;
  rtSize.Width = rtDesc.Width;
  AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
  v18 = 75;
  v6 = (Scaleform::Render::RenderTarget *)AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            44u,
                                            (const Scaleform::AllocInfo *)&v18);
  if ( v6 )
  {
    Scaleform::Render::RenderTarget::RenderTarget(v6, 0, RBuffer_Default, &rtSize);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = 0;
  if ( pdsView.pObject )
  {
    prtView.pObject->GetResource(prtView.pObject, (ID3D11Resource **)&pdepthStencilTarget);
    pdepthStencilTarget.pObject->GetDesc(pdepthStencilTarget.pObject, &dsDesc);
    dsSize.Height = dsDesc.Height;
    dsSize.Width = dsDesc.Width;
    v10 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
    v18 = 75;
    v11 = (Scaleform::Render::DepthStencilBuffer *)v10(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     28u,
                                                     (const Scaleform::AllocInfo *)&v18);
    if ( v11 )
      Scaleform::Render::DepthStencilBuffer::DepthStencilBuffer(v11, 0, &dsSize);
    else
      v12 = 0;
    v9 = v12;
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v9, v8, prtView.pObject, pdsView.pObject);
  if ( this->SetRenderTarget(this, v8, 1) )
  {
    if ( v9 )
      v9->Release(v9);
    if ( v8 )
      v8->Release(v8);
    if ( pdepthStencilTarget.pObject )
      pdepthStencilTarget.pObject->Release(pdepthStencilTarget.pObject);
    if ( prenderTarget.pObject )
      prenderTarget.pObject->Release(prenderTarget.pObject);
    if ( pdsView.pObject )
      pdsView.pObject->Release(pdsView.pObject);
    if ( prtView.pObject )
      prtView.pObject->Release(prtView.pObject);
    return this->pRenderBufferManager.pObject->Initialize(
             this->pRenderBufferManager.pObject,
             this->pTextureManager.pObject,
             Image_R8G8B8A8,
             &rtSize);
  }
  if ( v9 )
    v9->Release(v9);
  if ( v8 )
    v8->Release(v8);
  if ( pdepthStencilTarget.pObject )
    pdepthStencilTarget.pObject->Release(pdepthStencilTarget.pObject);
  if ( prenderTarget.pObject )
    prenderTarget.pObject->Release(prenderTarget.pObject);
  if ( pdsView.pObject )
    pdsView.pObject->Release(pdsView.pObject);
  if ( prtView.pObject )
    prtView.pObject->Release(prtView.pObject);
  return 0;
}
