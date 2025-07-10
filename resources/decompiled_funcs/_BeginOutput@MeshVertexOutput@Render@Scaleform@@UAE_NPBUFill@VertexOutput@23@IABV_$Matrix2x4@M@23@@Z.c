BOOL __thiscall Scaleform::Render::MeshVertexOutput::BeginOutput(
        Scaleform::Render::MeshVertexOutput *this,
        const Scaleform::Render::VertexOutput::Fill *fills,
        unsigned int fillCount,
        const Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  Scaleform::Render::Mesh *pMesh; // ebx
  Scaleform::Render::MeshBase **p_pMesh; // edi
  const Scaleform::Render::VertexFormat *pBatchFormat; // ecx
  unsigned int VertexCount; // ecx
  const Scaleform::Render::VertexFormat *pSingleFormat; // edx
  unsigned int Size; // edx
  Scaleform::Render::MeshCache::AllocResult v11; // eax
  Scaleform::Render::MeshCache *pCache; // ecx
  Scaleform::Render::MeshCacheItem *batchData; // [esp-4h] [ebp-24h]
  Scaleform::Render::MeshCacheItem::MeshBaseContent mc; // [esp+10h] [ebp-10h] BYREF

  pMesh = this->pMesh;
  p_pMesh = &this->pMesh;
  if ( !pMesh->LargeMesh )
  {
    pBatchFormat = this->pBatchFormat;
    if ( pBatchFormat )
    {
      if ( pBatchFormat->Size * fills->VertexCount <= this->pCache->Params.NoBatchVerticesSizeThreshold )
      {
LABEL_6:
        this->Result.Value = Scaleform::Render::MeshStagingBuffer::AllocateMesh(
                               &this->pCache->StagingBuffer,
                               pMesh,
                               fills->VertexCount,
                               this->pSourceFormat->Size,
                               fills->IndexCount) != 0
                           ? Success_Staging
                           : Fail_Staging_NoBuffer;
        goto LABEL_15;
      }
    }
    else if ( !this->pSingleFormat )
    {
      goto LABEL_6;
    }
  }
  VertexCount = fills->VertexCount;
  mc.HashKey = (unsigned int)pMesh >> 5;
  pSingleFormat = this->pSingleFormat;
  mc.Meshes.pData = p_pMesh;
  mc.Meshes.Size = 1;
  mc.Meshes.StrideSize = 4;
  Size = pSingleFormat->Size;
  pMesh->VertexCount = VertexCount;
  (*p_pMesh)->IndexCount = fills->IndexCount;
  LOBYTE((*p_pMesh)[1].pProvider.pObject) = 1;
  v11 = this->pCache->AllocCacheItem(
          this->pCache,
          &this->batchData,
          &this->pVertexDataStart,
          &this->pIndexDataStart,
          Mesh_Regular,
          &mc,
          VertexCount * Size,
          fills->VertexCount,
          fills->IndexCount,
          this->WaitForCache,
          this->pSingleFormat);
  if ( v11 == Alloc_Success )
  {
    batchData = this->batchData;
    pCache = this->pCache;
    this->Result.Value = Success_LargeMesh;
    Scaleform::Render::MeshCache::MoveToCacheListFront(pCache, MCL_ThisFrame, batchData);
  }
  else if ( v11 )
  {
    if ( v11 == Alloc_Fail_TooBig )
    {
      this->Result.Value = Fail_LargeMesh_TooBig;
    }
    else if ( v11 == Alloc_Fail_ThisFrame )
    {
      this->Result.Value = Fail_LargeMesh_ThisFrame;
    }
  }
  else
  {
    this->Result.Value = Fail_LargeMesh_NeedCache;
  }
LABEL_15:
  *(Scaleform::Render::Matrix2x4<float> *)&(*p_pMesh)[1].pNext = *vertexMatrix;
  return this->Result.Value <= Success_LargeMesh;
}
