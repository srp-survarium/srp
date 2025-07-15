void __thiscall Scaleform::Render::MeshCacheListSet::RemoveNode(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheItem *p)
{
  p->pPrev->pNext = p->pNext;
  p->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$91FE2188799D963DDDCE23AE0AD4A8E3::pPrev = p->pPrev;
  this->Slots[p->ListType].Size -= p->AllocSize;
}
