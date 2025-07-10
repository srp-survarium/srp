bool __usercall Scaleform::Render::D3D1x::HAL::ShutdownHAL@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<ebx>)
{
  bool result; // al
  Scaleform::Render::D3D1x::HAL *v4; // ecx
  Scaleform::Render::D3D1x::HAL *v5; // ecx
  Scaleform::Render::D3D1x::HAL *v6; // ecx
  Scaleform::Render::D3D1x::HAL *v7; // ecx
  ID3D11RenderTargetView *pObject; // eax
  ID3D11DepthStencilView *v9; // eax
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::Render::D3D1x::MeshCache *v12; // ecx
  ID3D11Device *pDevice; // eax

  if ( (this->HALState & 1) != 0 )
  {
    result = this->shutdownHAL(this);
    if ( !result )
      return result;
    ((void (__stdcall *)(ID3D11DeviceContext *, int))Scaleform::Render::D3D1x::RenderEvent::pContext->Release)(
      Scaleform::Render::D3D1x::RenderEvent::pContext,
      a2);
    Scaleform::Render::D3D1x::RenderEvent::pContext = 0;
    Scaleform::Render::D3D1x::HAL::destroyBlendStates(v4, this);
    Scaleform::Render::D3D1x::HAL::destroyDepthStencilStates(v5, this);
    Scaleform::Render::D3D1x::HAL::destroyRasterStates(v6, this);
    Scaleform::Render::D3D1x::HAL::destroyConstantBuffers(v7, this);
    pObject = this->pRenderTargetView.pObject;
    if ( pObject )
      pObject->Release(this->pRenderTargetView.pObject);
    this->pRenderTargetView.pObject = 0;
    v9 = this->pDepthStencilView.pObject;
    if ( v9 )
      v9->Release(this->pDepthStencilView.pObject);
    this->pDepthStencilView.pObject = 0;
    this->destroyRenderBuffers(this);
    v10 = (Scaleform::RefCountVImpl *)this->pRenderBufferManager.pObject;
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    this->pRenderBufferManager.pObject = 0;
    Scaleform::Render::D3D1x::TextureManager::Reset(
      (Scaleform::Render::D3D1x::TextureManager *)v10,
      (int)this->pTextureManager.pObject);
    v11 = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    this->pTextureManager.pObject = 0;
    Scaleform::Render::D3D1x::ShaderManager::Reset(
      (Scaleform::Render::D3D1x::ShaderManager *)v11,
      (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *)&this->SManager);
    Scaleform::Render::D3D1x::MeshCache::Reset(v12, (int)&this->Cache);
    ((void (__cdecl *)(ID3D11DeviceContext *))this->pDeviceContext->Release)(this->pDeviceContext);
    pDevice = this->pDevice;
    this->pDeviceContext = 0;
    pDevice->Release(pDevice);
    this->pDevice = 0;
  }
  return 1;
}
