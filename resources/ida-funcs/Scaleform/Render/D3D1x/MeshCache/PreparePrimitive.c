bool __thiscall Scaleform::Render::D3D1x::MeshCache::PreparePrimitive(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::PrimitiveBatch *pbatch,
        Scaleform::Render::MeshCacheItem::MeshContent *mc,
        BOOL waitForCache)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v5; // eax
  Scaleform::Render::Primitive *pPrimitive; // ebx
  Scaleform::Render::MeshCacheItem **p_RefCount; // eax
  bool v8; // bl
  const Scaleform::Render::VertexFormat *pFormat; // eax
  int v11; // edx
  const Scaleform::Render::VertexFormat *v12; // eax
  int v13; // ebx
  _DWORD *v14; // esi
  int v15; // [esp+1Ch] [ebp-150h]
  int v16; // [esp+20h] [ebp-14Ch]
  char v17; // [esp+24h] [ebp-148h]
  Scaleform::Render::MeshCache::MeshResult result; // [esp+28h] [ebp-144h] BYREF
  unsigned int i; // [esp+2Ch] [ebp-140h] BYREF
  unsigned __int16 *v20; // [esp+30h] [ebp-13Ch] BYREF
  void *pdest; // [esp+34h] [ebp-138h] BYREF
  void *pargumentData; // [esp+38h] [ebp-134h] BYREF
  unsigned int ptotalVertices; // [esp+3Ch] [ebp-130h] BYREF
  Scaleform::Render::MeshCacheItem *p; // [esp+40h] [ebp-12Ch] BYREF
  unsigned int ptotalIndices; // [esp+44h] [ebp-128h] BYREF
  unsigned int Size; // [esp+48h] [ebp-124h]
  const Scaleform::Render::VertexFormat *destFormat; // [esp+4Ch] [ebp-120h]
  const Scaleform::Render::VertexFormat *sourceFormat; // [esp+50h] [ebp-11Ch]
  Scaleform::AmpFunctionTimer v29; // [esp+54h] [ebp-118h] BYREF
  Scaleform::Render::MeshCache::StagingBufferPrep v30; // [esp+64h] [ebp-108h] BYREF

  result.Value = (Scaleform::Render::MeshCache::MeshResult::ResultType)this;
  Instance = Scaleform::AmpServer::GetInstance();
  v5 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v29,
    v5,
    "Scaleform::Render::D3D1x::MeshCache::PreparePrimitive",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  pPrimitive = pbatch->pPrimitive;
  if ( mc->Meshes.Size && LOBYTE((*mc->Meshes.pData)[1].pProvider.pObject) )
  {
    Scaleform::Render::MeshCache::GenerateMesh(
      (Scaleform::Render::MeshCache *)result.Value,
      &result,
      (Scaleform::Render::Mesh *)*mc->Meshes.pData,
      pPrimitive->pFill.pObject->Data.pFormat,
      pbatch->pFormat,
      0,
      waitForCache,
      v15,
      v16,
      v17);
    if ( result.Value <= Success_LargeMesh )
    {
      if ( (*mc->Meshes.pData)[1].Scaleform::RefCountBase<Scaleform::Render::MeshBase,70>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,70>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable <= (Scaleform::Render::MeshBase_vtbl *)2 )
        p_RefCount = (Scaleform::Render::MeshCacheItem **)&(*mc->Meshes.pData)[1].RefCount;
      else
        p_RefCount = (Scaleform::Render::MeshCacheItem **)(*mc->Meshes.pData)[1].RefCount;
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&pbatch->MeshNode, *p_RefCount);
    }
    v8 = result.Value != Fail_LargeMesh_NeedCache;
    Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v29);
    return v8;
  }
  else
  {
    Scaleform::Render::PrimitiveBatch::CalcMeshSizes(pbatch, &ptotalVertices, &ptotalIndices);
    pFormat = pbatch->pFormat;
    p = 0;
    v11 = *(_DWORD *)result.Value;
    Size = pFormat->Size;
    pargumentData = (void *)(*(int (__thiscall **)(Scaleform::Render::MeshCache::MeshResult::ResultType, Scaleform::Render::MeshCacheItem **, void **, unsigned __int16 **, _DWORD, Scaleform::Render::MeshCacheItem::MeshContent *, unsigned int, unsigned int, unsigned int, BOOL, _DWORD))(v11 + 48))(
                              result.Value,
                              &p,
                              &pdest,
                              &v20,
                              0,
                              mc,
                              ptotalVertices * Size,
                              ptotalVertices,
                              ptotalIndices,
                              waitForCache,
                              0);
    if ( pargumentData == (void *)3 )
    {
      Scaleform::Render::MeshCacheItemUseNode::SetMeshItem(&pbatch->MeshNode, p);
      Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(
        &v30,
        (Scaleform::Render::MeshCache *)result.Value,
        mc,
        pPrimitive->pFill.pObject->Data.pFormat,
        0,
        0);
      result.Value = *(_DWORD *)(result.Value + 60);
      v12 = pPrimitive->pFill.pObject->Data.pFormat;
      v13 = 0;
      sourceFormat = v12;
      destFormat = pbatch->pFormat;
      for ( i = 0; i < mc->Meshes.Size; ++i )
      {
        v14 = *(Scaleform::Render::MeshBase **)((char *)mc->Meshes.pData + i * mc->Meshes.StrideSize);
        pargumentData = &i;
        Scaleform::Render::ConvertVertices_Buffered(
          sourceFormat,
          (unsigned __int8 *)(result.Value + v14[6]),
          destFormat,
          (unsigned __int8 *)pdest,
          v14[9],
          (const void **)&pargumentData);
        Scaleform::Render::ConvertIndices((__m128i *)v20, (__m128i *)(result.Value + v14[7]), v14[10], v13);
        pdest = (char *)pdest + Size * v14[9];
        v20 += v14[10];
        v13 += v14[9];
      }
      Scaleform::Render::MeshCache::StagingBufferPrep::~StagingBufferPrep(&v30);
      Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v29);
      return 1;
    }
    else
    {
      Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v29);
      return pargumentData != 0;
    }
  }
}
