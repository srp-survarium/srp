void __thiscall Scaleform::Render::D3D1x::MeshCache::GetStats(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCache::Stats *stats)
{
  _DWORD v3[14]; // [esp+10h] [ebp-38h] BYREF

  memset(v3, 0, sizeof(v3));
  qmemcpy(stats, v3, sizeof(Scaleform::Render::MeshCache::Stats));
  stats->TotalSize[5] = this->VertexBuffers.TotalSize;
  stats->UsedSize[5] = 16 * Scaleform::AllocAddr::GetFreeSize(&this->VertexBuffers.Allocator);
  stats->TotalSize[6] = this->IndexBuffers.TotalSize;
  stats->UsedSize[6] = 16 * Scaleform::AllocAddr::GetFreeSize(&this->IndexBuffers.Allocator);
}
