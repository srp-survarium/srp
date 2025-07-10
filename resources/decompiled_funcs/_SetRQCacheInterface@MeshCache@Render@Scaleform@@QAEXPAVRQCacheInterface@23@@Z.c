void __thiscall Scaleform::Render::MeshCache::SetRQCacheInterface(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::RQCacheInterface *rqCaches)
{
  Scaleform::Render::RQCacheInterface *pRQCaches; // eax

  pRQCaches = this->pRQCaches;
  if ( pRQCaches != rqCaches )
  {
    if ( pRQCaches )
    {
      pRQCaches->LockFlags &= ~1u;
      this->pRQCaches->pCaches[0] = 0;
    }
    this->pRQCaches = rqCaches;
    if ( rqCaches )
    {
      rqCaches->pCaches[0] = this;
      if ( this->AreBuffersLocked(this) )
        this->pRQCaches->LockFlags |= 1u;
    }
  }
}
