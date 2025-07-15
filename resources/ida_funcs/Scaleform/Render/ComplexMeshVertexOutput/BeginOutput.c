bool __thiscall Scaleform::Render::ComplexMeshVertexOutput::BeginOutput(
        Scaleform::Render::ComplexMeshVertexOutput *this,
        const Scaleform::Render::VertexOutput::Fill *fills,
        unsigned int fillCount,
        const Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  const Scaleform::Render::VertexOutput::Fill *v4; // ebp
  Scaleform::Render::ComplexMesh **p_pMesh; // edi
  Scaleform::Render::MeshCache *pCache; // ecx
  Scaleform::Render::MeshCache::AllocResult v9; // eax
  BOOL WaitForCache; // [esp-8h] [ebp-28h]
  Scaleform::Render::MeshCacheItem *batchData; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::Render::MeshCacheItem::MeshBaseContent mc; // [esp+10h] [ebp-10h] BYREF

  v4 = fills;
  p_pMesh = &this->pMesh;
  if ( Scaleform::Render::ComplexMesh::InitFillRecords(
         this->pMesh,
         fills,
         fillCount,
         vertexMatrix,
         this->pHAL,
         (unsigned int *)&fills,
         &fillCount,
         (unsigned int *)&vertexMatrix) )
  {
    WaitForCache = this->WaitForCache;
    mc.HashKey = (unsigned int)*p_pMesh >> 5;
    pCache = this->pCache;
    mc.Meshes.pData = &this->pMesh;
    mc.Meshes.Size = 1;
    mc.Meshes.StrideSize = 4;
    v9 = pCache->AllocCacheItem(
           pCache,
           &batchData,
           &this->pVertexDataStart,
           &this->pIndexDataStart,
           Mesh_Complex,
           &mc,
           (unsigned int)fills,
           fillCount,
           (unsigned int)vertexMatrix,
           WaitForCache,
           0);
    this->AllocState = v9;
    this->pFills = v4;
    if ( v9 == Alloc_Fail_TooBig )
      (*p_pMesh)->AllocTooBig = 1;
    return this->AllocState == Alloc_Success;
  }
  else
  {
    (*p_pMesh)->AllocTooBig = 1;
    return 0;
  }
}
