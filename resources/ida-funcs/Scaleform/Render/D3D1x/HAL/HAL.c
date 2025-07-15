void __userpurge Scaleform::Render::D3D1x::HAL::HAL(
        Scaleform::Render::D3D1x::HAL *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  Scaleform::Render::D3D1x::MeshCache *v3; // ecx
  Scaleform::MemoryHeap *v4; // [esp-8h] [ebp-3Ch]
  Scaleform::Render::MeshCacheParams params; // [esp+8h] [ebp-2Ch] BYREF

  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(
    this,
    (Scaleform::Render::HAL *)a2,
    commandQueue);
  params.MemReserve = (unsigned int)&loc_300000;
  params.MemGranularity = (unsigned int)&loc_300000;
  v4 = Scaleform::Memory::pGlobalHeap;
  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::HAL::`vftable';
  *(_DWORD *)(a2 + 63952) = 0;
  *(_DWORD *)(a2 + 63956) = 0;
  *(_DWORD *)(a2 + 63960) = 0;
  *(_DWORD *)(a2 + 63964) = 0;
  params.MemLimit = (unsigned int)&s_ui_commands_allocator.m_buffer[2035360];
  params.LRUTailSize = 10485760;
  params.StagingBufferSize = (unsigned int)&loc_200000;
  params.VBLockEvictSizeLimit = (unsigned int)&loc_3FFFF + 1;
  params.MaxBatchInstances = 24;
  params.InstancingThreshold = 5;
  params.NoBatchVerticesSizeThreshold = 0x2000;
  params.MaxVerticesSizeInBatch = 0x4000;
  params.MaxIndicesInBatch = 6144;
  Scaleform::Render::D3D1x::MeshCache::MeshCache(v3, a2 + 63968, v4, &params);
  *(_DWORD *)(a2 + 64368) = 0;
  *(_BYTE *)(a2 + 64376) = 0;
  *(_BYTE *)(a2 + 64377) = 0;
  *(_BYTE *)(a2 + 64378) = 0;
  *(_DWORD *)(a2 + 64560) = 0;
  *(_DWORD *)(a2 + 64604) = 0;
  *(_DWORD *)(a2 + 64372) = 5;
}
