char __thiscall Scaleform::Render::D3D1x::HAL::InitHAL(Scaleform::Render::D3D1x::HAL *this, int params)
{
  int v2; // esi
  ID3D11Device *v5; // ecx
  ID3D11DeviceContext *v6; // eax
  Scaleform::Render::D3D1x::HAL *v7; // ecx
  Scaleform::Render::D3D1x::HAL *v8; // ecx
  Scaleform::Render::D3D1x::HAL *v9; // ecx
  Scaleform::Render::D3D1x::HAL *v10; // ecx
  int v11; // edi
  Scaleform::Render::D3D1x::TextureManager *v12; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::TextureManager *v14; // eax
  Scaleform::Render::D3D1x::TextureManager *v15; // eax
  Scaleform::Render::D3D1x::TextureManager *v16; // esi
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::Render::D3D1x::ShaderManager *v18; // ecx
  Scaleform::MemoryHeap_vtbl *v19; // eax
  int v20; // eax
  Scaleform::Render::MatrixState *v21; // ecx
  Scaleform::Render::MatrixState *v22; // eax
  Scaleform::Render::MatrixState *v23; // esi
  Scaleform::RefCountVImpl *v24; // ecx
  Scaleform::GFx::Resource *v25; // ecx
  Scaleform::RefCountVImpl *v26; // ecx
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v27; // eax
  Scaleform::Render::RenderBufferManager *v28; // eax
  Scaleform::Render::RenderBufferManager *v29; // esi
  Scaleform::RefCountVImpl *v30; // ecx
  Scaleform::Render::D3D1x::TextureManager *v31; // [esp-8h] [ebp-14h]
  ID3D11DeviceContext *v32; // [esp+8h] [ebp-4h] BYREF

  v2 = params;
  if ( !this->initHAL(this, (const Scaleform::Render::HALInitParams *)params) )
    return 0;
  v5 = *(ID3D11Device **)(v2 + 24);
  if ( !v5 )
    return 0;
  this->pDevice = v5;
  v6 = *(ID3D11DeviceContext **)(v2 + 28);
  v32 = v6;
  if ( !v6 )
  {
    v5->GetImmediateContext(v5, &v32);
    v6 = v32;
  }
  this->pDeviceContext = v6;
  Scaleform::Render::D3D1x::RenderEvent::InitializeEvents(v6);
  this->pDevice->AddRef(this->pDevice);
  this->pDeviceContext->AddRef(this->pDeviceContext);
  if ( !Scaleform::Render::D3D1x::HAL::createBlendStates(v7, (int)this)
    || !Scaleform::Render::D3D1x::HAL::createDepthStencilStates(v8, (int)this)
    || !Scaleform::Render::D3D1x::HAL::createRasterStates(v9, (int)this)
    || !Scaleform::Render::D3D1x::HAL::createConstantBuffers(v10, (int)this)
    || !Scaleform::Render::D3D1x::ShaderManager::Initialize(this, &this->SManager)
    || !Scaleform::Render::D3D1x::MeshCache::Initialize(
          &this->Cache,
          this->pDeviceContext,
          this->pDevice,
          &this->SManager) )
  {
LABEL_45:
    this->pDevice->Release(this->pDevice);
    this->pDeviceContext->Release(this->pDeviceContext);
    this->pDevice = 0;
    this->pDeviceContext = 0;
    return 0;
  }
  v11 = params;
  v12 = *(Scaleform::Render::D3D1x::TextureManager **)(params + 12);
  if ( v12 )
  {
    Scaleform::RefCountImpl::AddRef(*(Scaleform::GFx::Resource **)(params + 12));
    pObject = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pTextureManager.pObject = v12;
  }
  else
  {
    v14 = (Scaleform::Render::TextureManager *)Scaleform::NewOverrideBase<75>::operator new(
                                                 0x130u,
                                                 (Scaleform::MemAddressStub *)this);
    if ( v14 )
    {
      Scaleform::Render::D3D1x::TextureManager::TextureManager(
        v31,
        v14,
        (ID3D11Device_vtbl *)this->pDevice,
        (ID3D11Device_vtbl *)this->pDeviceContext,
        *(Scaleform::Render::ThreadCommandQueue **)(v11 + 8),
        this->pRTCommandQueue);
      v16 = v15;
    }
    else
    {
      v16 = 0;
    }
    v17 = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
    if ( v17 )
      Scaleform::RefCountImpl::Release(v17);
    this->pTextureManager.pObject = v16;
    if ( !v16 )
    {
      Scaleform::Render::D3D1x::MeshCache::Reset((Scaleform::Render::D3D1x::MeshCache *)v17, (int)&this->Cache);
      Scaleform::Render::D3D1x::ShaderManager::Reset(v18, (int)&this->SManager);
    }
  }
  v19 = Scaleform::Memory::pGlobalHeap->__vftable;
  params = 65;
  v20 = (int)v19->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 672u, (const Scaleform::AllocInfo *)&params);
  if ( v20 )
  {
    Scaleform::Render::MatrixState::MatrixState(v21, v20, this);
    v23 = v22;
  }
  else
  {
    v23 = 0;
  }
  v24 = (Scaleform::RefCountVImpl *)this->Matrices.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  this->Matrices.pObject = v23;
  if ( *(_DWORD *)(v11 + 16) )
  {
    v25 = *(Scaleform::GFx::Resource **)(v11 + 16);
    if ( v25 )
      Scaleform::RefCountImpl::AddRef(v25);
    v26 = (Scaleform::RefCountVImpl *)this->pRenderBufferManager.pObject;
    if ( v26 )
      Scaleform::RefCountImpl::Release(v26);
    this->pRenderBufferManager.pObject = *(Scaleform::Render::RenderBufferManager **)(v11 + 16);
    goto LABEL_41;
  }
  v27 = (Scaleform::Render::RBGenericImpl::RenderBufferManager *)Scaleform::NewOverrideBase<75>::operator new(
                                                                   0x5Cu,
                                                                   (Scaleform::MemAddressStub *)this);
  if ( v27 )
  {
    Scaleform::Render::RBGenericImpl::RenderBufferManager::RenderBufferManager(v27, 1, 0xFFFFFFFF, 0);
    v29 = v28;
  }
  else
  {
    v29 = 0;
  }
  v30 = (Scaleform::RefCountVImpl *)this->pRenderBufferManager.pObject;
  if ( v30 )
    Scaleform::RefCountImpl::Release(v30);
  this->pRenderBufferManager.pObject = v29;
  if ( v29 && this->createDefaultRenderBuffer(this) )
  {
LABEL_41:
    if ( this->pTextureManager.pObject && this->pRenderBufferManager.pObject )
    {
      this->HALState |= 1u;
      Scaleform::Render::HAL::notifyHandlers(this, HAL_Initialize);
      return 1;
    }
    goto LABEL_45;
  }
  this->ShutdownHAL(this);
  return 0;
}
