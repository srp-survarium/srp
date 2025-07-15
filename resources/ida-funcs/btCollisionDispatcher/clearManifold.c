void __thiscall btCollisionDispatcher::clearManifold(btCollisionDispatcher *this, btPersistentManifold *manifold)
{
  int v2; // ebx
  btManifoldPoint *m_pointCache; // esi

  v2 = 0;
  if ( manifold->m_cachedPoints > 0 )
  {
    m_pointCache = manifold->m_pointCache;
    do
    {
      if ( m_pointCache->m_userPersistentData )
        btPersistentManifold::clearUserCache(m_pointCache);
      ++v2;
      ++m_pointCache;
    }
    while ( v2 < manifold->m_cachedPoints );
  }
  manifold->m_cachedPoints = 0;
}
