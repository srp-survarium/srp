void __thiscall btCollisionDispatcher::clearManifold(btCollisionDispatcher *this, btPersistentManifold *manifold)
{
  int v2; // edi
  bool (__cdecl *v3)(void *); // ecx
  void **p_m_userPersistentData; // esi

  v2 = 0;
  if ( manifold->m_cachedPoints <= 0 )
  {
    manifold->m_cachedPoints = 0;
  }
  else
  {
    v3 = gContactDestroyedCallback;
    p_m_userPersistentData = &manifold->m_pointCache[0].m_userPersistentData;
    do
    {
      if ( *p_m_userPersistentData )
      {
        if ( v3 )
        {
          v3(*p_m_userPersistentData);
          v3 = gContactDestroyedCallback;
          *p_m_userPersistentData = 0;
        }
      }
      ++v2;
      p_m_userPersistentData += 72;
    }
    while ( v2 < manifold->m_cachedPoints );
    manifold->m_cachedPoints = 0;
  }
}
