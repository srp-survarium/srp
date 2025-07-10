void __usercall btPersistentManifold::clearUserCache(btManifoldPoint *pt@<esi>)
{
  if ( pt->m_userPersistentData )
  {
    if ( gContactDestroyedCallback )
    {
      gContactDestroyedCallback(pt->m_userPersistentData);
      pt->m_userPersistentData = 0;
    }
  }
}
