void __thiscall Scaleform::Render::D3D1x::HAL::DrawProcessedPrimitive(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::Primitive *pprimitive,
        Scaleform::Render::PrimitiveBatch *pstart,
        Scaleform::Render::PrimitiveBatch *pend)
{
  Scaleform::Render::RenderEvent *EventObj; // esi
  Scaleform::Render::RenderEvent v6; // ebx
  unsigned int v7; // ecx
  void *v8; // ebx
  Scaleform::Render::Primitive *v9; // eax
  Scaleform::Render::PrimitiveBatch *pNext; // ebx
  Scaleform::Render::MeshCacheItem *pMeshItem; // esi
  unsigned int MeshCount; // ecx
  Scaleform::Render::Primitive::MeshEntry *Data; // edx
  unsigned int MeshIndex; // ecx
  const Scaleform::Render::D3D1x::ShaderPair *v15; // eax
  ID3D11Buffer *pMeshes; // edx
  unsigned int pCacheList; // eax
  Scaleform::Render::MeshCacheItem *v18; // edx
  const Scaleform::Render::D3D1x::FragShader *pFS; // eax
  bool v20; // zf
  ID3D11DeviceContext *pDeviceContext; // eax
  ID3D11DeviceContext_vtbl *v22; // ecx
  const Scaleform::Render::D3D1x::ShaderPair *inserted; // eax
  Scaleform::Render::Fence *pObject; // ecx
  Scaleform::Render::MeshCacheListSet *v25; // ecx
  unsigned int *p_Size; // eax
  Scaleform::Render::MeshCacheListSet *v27; // ecx
  Scaleform::Render::MeshCacheItem *v28; // edx
  Scaleform::String v29[5]; // [esp+30h] [ebp-2Ch] BYREF
  unsigned int indexOffset; // [esp+44h] [ebp-18h] BYREF
  Scaleform::String src; // [esp+48h] [ebp-14h] BYREF
  const Scaleform::Render::D3D1x::ShaderPair *pShader; // [esp+4Ch] [ebp-10h]
  unsigned int offset; // [esp+50h] [ebp-Ch] BYREF
  ID3D11Buffer *pb; // [esp+54h] [ebp-8h] BYREF
  Scaleform::Render::ScopedRenderEvent GPUEvent; // [esp+58h] [ebp-4h]

  Scaleform::String::String(&src, (char *)&stru_973E7C);
  EventObj = this->GetEvent(this, 9);
  v6.__vftable = EventObj->__vftable;
  v29[0].HeapTypeBits = v7;
  GPUEvent.EventObj = EventObj;
  Scaleform::String::String(v29, &src);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, unsigned int))v6.Begin)(EventObj, v29[0].HeapTypeBits);
  v8 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  if ( (this->HALState & 8) != 0 )
  {
    v9 = pprimitive;
    if ( pprimitive->Meshes.Data.Size )
    {
      pNext = pstart;
      if ( !pstart )
        pNext = pprimitive->Batches.Root.pNext;
      *(_QWORD *)this->ShaderData.UniformSet = 0;
      *(_DWORD *)&this->ShaderData.UniformSet[8] = 0;
      *(_WORD *)&this->ShaderData.UniformSet[12] = 0;
      this->ShaderData.UniformSet[14] = 0;
      *(_QWORD *)this->ShaderData.Textures = 0;
      *(_QWORD *)&this->ShaderData.Textures[2] = 0;
      if ( pNext != pend )
      {
        do
        {
          pMeshItem = pNext->MeshNode.pMeshItem;
          MeshCount = pNext->MeshCount;
          if ( pMeshItem )
          {
            indexOffset = this->FillFlags;
            if ( MeshCount )
              indexOffset |= (v9->Meshes.Data.Data->M.pHandle->pHeader->Format >> 1) & 8;
            Data = v9->Meshes.Data.Data;
            MeshIndex = pNext->MeshIndex;
            pShader = (const Scaleform::Render::D3D1x::ShaderPair *)v9->pFill.pObject;
            v15 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetPrimitiveFill(
                    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)pShader,
                    (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)&indexOffset,
                    (Scaleform::Render::PrimitiveFill *)pNext->Type,
                    pNext->pFormat,
                    (const Scaleform::Render::VertexFormat *)pNext->MeshCount,
                    this->Matrices.pObject,
                    &Data[MeshIndex],
                    &this->ShaderData,
                    (Scaleform::Render::D3D1x::ShaderInterface *)v29[1].pData);
            pMeshes = (ID3D11Buffer *)pMeshItem[1].pPrev->pMeshes;
            pShader = v15;
            indexOffset = (unsigned int)pMeshItem[1].Type >> 1;
            pCacheList = (unsigned int)pMeshItem[1].pCacheList;
            pb = pMeshes;
            v18 = pMeshItem[1].pNext;
            offset = pCacheList;
            this->pDeviceContext->IASetIndexBuffer(
              this->pDeviceContext,
              (ID3D11Buffer *)v18->pMeshes,
              DXGI_FORMAT_R16_UINT,
              0);
            this->pDeviceContext->IASetVertexBuffers(
              this->pDeviceContext,
              0,
              1u,
              &pb,
              (const unsigned int *)pNext->pFormat,
              &offset);
            if ( (this->HALState & 0x20) != 0 )
            {
              if ( pShader->pVS )
              {
                pFS = pShader->pFS;
                if ( pFS )
                {
                  if ( pShader->pVS->pProg.pObject && pFS->pProg.pObject && pShader->pVFormat )
                  {
                    v20 = pNext->Type == DP_Instanced;
                    pDeviceContext = this->pDeviceContext;
                    v22 = pDeviceContext->lpVtbl;
                    v29[0].HeapTypeBits = 0;
                    if ( v20 )
                      v22->DrawIndexedInstanced(
                        pDeviceContext,
                        pMeshItem->IndexCount,
                        pNext->MeshCount,
                        indexOffset,
                        0,
                        v29[0].HeapTypeBits);
                    else
                      v22->DrawIndexed(pDeviceContext, pMeshItem->IndexCount, indexOffset, v29[0].HeapTypeBits);
                  }
                }
              }
            }
            inserted = (const Scaleform::Render::D3D1x::ShaderPair *)Scaleform::Render::RenderSync::InsertFence(&this->Cache.RSync);
            pShader = inserted;
            if ( inserted )
              ++LOWORD(inserted->pVDesc);
            pObject = pMeshItem->GPUFence.pObject;
            if ( pObject )
            {
              Scaleform::Render::Fence::Release(pObject);
              inserted = pShader;
            }
            pMeshItem->GPUFence.pObject = (Scaleform::Render::Fence *)inserted;
            v25 = pMeshItem->pCacheList;
            pMeshItem->pPrev->pNext = pMeshItem->pNext;
            pMeshItem->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$181941B0ECCE92AAF0AD80025FE0C204::pPrev = pMeshItem->pPrev;
            p_Size = &v25->Slots[pMeshItem->ListType].Size;
            *p_Size -= pMeshItem->AllocSize;
            v27 = pMeshItem->pCacheList;
            pMeshItem->ListType = MCL_ThisFrame;
            v28 = v27->Slots[2].Root.pNext;
            pMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)&v27->Slots[2];
            pMeshItem->pNext = v28;
            v27->Slots[2].Root.pNext->pPrev = pMeshItem;
            v27->Slots[2].Root.pNext = pMeshItem;
            v27->Slots[2].Size += pMeshItem->AllocSize;
            v9 = pprimitive;
          }
          pNext = pNext->pNext;
        }
        while ( pNext != pend );
        EventObj = GPUEvent.EventObj;
      }
    }
    EventObj->End(EventObj);
  }
  else
  {
    Scaleform::GFx::AS2::Object::SetValue((Scaleform::GFx::AS3::Instances::fl_geom::Transform *)this, 8u, &stru_973E7C);
    EventObj->End(EventObj);
  }
}
