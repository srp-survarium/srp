void __thiscall Scaleform::Render::D3D1x::MeshCache::GetStats(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCache::Stats *stats)
{
  int i; // eax
  Scaleform::AllocAddr *v3; // eax
  _DWORD v4[14]; // [esp+0h] [ebp-3Ch] BYREF
  Scaleform::Render::D3D1x::MeshCache *v5; // [esp+38h] [ebp-4h]

  v5 = this;
  for ( i = 0; i < 7; ++i )
  {
    v4[i + 7] = 0;
    v4[i] = 0;
  }
  qmemcpy(stats, v4, sizeof(Scaleform::Render::MeshCache::Stats));
  stats->TotalSize[5] = this->VertexBuffers.TotalSize;
  stats->UsedSize[5] = 16 * Scaleform::AllocAddr::GetFreeSize(&this->VertexBuffers.Allocator);
  v3 = (Scaleform::AllocAddr *)v5;
  stats->TotalSize[6] = v5->IndexBuffers.TotalSize;
  stats->UsedSize[6] = 16 * Scaleform::AllocAddr::GetFreeSize(v3 + 29);
}
