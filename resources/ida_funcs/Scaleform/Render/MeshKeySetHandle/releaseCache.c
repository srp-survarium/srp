void __thiscall Scaleform::Render::MeshKeySetHandle::releaseCache(Scaleform::Render::MeshKeySetHandle *this)
{
  Scaleform::Render::MeshKeyManager *v2; // eax
  Scaleform::RefCountVImpl *v3; // esi

  v2 = (Scaleform::Render::MeshKeyManager *)InterlockedExchange((volatile LONG *)this, 0);
  v3 = (Scaleform::RefCountVImpl *)v2;
  if ( v2 )
  {
    Scaleform::Render::MeshKeyManager::providerLost(v2, this);
    Scaleform::RefCountImpl::Release(v3);
  }
}
