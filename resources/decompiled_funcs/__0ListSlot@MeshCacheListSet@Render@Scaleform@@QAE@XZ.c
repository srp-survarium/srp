void __thiscall Scaleform::Render::MeshCacheListSet::ListSlot::ListSlot(
        Scaleform::Render::MeshCacheListSet::ListSlot *this)
{
  this->Root.pPrev = (Scaleform::Render::MeshCacheItem *)this;
  this->Root.pNext = (Scaleform::Render::MeshCacheItem *)this;
  this->Size = 0;
}
