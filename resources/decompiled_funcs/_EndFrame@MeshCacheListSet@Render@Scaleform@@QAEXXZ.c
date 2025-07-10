void __thiscall Scaleform::Render::MeshCacheListSet::EndFrame(Scaleform::Render::MeshCacheListSet *this)
{
  Scaleform::Render::MeshCacheListSet::PushListToFront(this, MCL_LRUTail, MCL_PrevFrame);
  Scaleform::Render::MeshCacheListSet::PushListToFront(this, MCL_PrevFrame, MCL_ThisFrame);
}
