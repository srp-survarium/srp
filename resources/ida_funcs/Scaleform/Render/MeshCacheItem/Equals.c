char __thiscall Scaleform::Render::MeshCacheItem::Equals(
        Scaleform::Render::MeshCacheItem *this,
        const Scaleform::Render::StrideArray<Scaleform::Render::MeshBase *> *meshes)
{
  unsigned int MeshCount; // esi
  unsigned int v4; // eax
  Scaleform::Render::MeshBase **pData; // edx
  Scaleform::Render::MeshBase **i; // ecx

  MeshCount = this->MeshCount;
  if ( MeshCount != meshes->Size )
    return 0;
  v4 = 0;
  if ( !MeshCount )
    return 1;
  pData = meshes->pData;
  for ( i = this->pMeshes; *i == *pData; ++i )
  {
    ++v4;
    pData = (Scaleform::Render::MeshBase **)((char *)pData + meshes->StrideSize);
    if ( v4 >= MeshCount )
      return 1;
  }
  return 0;
}
