bool __usercall Scaleform::Render::D3D1x::HAL::ShutdownHAL@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>)
{
  bool result; // al
  ID3D11BlendState **BlendStates; // esi
  ID3D11DepthStencilState **DepthStencilStates; // esi
  ID3D11RasterizerState **RasterStates; // esi
  ID3D11Buffer **ConstantBuffers; // esi
  ID3D11RenderTargetView *pObject; // eax
  ID3D11DepthStencilView *v10; // eax
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::Render::D3D1x::MeshCache *v13; // ecx
  ID3D11Device **p_pDevice; // ebx
  int v15; // [esp+4h] [ebp-4h]
  int v16; // [esp+4h] [ebp-4h]
  int v17; // [esp+4h] [ebp-4h]
  int v18; // [esp+4h] [ebp-4h]

  if ( (this->HALState & 1) != 0 )
  {
    result = this->shutdownHAL(this);
    if ( !result )
      return result;
    ((void (__stdcall *)(ID3D11DeviceContext *, int, int))Scaleform::Render::D3D1x::RenderEvent::pContext->Release)(
      Scaleform::Render::D3D1x::RenderEvent::pContext,
      a2,
      a3);
    Scaleform::Render::D3D1x::RenderEvent::pContext = 0;
    BlendStates = this->BlendStates;
    v15 = 37;
    do
    {
      if ( *BlendStates )
        (*BlendStates)->Release(*BlendStates);
      ++BlendStates;
      --v15;
    }
    while ( v15 );
    memset((int)this->BlendStates, 0, sizeof(this->BlendStates));
    DepthStencilStates = this->DepthStencilStates;
    v16 = 8;
    do
    {
      if ( *DepthStencilStates )
        (*DepthStencilStates)->Release(*DepthStencilStates);
      ++DepthStencilStates;
      --v16;
    }
    while ( v16 );
    memset(this->DepthStencilStates, 0, sizeof(this->DepthStencilStates));
    RasterStates = this->RasterStates;
    v17 = 2;
    do
    {
      if ( *RasterStates )
        (*RasterStates)->Release(*RasterStates);
      ++RasterStates;
      --v17;
    }
    while ( v17 );
    this->RasterStates[0] = 0;
    this->RasterStates[1] = 0;
    ConstantBuffers = this->ConstantBuffers;
    v18 = 8;
    do
    {
      if ( *ConstantBuffers )
        (*ConstantBuffers)->Release(*ConstantBuffers);
      ++ConstantBuffers;
      --v18;
    }
    while ( v18 );
    memset(this->ConstantBuffers, 0, sizeof(this->ConstantBuffers));
    pObject = this->pRenderTargetView.pObject;
    if ( pObject )
      pObject->Release(this->pRenderTargetView.pObject);
    this->pRenderTargetView.pObject = 0;
    v10 = this->pDepthStencilView.pObject;
    if ( v10 )
      v10->Release(this->pDepthStencilView.pObject);
    this->pDepthStencilView.pObject = 0;
    this->destroyRenderBuffers(this);
    v11 = (Scaleform::RefCountVImpl *)this->pRenderBufferManager.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    this->pRenderBufferManager.pObject = 0;
    Scaleform::Render::D3D1x::TextureManager::Reset(
      (Scaleform::Render::D3D1x::TextureManager *)v11,
      &this->pTextureManager.pObject->__vftable);
    v12 = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    this->pTextureManager.pObject = 0;
    Scaleform::Render::D3D1x::ShaderManager::Reset((Scaleform::Render::D3D1x::ShaderManager *)v12, (int)&this->SManager);
    Scaleform::Render::D3D1x::MeshCache::Reset(v13, (int)&this->Cache);
    ((void (__cdecl *)(ID3D11DeviceContext *))this->pDeviceContext->Release)(this->pDeviceContext);
    this->pDeviceContext = 0;
    p_pDevice = &this->pDevice;
    ((void (__cdecl *)(ID3D11Device *))(*p_pDevice)->Release)(*p_pDevice);
    *p_pDevice = 0;
  }
  return 1;
}
