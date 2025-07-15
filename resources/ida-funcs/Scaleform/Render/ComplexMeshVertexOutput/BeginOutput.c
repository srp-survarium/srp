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
  Scaleform::Render::MeshCacheItem *v11; // [esp+Ch] [ebp-14h] BYREF
  _DWORD v12[4]; // [esp+10h] [ebp-10h] BYREF

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
    v12[3] = (unsigned int)*p_pMesh >> 5;
    pCache = this->pCache;
    v12[0] = &this->pMesh;
    v12[1] = 1;
    v12[2] = 4;
    v9 = pCache->AllocCacheItem(
           pCache,
           &v11,
           &this->pVertexDataStart,
           &this->pIndexDataStart,
           Mesh_Complex,
           (Scaleform::Render::MeshCacheItem::MeshBaseContent *)v12,
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
