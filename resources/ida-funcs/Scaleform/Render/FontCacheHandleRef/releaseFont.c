void __thiscall Scaleform::Render::FontCacheHandleRef::releaseFont(Scaleform::Render::FontCacheHandleRef *this)
{
  Scaleform::Render::FontCacheHandleManager *v2; // eax
  Scaleform::RefCountVImpl *v3; // esi

  v2 = (Scaleform::Render::FontCacheHandleManager *)InterlockedExchange((volatile LONG *)this, 0);
  v3 = (Scaleform::RefCountVImpl *)v2;
  if ( v2 )
  {
    Scaleform::Render::FontCacheHandleManager::fontLost(v2, this);
    Scaleform::RefCountImpl::Release(v3);
  }
}
