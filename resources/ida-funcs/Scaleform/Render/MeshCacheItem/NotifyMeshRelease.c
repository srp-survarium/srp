void __thiscall Scaleform::Render::MeshCacheItem::NotifyMeshRelease(
        Scaleform::Render::MeshCacheItem *this,
        Scaleform::Render::MeshBase *pmesh)
{
  this->pCacheList->pCache->Evict(this->pCacheList->pCache, this, 0, pmesh);
}
