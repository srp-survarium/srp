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
  unsigned int MeshIndex; // edi
  Scaleform::Render::Primitive::MeshEntry *Data; // ecx
  unsigned int MeshCount; // eax
  Scaleform::Render::Primitive::MeshEntry *v12; // ecx
  Scaleform::Render::Mesh *v13; // edi
  unsigned int v14; // eax
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
  int v32; // [esp+0h] [ebp-48h]
  int v33; // [esp+4h] [ebp-44h]
  char v34; // [esp+8h] [ebp-40h]
  bool v35; // [esp+11h] [ebp-37h]
  char v36; // [esp+12h] [ebp-36h]
  char v37; // [esp+13h] [ebp-35h]
  unsigned int v38; // [esp+14h] [ebp-34h]
  Scaleform::Render::PrimitiveBatch::BatchType type; // [esp+18h] [ebp-30h]
  unsigned int v40; // [esp+1Ch] [ebp-2Ch]
  _DWORD *v41; // [esp+20h] [ebp-28h]
  unsigned int knownVerticesSize; // [esp+24h] [ebp-24h] BYREF
  Scaleform::Render::Mesh **p_pObject; // [esp+28h] [ebp-20h]
  Scaleform::Render::Mesh *v44; // [esp+2Ch] [ebp-1Ch]
  unsigned int v45; // [esp+30h] [ebp-18h]
  unsigned int knownIndexCount; // [esp+34h] [ebp-14h] BYREF
  unsigned int Size; // [esp+38h] [ebp-10h]
  unsigned int v48; // [esp+3Ch] [ebp-Ch]
  Scaleform::Render::MeshCache::MeshResult v49; // [esp+40h] [ebp-8h] BYREF
  Scaleform::Render::Primitive::MeshEntry *v50; // [esp+44h] [ebp-4h]

  v2 = &this->pCache->Scaleform::Render::MeshCacheConfig;
  GetParams = v2->GetParams;
  v4 = 0;
  knownVerticesSize = 0;
  knownIndexCount = 0;
  v44 = 0;
  v5 = 0;
  v37 = 0;
  v36 = 0;
  type = DP_Batch;
  v6 = (int)GetParams(v2);
  pBatchVFormat = this->pBatchVFormat;
  v41 = (_DWORD *)v6;
  v45 = *(_DWORD *)(v6 + 28);
  if ( pBatchVFormat )
    Size = pBatchVFormat->Size;
  else
    Size = 0;
  pConvert = this->pConvert;
  MeshIndex = pConvert->MeshIndex;
  Data = pConvert->pPrimitive->Meshes.Data.Data;
  MeshCount = pConvert->MeshCount;
  v35 = this->pInstancedVFormat != 0;
  v12 = &Data[MeshIndex];
  v50 = v12;
  v48 = MeshCount;
  v38 = 0;
  if ( !MeshCount )
    goto LABEL_35;
  p_pObject = &v12->pMesh.pObject;
  while ( 1 )
  {
    v13 = *p_pObject;
    if ( *p_pObject != v44 )
    {
      if ( v35 && v5 >= v45 )
        goto LABEL_35;
      v5 = 1;
      goto LABEL_15;
    }
    if ( !v35 )
    {
      ++v5;
LABEL_15:
      v40 = v5;
      goto LABEL_16;
    }
    v14 = v41[6];
    if ( v5 == v14 )
      goto LABEL_35;
    v40 = ++v5;
    if ( v5 >= v14 )
    {
      ++v38;
      goto LABEL_35;
    }
LABEL_16:
    if ( !v13->IndexCount )
    {
      Scaleform::Render::MeshCache::GenerateMesh(
        this->pCache,
        &v49,
        v13,
        this->pSourceVFormat,
        this->pSingleVFormat,
        pBatchVFormat,
        0,
        v32,
        v33,
        v34);
      if ( v49.Value > Success_LargeMesh && v49.Value != Fail_LargeMesh_NeedCache )
      {
        if ( v49.Value == Fail_LargeMesh_TooBig )
        {
          v36 = 1;
LABEL_22:
          type = DP_Failed;
          goto LABEL_23;
        }
        if ( v49.Value != Fail_LargeMesh_ThisFrame )
          goto LABEL_22;
      }
    }
LABEL_23:
    if ( v13->LargeMesh || type == DP_Failed || (pBatchVFormat = this->pBatchVFormat) == 0 )
    {
      ++v38;
      v45 = 1;
      v37 = 1;
      goto LABEL_35;
    }
    v15 = v13->IndexCount + v4;
    if ( v15 > v41[10] )
      goto LABEL_32;
    v16 = knownVerticesSize + Size * v13->VertexCount;
    if ( v16 > v41[9] )
      goto LABEL_32;
    if ( v38 >= v41[6] )
      break;
    p_pObject += 2;
    v17 = v38 + 1 < v48;
    v4 = v15;
    ++v38;
    v5 = v40;
    knownIndexCount = v15;
    knownVerticesSize = v16;
    v44 = v13;
    if ( !v17 )
      goto LABEL_35;
  }
  v5 = v40;
LABEL_32:
  if ( v13 == v44 )
    --v5;
LABEL_35:
  v18 = v38;
  if ( v35 )
  {
    if ( v38 < this->pConvert->MeshCount )
    {
      p_pMesh = &v50[v38].pMesh;
      do
      {
        if ( p_pMesh->pObject != v50[v38 - 1].pMesh.pObject )
          break;
        if ( v5 >= v41[6] )
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
  if ( v5 >= v45 || v18 == v5 && v5 != 1 )
    v38 = v18;
  else
    v5 = 0;
  v20 = v38 - v5;
  if ( v38 != v5 )
  {
    v21 = this->pConvert;
    if ( v38 != v21->MeshCount || v5 )
    {
      v24 = Scaleform::Render::PrimitiveBatch::Create(v21->pPrimitive, DP_Batch, v21->MeshIndex, v38 - v5);
      v25 = this->pConvert;
      v24->pNext = v25->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$B6E31D4B7F8069B2127C6EE45BDFC5DE::pPrev;
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
          &knownVerticesSize,
          &knownIndexCount);
      v23 = this->pConvert;
      if ( v23->pNext != (Scaleform::Render::PrimitiveBatch *)&this->pPrimitive->Batches )
        Scaleform::Render::PrimitivePrepareBuffer::attemptMergeBatches(
          this,
          v23,
          v23->pNext,
          v23->pNext,
          v23,
          &knownVerticesSize,
          &knownIndexCount);
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
    if ( v5 <= 1 || type == DP_Failed )
    {
      if ( !v36 )
        type = DP_Single;
      v27 = Scaleform::Render::PrimitiveBatch::Create(this->pConvert->pPrimitive, type, this->pConvert->MeshIndex, v5);
    }
    else
    {
      type = DP_Instanced;
      v27 = Scaleform::Render::PrimitiveBatch::Create(
              this->pConvert->pPrimitive,
              DP_Instanced,
              this->pConvert->MeshIndex,
              v5);
    }
    v28 = v27;
    v27->LargeMesh = v37;
    if ( type == DP_Instanced )
    {
      v27->pFormat = this->pInstancedVFormat;
    }
    else if ( type == DP_Single || type == DP_Failed )
    {
      v27->pFormat = this->pSingleVFormat;
    }
    v29 = this->pConvert;
    v28->pNext = v29->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$B6E31D4B7F8069B2127C6EE45BDFC5DE::pPrev;
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
  if ( v38 >= v48 )
    this->Converting = 0;
}
