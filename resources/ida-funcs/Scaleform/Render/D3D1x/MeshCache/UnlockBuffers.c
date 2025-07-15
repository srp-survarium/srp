void __thiscall Scaleform::Render::D3D1x::MeshCache::UnlockBuffers(Scaleform::Render::D3D1x::MeshCache *this)
{
  ID3D11DeviceContext *pObject; // ebx
  Scaleform::Render::D3D1x::MeshBuffer *i; // edi
  Scaleform::Render::RQCacheInterface *pRQCaches; // esi

  pObject = this->pDeviceContext.pObject;
  for ( i = this->LockedBuffers.pFirst; i; i = i->pNextLock )
    i->Unlock(i, pObject);
  this->LockedBuffers.pFirst = 0;
  this->Locked = 0;
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
    pRQCaches->LockFlags &= ~1u;
}
