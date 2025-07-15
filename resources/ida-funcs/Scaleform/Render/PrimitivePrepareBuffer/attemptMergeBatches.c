bool __thiscall Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
        Scaleform::Render::PrimitivePrepareBuffer *this,
        Scaleform::Render::PrimitiveBatch *pfirst,
        Scaleform::Render::PrimitiveBatch *psecond,
        Scaleform::Render::PrimitiveBatch *pother,
        Scaleform::Render::PrimitiveBatch *pknown,
        unsigned int *knownVerticesSize,
        unsigned int *knownIndexCount)
{
  const Scaleform::Render::MeshCacheParams *v8; // edi
  unsigned int v9; // ebx
  const Scaleform::Render::VertexFormat *pBatchVFormat; // eax
  unsigned int v11; // edx
  unsigned int ptotalVertices; // [esp+4h] [ebp-8h] BYREF
  unsigned int ptotalIndices; // [esp+8h] [ebp-4h] BYREF

  if ( pother->LargeMesh || !this->pBatchVFormat || pother->Type > (unsigned int)DP_Batch )
    return 0;
  v8 = this->pCache->GetParams(&this->pCache->Scaleform::Render::MeshCacheConfig);
  v9 = psecond->MeshCount + pfirst->MeshCount;
  if ( v9 <= v8->MaxBatchInstances )
  {
    Scaleform::Render::PrimitiveBatch::CalcMeshSizes(pother, &ptotalVertices, &ptotalIndices);
    if ( *knownVerticesSize + ptotalVertices * this->pBatchVFormat->Size <= v8->MaxVerticesSizeInBatch
      && ptotalIndices + *knownIndexCount <= v8->MaxIndicesInBatch )
    {
      pknown->MeshCount = v9;
      pknown->MeshIndex = pfirst->MeshIndex;
      pknown->Type = DP_Batch;
      Scaleform::Render::PrimitiveBatch::ClearCacheItem(pknown);
      Scaleform::Render::PrimitiveBatch::RemoveAndFree(pother);
      Scaleform::Render::PrimitivePrepareBuffer::patchEmitDrawStartIfEq(this, pfirst, pknown);
      if ( this->pPrepare == pfirst )
        this->pPrepare = pknown;
      pBatchVFormat = this->pBatchVFormat;
      v11 = ptotalIndices;
      this->pConvert = pknown;
      *knownVerticesSize += ptotalVertices * pBatchVFormat->Size;
      *knownIndexCount += v11;
      this->Converting = 0;
    }
  }
  return 0;
}
