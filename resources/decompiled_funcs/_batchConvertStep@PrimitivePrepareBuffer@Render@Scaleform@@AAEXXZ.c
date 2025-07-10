void __thiscall Scaleform::Render::PrimitivePrepareBuffer::batchConvertStep(
        Scaleform::Render::PrimitivePrepareBuffer *this)
{
  Scaleform::Render::MeshCacheConfig *v2; // ecx
  const Scaleform::Render::MeshCacheParams *(__thiscall *GetParams)(Scaleform::Render::MeshCacheConfig *); // edx
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  int v6; // eax
  const Scaleform::Render::VertexFormat *pBatchVFormat; // edx
  Scaleform::Render::PrimitiveBatch *pConvert; // eax
  unsigned int v9; // edi
  Scaleform::Render::Primitive::MeshEntry *Data; // ecx
  unsigned int MeshCount; // eax
  Scaleform::Render::Primitive::MeshEntry *v12; // ecx
  Scaleform::Render::Mesh *v13; // edi
  unsigned int MaxBatchInstances; // eax
  unsigned int v15; // ecx
  unsigned int v16; // eax
  bool v17; // cf
  unsigned int v18; // eax
  Scaleform::Ptr<Scaleform::Render::Mesh> *p_pMesh; // ecx
  unsigned int v20; // edi
  Scaleform::Render::PrimitiveBatch *v21; // eax
  Scaleform::Render::PrimitiveBatch *v22; // eax
  Scaleform::Render::PrimitiveBatch *v23; // eax
  Scaleform::Render::PrimitiveBatch *v24; // eax
  Scaleform::Render::PrimitiveBatch *v25; // ecx
  Scaleform::Render::PrimitiveEmitBuffer *pEmitBuffer; // ecx
  Scaleform::Render::PrimitiveBatch *v27; // eax
  Scaleform::Render::PrimitiveBatch *v28; // edi
  Scaleform::Render::PrimitiveBatch *v29; // eax
  Scaleform::Render::PrimitiveEmitBuffer *v30; // eax
  Scaleform::Render::PrimitiveBatch *v31; // ecx
  bool instancingSupported; // [esp+11h] [ebp-37h]
  bool meshTooBigFail; // [esp+12h] [ebp-36h]
  bool largeTailMesh; // [esp+13h] [ebp-35h]
  unsigned int meshIndex; // [esp+14h] [ebp-34h]
  Scaleform::Render::PrimitiveBatch::BatchType tailMeshType; // [esp+18h] [ebp-30h]
  unsigned int tailRepeatCount; // [esp+1Ch] [ebp-2Ch]
  const Scaleform::Render::MeshCacheParams *params; // [esp+20h] [ebp-28h]
  unsigned int totalVerticesSize; // [esp+24h] [ebp-24h] BYREF
  Scaleform::Render::Mesh **p_pObject; // [esp+28h] [ebp-20h]
  Scaleform::Render::Mesh *pprevMesh; // [esp+2Ch] [ebp-1Ch]
  unsigned int instancingThreshold; // [esp+30h] [ebp-18h]
  unsigned int totalIndexCount; // [esp+34h] [ebp-14h] BYREF
  unsigned int batchVertexSize; // [esp+38h] [ebp-10h]
  unsigned int originalConvertMeshCount; // [esp+3Ch] [ebp-Ch]
  Scaleform::Render::MeshCache::MeshResult mr; // [esp+40h] [ebp-8h] BYREF
  Scaleform::Render::Primitive::MeshEntry *convertMeshes; // [esp+44h] [ebp-4h]

  v2 = &this->pCache->Scaleform::Render::MeshCacheConfig;
  GetParams = v2->GetParams;
  v4 = 0;
  totalVerticesSize = 0;
  totalIndexCount = 0;
  pprevMesh = 0;
  v5 = 0;
  largeTailMesh = 0;
  meshTooBigFail = 0;
  tailMeshType = DP_Batch;
  v6 = (int)GetParams(v2);
  pBatchVFormat = this->pBatchVFormat;
  params = (const Scaleform::Render::MeshCacheParams *)v6;
  instancingThreshold = *(_DWORD *)(v6 + 28);
  if ( pBatchVFormat )
    batchVertexSize = pBatchVFormat->Size;
  else
    batchVertexSize = 0;
  pConvert = this->pConvert;
  v9 = pConvert->MeshIndex;
  Data = pConvert->pPrimitive->Meshes.Data.Data;
  MeshCount = pConvert->MeshCount;
  instancingSupported = this->pInstancedVFormat != 0;
  v12 = &Data[v9];
  convertMeshes = v12;
  originalConvertMeshCount = MeshCount;
  meshIndex = 0;
  if ( !MeshCount )
    goto LABEL_35;
  p_pObject = &v12->pMesh.pObject;
  while ( 1 )
  {
    v13 = *p_pObject;
    if ( *p_pObject != pprevMesh )
    {
      if ( instancingSupported && v5 >= instancingThreshold )
        goto LABEL_35;
      v5 = 1;
      goto LABEL_15;
    }
    if ( !instancingSupported )
    {
      ++v5;
LABEL_15:
      tailRepeatCount = v5;
      goto LABEL_16;
    }
    MaxBatchInstances = params->MaxBatchInstances;
    if ( v5 == MaxBatchInstances )
      goto LABEL_35;
    tailRepeatCount = ++v5;
    if ( v5 >= MaxBatchInstances )
    {
      ++meshIndex;
      goto LABEL_35;
    }
LABEL_16:
    if ( !v13->IndexCount )
    {
      Scaleform::Render::MeshCache::GenerateMesh(
        this->pCache,
        &mr,
        v13,
        this->pSourceVFormat,
        this->pSingleVFormat,
        pBatchVFormat,
        0);
      if ( mr.Value > Success_LargeMesh && mr.Value != Fail_LargeMesh_NeedCache )
      {
        if ( mr.Value == Fail_LargeMesh_TooBig )
        {
          meshTooBigFail = 1;
LABEL_22:
          tailMeshType = DP_Failed;
          goto LABEL_23;
        }
        if ( mr.Value != Fail_LargeMesh_ThisFrame )
          goto LABEL_22;
      }
    }
LABEL_23:
    if ( v13->LargeMesh || tailMeshType == DP_Failed || (pBatchVFormat = this->pBatchVFormat) == 0 )
    {
      ++meshIndex;
      instancingThreshold = 1;
      largeTailMesh = 1;
      goto LABEL_35;
    }
    v15 = v13->IndexCount + v4;
    if ( v15 > params->MaxIndicesInBatch )
      goto LABEL_32;
    v16 = totalVerticesSize + batchVertexSize * v13->VertexCount;
    if ( v16 > params->MaxVerticesSizeInBatch )
      goto LABEL_32;
    if ( meshIndex >= params->MaxBatchInstances )
      break;
    p_pObject += 2;
    v17 = meshIndex + 1 < originalConvertMeshCount;
    v4 = v15;
    ++meshIndex;
    v5 = tailRepeatCount;
    totalIndexCount = v15;
    totalVerticesSize = v16;
    pprevMesh = v13;
    if ( !v17 )
      goto LABEL_35;
  }
  v5 = tailRepeatCount;
LABEL_32:
  if ( v13 == pprevMesh )
    --v5;
LABEL_35:
  v18 = meshIndex;
  if ( instancingSupported )
  {
    if ( meshIndex < this->pConvert->MeshCount )
    {
      p_pMesh = &convertMeshes[meshIndex].pMesh;
      do
      {
        if ( p_pMesh->pObject != convertMeshes[meshIndex - 1].pMesh.pObject )
          break;
        if ( v5 >= params->MaxBatchInstances )
          break;
        ++v18;
        ++v5;
        p_pMesh += 2;
      }
      while ( v18 < this->pConvert->MeshCount );
    }
  }
  else if ( v5 > 1 )
  {
    v5 = 0;
  }
  if ( v5 >= instancingThreshold || v18 == v5 && v5 != 1 )
    meshIndex = v18;
  else
    v5 = 0;
  v20 = meshIndex - v5;
  if ( meshIndex != v5 )
  {
    v21 = this->pConvert;
    if ( meshIndex != v21->MeshCount || v5 )
    {
      v24 = Scaleform::Render::PrimitiveBatch::Create(v21->pPrimitive, DP_Batch, v21->MeshIndex, meshIndex - v5);
      v25 = this->pConvert;
      v24->pNext = v25->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$C512BB809886916B7F681A9EBDF58E11::pPrev;
      v24->pPrev = v25->pPrev;
      v25->pPrev->pNext = v24;
      v25->pPrev = v24;
      this->pConvert->MeshIndex += v20;
      this->pConvert->MeshCount -= v20;
      pEmitBuffer = this->pEmitBuffer;
      if ( this->pItem == pEmitBuffer->pItem && pEmitBuffer->pDraw == this->pConvert )
        pEmitBuffer->pDraw = v24;
      if ( this->pPrepare == this->pConvert )
        this->pPrepare = v24;
    }
    else
    {
      v21->Type = DP_Batch;
      v22 = this->pConvert;
      if ( this->pPrepareTail != v22 )
        Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
          this,
          v22->pPrev,
          v22,
          v22->pPrev,
          v22,
          &totalVerticesSize,
          &totalIndexCount);
      v23 = this->pConvert;
      if ( v23->pNext != (Scaleform::Render::PrimitiveBatch *)&this->pPrimitive->Batches )
        Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
          this,
          v23,
          v23->pNext,
          v23->pNext,
          v23,
          &totalVerticesSize,
          &totalIndexCount);
      v24 = this->pConvert;
    }
    if ( v24->MeshCount == 1 )
    {
      v24->Type = DP_Single;
      v24->pFormat = this->pSingleVFormat;
    }
    else
    {
      v24->pFormat = this->pBatchVFormat;
    }
    this->pPrepareTail = this->pConvert;
  }
  if ( v5 )
  {
    if ( v5 <= 1 || tailMeshType == DP_Failed )
    {
      if ( !meshTooBigFail )
        tailMeshType = DP_Single;
      v27 = Scaleform::Render::PrimitiveBatch::Create(
              this->pConvert->pPrimitive,
              tailMeshType,
              this->pConvert->MeshIndex,
              v5);
    }
    else
    {
      tailMeshType = DP_Instanced;
      v27 = Scaleform::Render::PrimitiveBatch::Create(
              this->pConvert->pPrimitive,
              DP_Instanced,
              this->pConvert->MeshIndex,
              v5);
    }
    v28 = v27;
    v27->LargeMesh = largeTailMesh;
    if ( tailMeshType == DP_Instanced )
    {
      v27->pFormat = this->pInstancedVFormat;
    }
    else if ( tailMeshType == DP_Single || tailMeshType == DP_Failed )
    {
      v27->pFormat = this->pSingleVFormat;
    }
    v29 = this->pConvert;
    v28->pNext = v29->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$C512BB809886916B7F681A9EBDF58E11::pPrev;
    v28->pPrev = v29->pPrev;
    v29->pPrev->pNext = v28;
    v29->pPrev = v28;
    this->pConvert->MeshIndex += v5;
    this->pConvert->MeshCount -= v5;
    v30 = this->pEmitBuffer;
    if ( this->pItem == v30->pItem && v30->pDraw == this->pConvert )
      v30->pDraw = v28;
    v31 = this->pConvert;
    if ( this->pPrepare == v31 )
      this->pPrepare = v28;
    if ( !v31->MeshCount )
    {
      Scaleform::Render::PrimitiveBatch::RemoveAndFree(v31);
      this->pConvert = v28;
    }
    this->pPrepareTail = v28;
  }
  if ( meshIndex >= originalConvertMeshCount )
    this->Converting = 0;
}
