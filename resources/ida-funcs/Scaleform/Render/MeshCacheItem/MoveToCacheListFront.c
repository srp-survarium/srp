void __thiscall Scaleform::Render::MeshCacheItem::MoveToCacheListFront(
        Scaleform::Render::MeshCacheItem *this,
        Scaleform::Render::MeshCacheListType list)
{
  Scaleform::Render::MeshCacheListSet::RemoveNode(this->pCacheList, this);
  Scaleform::Render::MeshCacheListSet::PushFront(this->pCacheList, list, this);
}
