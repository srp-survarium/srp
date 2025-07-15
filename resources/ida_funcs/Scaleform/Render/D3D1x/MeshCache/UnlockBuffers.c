void __thiscall Scaleform::Render::D3D1x::MeshCache::UnlockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshBuffer *pFirst; // esi
  ID3D11DeviceContext *i; // ebp
  Scaleform::Render::RQCacheInterface *pRQCaches; // edi

  pFirst = this->LockedBuffers.pFirst;
  for ( i = this->pDeviceContext.pObject; pFirst; pFirst = pFirst->pNextLock )
    pFirst->Unlock(pFirst, i);
  this->LockedBuffers.pFirst = 0;
  this->Locked = 0;
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
    pRQCaches->LockFlags &= ~1u;
}
