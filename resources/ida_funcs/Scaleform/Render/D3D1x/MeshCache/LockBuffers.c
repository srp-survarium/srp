int __thiscall Scaleform::Render::D3D1x::MeshCache::LockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  int result; // eax
  Scaleform::Render::RQCacheInterface *pRQCaches; // ecx

  result = 1;
  this->Locked = 1;
  this->VBSizeEvictedInLock = 0;
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
    pRQCaches->LockFlags |= 1u;
  return result;
}
