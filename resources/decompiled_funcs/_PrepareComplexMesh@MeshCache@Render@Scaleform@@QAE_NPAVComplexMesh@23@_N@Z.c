char __thiscall Scaleform::Render::MeshCache::PrepareComplexMesh(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::ComplexMesh *mesh,
        bool waitForCache)
{
  Scaleform::Render::MeshProvider *pObject; // ecx
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // esi
  unsigned int MGFlags; // [esp-4h] [ebp-30h]
  Scaleform::Render::ComplexMeshVertexOutput out; // [esp+8h] [ebp-24h] BYREF

  if ( mesh && !mesh->AllocTooBig )
  {
    if ( mesh->pCacheMeshItem )
      goto LABEL_7;
    out.pHAL = mesh->pFillManager->pHAL;
    MGFlags = mesh->MGFlags;
    out.WaitForCache = waitForCache;
    pObject = mesh->pProvider.pObject;
    out.__vftable = (Scaleform::Render::ComplexMeshVertexOutput_vtbl *)&Scaleform::Render::ComplexMeshVertexOutput::`vftable';
    out.pMesh = mesh;
    out.pCache = this;
    out.AllocState = Alloc_StateError;
    pObject->GetData(pObject, mesh, &out, MGFlags);
    if ( out.AllocState == Alloc_Fail )
      return 0;
    if ( out.AllocState == Alloc_Success )
    {
LABEL_7:
      pCacheMeshItem = mesh->pCacheMeshItem;
      if ( pCacheMeshItem )
        Scaleform::Render::MeshCache::MoveToCacheListFront(this, MCL_InFlight, pCacheMeshItem);
    }
  }
  return 1;
}
