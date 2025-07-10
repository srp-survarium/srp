void __usercall Scaleform::Render::D3D1x::HAL::HAL(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        Scaleform::Render::ThreadCommandQueue *commandQueue@<eax>)
{
  Scaleform::Render::D3D1x::MeshCache *v3; // ecx
  Scaleform::Render::MeshCacheParams params; // [esp+Ch] [ebp-2Ch] BYREF

  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(
    this,
    commandQueue);
  v3 = (Scaleform::Render::D3D1x::MeshCache *)Scaleform::Memory::pGlobalHeap;
  params.MemReserve = (unsigned int)&loc_2FFFFF + 1;
  params.MemGranularity = (unsigned int)&loc_2FFFFF + 1;
  this->__vftable = (Scaleform::Render::D3D1x::HAL_vtbl *)&Scaleform::Render::D3D1x::HAL::`vftable';
  this->pDevice = 0;
  this->pDeviceContext = 0;
  this->pRenderTargetView.pObject = 0;
  this->pDepthStencilView.pObject = 0;
  params.MemLimit = (unsigned int)&vostok::memory::s_CRT_arena[5574200];
  params.LRUTailSize = (unsigned int)&vostok::resources::g_resources_manager.m_static_memory[62144];
  params.StagingBufferSize = (unsigned int)&loc_1FFFFE + 2;
  params.VBLockEvictSizeLimit = 0x40000;
  params.MaxBatchInstances = 24;
  params.InstancingThreshold = 5;
  params.NoBatchVerticesSizeThreshold = 0x2000;
  params.MaxVerticesSizeInBatch = 0x4000;
  params.MaxIndicesInBatch = 6144;
  Scaleform::Render::D3D1x::MeshCache::MeshCache(v3, (int)&this->Cache, (Scaleform::MemoryHeap *)v3, &params);
  this->pTextureManager.pObject = 0;
  this->StencilChecked = 0;
  this->StencilAvailable = 0;
  this->DepthBufferAvailable = 0;
  this->RasterMode = RasterMode_Default;
  this->CurrentConstantBuffer = 0;
  this->PrevBatchType = DP_None;
}
