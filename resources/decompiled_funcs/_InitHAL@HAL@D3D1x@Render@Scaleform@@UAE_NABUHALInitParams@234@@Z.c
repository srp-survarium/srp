char __userpurge Scaleform::Render::D3D1x::HAL::InitHAL@<al>(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        Scaleform::Render::TextureCache *a2@<edi>,
        ID3D11DeviceContext *params)
{
  ID3D11DeviceContext *v3; // ebp
  char result; // al
  ID3D11Device *v6; // ecx
  const Scaleform::Render::D3D1x::HALInitParams *v7; // eax
  void (__stdcall *v8)(const Scaleform::Render::D3D1x::HALInitParams *); // edx
  Scaleform::Render::D3D1x::HAL *v9; // ecx
  Scaleform::Render::D3D1x::HAL *v10; // ecx
  Scaleform::Render::D3D1x::HAL *v11; // ecx
  Scaleform::Render::D3D1x::HAL *v12; // ecx
  Scaleform::Render::D3D1x::TextureManager *v13; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::D3D1x::TextureManager *v15; // edi
  Scaleform::Render::D3D1x::TextureManager *v16; // eax
  Scaleform::Render::D3D1x::TextureManager *v17; // esi
  Scaleform::RefCountVImpl *v18; // ecx
  Scaleform::Render::D3D1x::ShaderManager *v19; // ecx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  int v21; // eax
  Scaleform::Render::MatrixState *v22; // ecx
  Scaleform::Render::MatrixState *v23; // eax
  Scaleform::Render::MatrixState *v24; // esi
  Scaleform::RefCountVImpl *v25; // ecx
  Scaleform::GFx::Resource *v26; // ecx
  Scaleform::RefCountVImpl *v27; // ecx
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v28; // eax
  Scaleform::Render::RenderBufferManager *v29; // eax
  Scaleform::Render::RenderBufferManager *v30; // esi
  Scaleform::RefCountVImpl *v31; // ecx
  int v33; // [esp+18h] [ebp-4h] BYREF

  v3 = params;
  if ( !this->initHAL(this, (const Scaleform::Render::HALInitParams *)params) )
    return 0;
  v6 = (ID3D11Device *)v3[6].lpVtbl;
  if ( !v6 )
    return 0;
  this->pDevice = v6;
  v7 = (const Scaleform::Render::D3D1x::HALInitParams *)v3[7].lpVtbl;
  params = (ID3D11DeviceContext *)v7;
  if ( !v7 )
  {
    v6->GetImmediateContext(v6, &params);
    v7 = (const Scaleform::Render::D3D1x::HALInitParams *)params;
  }
  this->pDeviceContext = (ID3D11DeviceContext *)v7;
  v8 = (void (__stdcall *)(const Scaleform::Render::D3D1x::HALInitParams *))*((_DWORD *)v7->pMemoryManager + 1);
  Scaleform::Render::D3D1x::RenderEvent::pContext = (ID3D11DeviceContext *)v7;
  v8(v7);
  this->pDevice->AddRef(this->pDevice);
  this->pDeviceContext->AddRef(this->pDeviceContext);
  if ( Scaleform::Render::D3D1x::HAL::createBlendStates(v9, this)
    && Scaleform::Render::D3D1x::HAL::createDepthStencilStates(v10, this)
    && Scaleform::Render::D3D1x::HAL::createRasterStates(v11, (int)this)
    && Scaleform::Render::D3D1x::HAL::createConstantBuffers(v12, this)
    && Scaleform::Render::D3D1x::ShaderManager::Initialize(this, &this->SManager)
    && Scaleform::Render::D3D1x::MeshCache::Initialize(
         this->pDevice,
         this->pDeviceContext,
         &this->Cache,
         &this->SManager) )
  {
    v13 = (Scaleform::Render::D3D1x::TextureManager *)v3[3].lpVtbl;
    if ( v13 )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v3[3].lpVtbl);
      pObject = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      this->pTextureManager.pObject = v13;
    }
    else
    {
      v15 = (Scaleform::Render::D3D1x::TextureManager *)Scaleform::NewOverrideBase<75>::operator new(
                                                          0x130u,
                                                          (Scaleform::MemAddressStub *)this);
      if ( v15 )
      {
        Scaleform::Render::D3D1x::TextureManager::TextureManager(
          v15,
          v3[2].lpVtbl,
          this->pRTCommandQueue,
          this->pDevice,
          this->pDeviceContext,
          a2);
        v17 = v16;
      }
      else
      {
        v17 = 0;
      }
      v18 = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
      if ( v18 )
        Scaleform::RefCountImpl::Release(v18);
      this->pTextureManager.pObject = v17;
      if ( !v17 )
      {
        Scaleform::Render::D3D1x::MeshCache::Reset((Scaleform::Render::D3D1x::MeshCache *)v18, (int)&this->Cache);
        Scaleform::Render::D3D1x::ShaderManager::Reset(
          v19,
          (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *)&this->SManager);
      }
    }
    AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
    v33 = 65;
    v21 = (int)AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 672u, (const Scaleform::AllocInfo *)&v33);
    if ( v21 )
    {
      Scaleform::Render::MatrixState::MatrixState(v22, v21, this);
      v24 = v23;
    }
    else
    {
      v24 = 0;
    }
    v25 = (Scaleform::RefCountVImpl *)this->Matrices.pObject;
    if ( v25 )
      Scaleform::RefCountImpl::Release(v25);
    this->Matrices.pObject = v24;
    if ( v3[4].lpVtbl )
    {
      v26 = (Scaleform::GFx::Resource *)v3[4].lpVtbl;
      if ( v26 )
        Scaleform::RefCountImpl::AddRef(v26);
      v27 = (Scaleform::RefCountVImpl *)this->pRenderBufferManager.pObject;
      if ( v27 )
        Scaleform::RefCountImpl::Release(v27);
      this->pRenderBufferManager.pObject = (Scaleform::Render::RenderBufferManager *)v3[4].lpVtbl;
    }
    else
    {
      v28 = (Scaleform::Render::RBGenericImpl::RenderBufferManager *)Scaleform::NewOverrideBase<75>::operator new(
                                                                       0x5Cu,
                                                                       (Scaleform::MemAddressStub *)this);
      if ( v28 )
      {
        Scaleform::Render::RBGenericImpl::RenderBufferManager::RenderBufferManager(v28, 1, 0xFFFFFFFF, 0);
        v30 = v29;
      }
      else
      {
        v30 = 0;
      }
      v31 = (Scaleform::RefCountVImpl *)this->pRenderBufferManager.pObject;
      if ( v31 )
        Scaleform::RefCountImpl::Release(v31);
      this->pRenderBufferManager.pObject = v30;
      if ( !v30 || !this->createDefaultRenderBuffer(this) )
      {
        this->ShutdownHAL(this);
        return 0;
      }
    }
    if ( this->pTextureManager.pObject && this->pRenderBufferManager.pObject )
    {
      this->HALState |= 1u;
      Scaleform::Render::HAL::notifyHandlers(this, HAL_Initialize);
      return 1;
    }
  }
  this->pDevice->Release(this->pDevice);
  this->pDeviceContext->Release(this->pDeviceContext);
  result = 0;
  this->pDevice = 0;
  this->pDeviceContext = 0;
  return result;
}
