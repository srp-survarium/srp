int __thiscall Scaleform::Render::D3D1x::MeshCache::LockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  int result; // eax
  Scaleform::Render::RQCacheInterface *pRQCaches; // ecx

  this->VBSizeEvictedInLock = 0;
  result = 1;
  this->Locked = 1;
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
    pRQCaches->LockFlags |= 1u;
  return result;
}
