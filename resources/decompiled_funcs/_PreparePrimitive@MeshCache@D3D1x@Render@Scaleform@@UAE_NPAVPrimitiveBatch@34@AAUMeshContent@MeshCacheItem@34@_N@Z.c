char __thiscall Scaleform::Render::D3D1x::MeshCache::PreparePrimitive(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::PrimitiveBatch *pbatch,
        Scaleform::Render::MeshCacheItem::MeshContent *mc,
        BOOL waitForCache)
{
  bool v4; // zf
  Scaleform::Render::Primitive *pPrimitive; // ecx
  Scaleform::Render::MeshCacheItem **p_RefCount; // eax
  const Scaleform::Render::VertexFormat *pFormat; // eax
  Scaleform::Render::MeshCache::AllocResult (__thiscall *AllocCacheItem)(struct Scaleform::Render::D3D1x::MeshCache *, Scaleform::Render::MeshCacheItem **, unsigned __int8 **, unsigned __int16 **, Scaleform::Render::MeshCacheItem::MeshType, Scaleform::Render::MeshCacheItem::MeshBaseContent *, unsigned int, unsigned int, unsigned int, bool, const Scaleform::Render::VertexFormat *); // edx
  int v11; // eax
  int v12; // eax
  const Scaleform::Render::VertexFormat *v13; // edx
  const Scaleform::Render::VertexFormat *v14; // ecx
  unsigned int v15; // eax
  int v16; // ebx
  _DWORD *v17; // esi
  void *convertArgArray[1]; // [esp+28h] [ebp-134h] BYREF
  unsigned __int16 *pindexDataStart; // [esp+2Ch] [ebp-130h] BYREF
  unsigned int i; // [esp+30h] [ebp-12Ch] BYREF
  unsigned __int8 *pvertexDataStart; // [esp+34h] [ebp-128h] BYREF
  unsigned __int8 *pstagingBuffer; // [esp+38h] [ebp-124h]
  Scaleform::Render::MeshCacheItem *batchData; // [esp+3Ch] [ebp-120h] BYREF
  const Scaleform::Render::VertexFormat *pdvf; // [esp+40h] [ebp-11Ch]
  const Scaleform::Render::VertexFormat *pvf; // [esp+44h] [ebp-118h]
  unsigned int totalVertexCount; // [esp+48h] [ebp-114h] BYREF
  unsigned int destVertexSize; // [esp+4Ch] [ebp-110h]
  unsigned int totalIndexCount; // [esp+50h] [ebp-10Ch] BYREF
  Scaleform::Render::MeshCache::StagingBufferPrep meshPrep; // [esp+54h] [ebp-108h] BYREF

  v4 = mc->Meshes.Size == 0;
  pPrimitive = pbatch->pPrimitive;
  convertArgArray[0] = pPrimitive;
  if ( v4 || !LOBYTE((*mc->Meshes.pData)[1].pProvider.pObject) )
  {
    Scaleform::Render::PrimitiveBatch::CalcMeshSizes(pbatch, &totalVertexCount, &totalIndexCount);
    pFormat = pbatch->pFormat;
    AllocCacheItem = this->AllocCacheItem;
    batchData = 0;
    destVertexSize = pFormat->Size;
    v11 = AllocCacheItem(
            this,
            &batchData,
            &pvertexDataStart,
            &pindexDataStart,
            Mesh_Regular,
            mc,
            totalVertexCount * destVertexSize,
            totalVertexCount,
            totalIndexCount,
            waitForCache,
            0);
    if ( v11 == 3 )
    {
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&pbatch->MeshNode, batchData);
      Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(
        &meshPrep,
        this,
        mc,
        *(const Scaleform::Render::VertexFormat **)(*((_DWORD *)convertArgArray[0] + 4) + 28),
        0,
        0);
      v12 = *((_DWORD *)convertArgArray[0] + 4);
      v13 = pbatch->pFormat;
      pstagingBuffer = this->StagingBuffer.pBuffer;
      v14 = *(const Scaleform::Render::VertexFormat **)(v12 + 28);
      v15 = 0;
      v16 = 0;
      pvf = v14;
      pdvf = v13;
      for ( i = 0; v15 < mc->Meshes.Size; i = v15 )
      {
        v17 = *(Scaleform::Render::MeshBase **)((char *)mc->Meshes.pData + v15 * mc->Meshes.StrideSize);
        convertArgArray[0] = &i;
        Scaleform::Render::ConvertVertices_Buffered(
          pvf,
          &pstagingBuffer[v17[6]],
          pdvf,
          pvertexDataStart,
          v17[9],
          convertArgArray);
        Scaleform::Render::ConvertIndices((__m128i *)pindexDataStart, (__m128i *)&pstagingBuffer[v17[7]], v17[10], v16);
        pvertexDataStart += destVertexSize * v17[9];
        v15 = i + 1;
        pindexDataStart += v17[10];
        v16 += v17[9];
      }
      Scaleform::Render::MeshCache::StagingBufferPrep::~StagingBufferPrep(&meshPrep);
      return 1;
    }
    else
    {
      return v11 != 0;
    }
  }
  else
  {
    Scaleform::Render::MeshCache::GenerateMesh(
      this,
      (Scaleform::Render::MeshCache::MeshResult *)convertArgArray,
      (Scaleform::Render::Mesh *)*mc->Meshes.pData,
      pPrimitive->pFill.pObject->Data.pFormat,
      pbatch->pFormat,
      0,
      waitForCache);
    if ( (int)convertArgArray[0] <= 1 )
    {
      if ( (*mc->Meshes.pData)[1].Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable <= (Scaleform::Render::MeshBase_vtbl *)2 )
        p_RefCount = (Scaleform::Render::MeshCacheItem **)&(*mc->Meshes.pData)[1].RefCount;
      else
        p_RefCount = (Scaleform::Render::MeshCacheItem **)(*mc->Meshes.pData)[1].RefCount;
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&pbatch->MeshNode, *p_RefCount);
    }
    return convertArgArray[0] != (void *)3;
  }
}
