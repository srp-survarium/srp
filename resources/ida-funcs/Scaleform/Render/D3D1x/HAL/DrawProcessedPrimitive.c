void __thiscall Scaleform::Render::D3D1x::HAL::DrawProcessedPrimitive(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::Primitive *pprimitive,
        Scaleform::Render::PrimitiveBatch *pstart,
        Scaleform::Render::PrimitiveBatch *pend)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer_vtbl *v6; // edx
  Scaleform::AmpStats *v7; // eax
  Scaleform::String::DataDesc *v8; // ecx
  Scaleform::Render::RenderEvent *v9; // eax
  Scaleform::Render::D3D1x::ProfileViewScopedOMChange *v10; // ecx
  Scaleform::Render::PrimitiveBatch *pNext; // esi
  Scaleform::Render::MeshCacheItem *pMeshItem; // edi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *MeshCount; // eax
  Scaleform::Render::Color *ColorForBatch; // eax
  bool v15; // zf
  Scaleform::Render::Primitive::MeshEntry *Data; // ecx
  Scaleform::Render::ProfileViews *Profiler; // edx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v18; // eax
  Scaleform::Render::MeshCacheItem *v19; // edx
  Scaleform::Render::D3D1x::ShaderPair *v20; // ecx
  Scaleform::Render::D3D1x::HAL *v21; // ecx
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *inserted; // eax
  Scaleform::Render::Fence *pObject; // ecx
  Scaleform::Render::PrimitiveBatch *v24; // esi
  Scaleform::String v25; // [esp+24h] [ebp-64h] BYREF
  Scaleform::AmpNativeFunctionId v26; // [esp+28h] [ebp-60h]
  Scaleform::Render::PrimitiveBatch *v27; // [esp+38h] [ebp-50h]
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> batchType; // [esp+3Ch] [ebp-4Ch] BYREF
  Scaleform::Render::MeshBase **pMeshes; // [esp+54h] [ebp-34h] BYREF
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *v30; // [esp+58h] [ebp-30h]
  Scaleform::Render::Color result; // [esp+5Ch] [ebp-2Ch] BYREF
  Scaleform::AmpFunctionTimer v32; // [esp+60h] [ebp-28h] BYREF
  Scaleform::Render::D3D1x::ProfileViewScopedOMChange v33; // [esp+74h] [ebp-14h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v6 = Instance->__vftable;
  v25.pData = (Scaleform::String::DataDesc *)-1;
  v7 = (Scaleform::AmpStats *)((int (__thiscall *)(Scaleform::AmpServer *, const char *))v6->GetDisplayStats)(
                                Instance,
                                "Scaleform::Render::D3D1x::HAL::DrawProcessedPrimitive");
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    (Scaleform::AmpFunctionTimer *)((char *)&v32.StartTicks + 4),
    v7,
    (const char *)2,
    -1,
    v26);
  v26 = Amp_Native_Function_Id_AdvanceFrame;
  v25.pData = v8;
  Scaleform::String::String(&v25, "Scaleform::Render::D3D1x::HAL::DrawProcessedPrimitive");
  v9 = (Scaleform::Render::RenderEvent *)((int (__thiscall *)(Scaleform::Render::D3D1x::HAL *))this->GetEvent)(this);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(
    (Scaleform::Render::ScopedRenderEvent *)&batchType.VFormats.ValueBuffer.pLast,
    v9,
    (Scaleform::String)9,
    (bool)v25.pData);
  if ( Scaleform::Render::HAL::checkState(
         this,
         8u,
         (Scaleform::GFx::AS3::Value *)"Scaleform::Render::D3D1x::HAL::DrawProcessedPrimitive")
    && pprimitive->Meshes.Data.Size )
  {
    if ( this->Profiler.OverrideMasks && !drawingMask && (this->HALState & 0x40) != 0 )
    {
      Scaleform::Render::D3D1x::ProfileViewScopedOMChange::ProfileViewScopedOMChange(
        &v33,
        &drawingMask,
        this->pDeviceContext,
        this->BlendStates[36],
        this->DepthStencilStates[0]);
      this->DrawProcessedPrimitive(this, pprimitive, pstart, pend);
      Scaleform::Render::D3D1x::ProfileViewScopedOMChange::~ProfileViewScopedOMChange(v10, (int)&v33);
    }
    pNext = pstart;
    if ( !pstart )
      pNext = pprimitive->Batches.Root.pNext;
    v27 = pNext;
    Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
    batchType.VFormats.KeyBuffer.pLast = 0;
    if ( pNext != pend )
    {
      while ( 1 )
      {
        pMeshItem = pNext->MeshNode.pMeshItem;
        batchType.Profiler = (Scaleform::Render::ProfileViews *)pNext->MeshIndex;
        MeshCount = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *)pNext->MeshCount;
        v30 = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *)pMeshItem;
        batchType.VFormats.ValueBuffer.pPages = MeshCount;
        if ( pMeshItem )
        {
          ColorForBatch = Scaleform::Render::ProfileViews::GetColorForBatch(
                            &this->Profiler,
                            &result,
                            (__int16)pprimitive,
                            (unsigned __int16)batchType.VFormats.KeyBuffer.pLast);
          v15 = batchType.VFormats.ValueBuffer.pPages == 0;
          this->Profiler.BatchColor = *ColorForBatch;
          batchType.VFormats.KeyBuffer.pPages = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *)this->FillFlags;
          if ( !v15 )
            batchType.VFormats.KeyBuffer.pPages = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *)((int)batchType.VFormats.KeyBuffer.pPages | (pprimitive->Meshes.Data.Data->M.pHandle->pHeader->Format >> 1) & 8);
          Data = pprimitive->Meshes.Data.Data;
          Profiler = batchType.Profiler;
          batchType.Profiler = (Scaleform::Render::ProfileViews *)pprimitive->pFill.pObject;
          v18 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetPrimitiveFill(
                  (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&Data[(_DWORD)Profiler],
                  (Scaleform::Render::PrimitiveFill *)&this->SManager,
                  (Scaleform::Render::PrimitiveFill *)batchType.Profiler,
                  &batchType,
                  (const Scaleform::Render::VertexFormat *)pNext->Type,
                  pNext->pFormat,
                  (const Scaleform::Render::Matrix2x4<float> *)batchType.VFormats.ValueBuffer.pPages,
                  this->Matrices.pObject,
                  &Data[(_DWORD)Profiler].M,
                  &this->ShaderData);
          v19 = pMeshItem[1].pNext;
          batchType.Profiler = (Scaleform::Render::ProfileViews *)v18;
          batchType.VFormats.ValueBuffer.pPages = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *)((unsigned int)pMeshItem[1].Type >> 1);
          pMeshes = pMeshItem[1].pPrev->pMeshes;
          batchType.VertexFormatComputedHash = (Scaleform::HashLH<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash,Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash>,2,Scaleform::HashNode<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash,Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash,Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash> >,Scaleform::HashNode<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash,Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::ResultFormat,Scaleform::FixedSizeHash<Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SourceFormatHash> >::NodeHashF> >)pMeshItem[1].pCacheList;
          this->pDeviceContext->IASetIndexBuffer(
            this->pDeviceContext,
            (ID3D11Buffer *)v19->pMeshes,
            DXGI_FORMAT_R16_UINT,
            0);
          this->pDeviceContext->IASetVertexBuffers(
            this->pDeviceContext,
            0,
            1u,
            (ID3D11Buffer *const *)&pMeshes,
            (const unsigned int *)pNext->pFormat,
            (const unsigned int *)&batchType.VertexFormatComputedHash);
          if ( (this->HALState & 0x20) != 0
            && Scaleform::Render::D3D1x::ShaderPair::operator bool(v20, batchType.Profiler) )
          {
            v15 = pNext->Type == DP_Instanced;
            v25.pData = 0;
            if ( v15 )
            {
              Scaleform::Render::D3D1x::HAL::drawIndexedInstanced(
                this,
                pNext->MeshCount,
                pMeshItem->IndexCount,
                (unsigned int)batchType.VFormats.ValueBuffer.pPages,
                (int)v25.pData);
              pMeshItem = (Scaleform::Render::MeshCacheItem *)v30;
            }
            else
            {
              Scaleform::Render::D3D1x::HAL::drawIndexedPrimitive(
                v21,
                (int)this,
                pMeshItem->IndexCount,
                pMeshItem->MeshCount,
                (unsigned int)batchType.VFormats.ValueBuffer.pPages,
                v25.HeapTypeBits);
            }
            pNext = v27;
          }
          inserted = Scaleform::Render::RenderSync::InsertFence(&this->Cache.RSync);
          v30 = inserted;
          if ( inserted )
            ++inserted->Data[0].RefCount;
          pObject = pMeshItem->GPUFence.pObject;
          if ( pObject )
          {
            Scaleform::Render::Fence::Release(pObject);
            inserted = v30;
          }
          v25.pData = (Scaleform::String::DataDesc *)2;
          pMeshItem->GPUFence.pObject = (Scaleform::Render::Fence *)inserted;
          Scaleform::Render::MeshCacheItem::MoveToCacheListFront(
            pMeshItem,
            (Scaleform::Render::MeshCacheListType)v25.pData);
        }
        v24 = pNext->pNext;
        ++batchType.VFormats.KeyBuffer.pLast;
        v27 = v24;
        if ( v24 == pend )
          break;
        pNext = v27;
      }
    }
  }
  ((void (__thiscall *)(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *))batchType.VFormats.ValueBuffer.pLast->pNext->Items[0].KeyCount)(batchType.VFormats.ValueBuffer.pLast);
  Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v32);
}
