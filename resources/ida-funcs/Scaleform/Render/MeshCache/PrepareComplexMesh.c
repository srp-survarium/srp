char __thiscall Scaleform::Render::MeshCache::PrepareComplexMesh(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::ComplexMesh *mesh,
        bool waitForCache)
{
  Scaleform::Render::MeshProvider *pObject; // ecx
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // esi
  unsigned int MGFlags; // [esp-4h] [ebp-30h]
  _DWORD v8[4]; // [esp+8h] [ebp-24h] BYREF
  bool v9; // [esp+18h] [ebp-14h]
  int v10; // [esp+20h] [ebp-Ch]

  if ( mesh && !mesh->AllocTooBig )
  {
    if ( mesh->pCacheMeshItem )
      goto LABEL_7;
    v8[3] = mesh->pFillManager->pHAL;
    MGFlags = mesh->MGFlags;
    v9 = waitForCache;
    pObject = mesh->pProvider.pObject;
    v8[0] = &Scaleform::Render::ComplexMeshVertexOutput::`vftable';
    v8[1] = mesh;
    v8[2] = this;
    v10 = 4;
    pObject->GetData(pObject, mesh, (Scaleform::Render::VertexOutput *)v8, MGFlags);
    if ( !v10 )
      return 0;
    if ( v10 == 3 )
    {
LABEL_7:
      pCacheMeshItem = mesh->pCacheMeshItem;
      if ( pCacheMeshItem )
        Scaleform::Render::MeshCache::MoveToCacheListFront(this, MCL_InFlight, pCacheMeshItem);
    }
  }
  return 1;
}
