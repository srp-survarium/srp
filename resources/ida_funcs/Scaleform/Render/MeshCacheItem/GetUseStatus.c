Scaleform::Render::MeshUseStatus __thiscall Scaleform::Render::MeshCacheItem::GetUseStatus(
        Scaleform::Render::MeshCacheItem *this)
{
  return this->pCacheList->pCache->GetItemUseStatus(this->pCacheList->pCache, this);
}
