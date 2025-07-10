void __userpurge btPersistentManifold::removeContactPoint(int index@<eax>, btPersistentManifold *this)
{
  btManifoldPoint *v3; // edi
  void *m_userPersistentData; // eax
  int v5; // eax
  char *v6; // eax

  v3 = &this->m_pointCache[index];
  m_userPersistentData = this->m_pointCache[index].m_userPersistentData;
  if ( m_userPersistentData && gContactDestroyedCallback )
  {
    gContactDestroyedCallback(m_userPersistentData);
    v3->m_userPersistentData = 0;
  }
  v5 = this->m_cachedPoints - 1;
  if ( index != v5 )
  {
    v6 = (char *)this + 288 * v5;
    qmemcpy(v3, v6 + 16, sizeof(btManifoldPoint));
    *((_DWORD *)v6 + 31) = 0;
    *((_DWORD *)v6 + 59) = 0;
    *((_DWORD *)v6 + 67) = 0;
    *((_DWORD *)v6 + 75) = 0;
    *((_DWORD *)v6 + 32) = 0;
    v6[132] = 0;
    *((_DWORD *)v6 + 34) = 0;
    *((_DWORD *)v6 + 35) = 0;
    *((_DWORD *)v6 + 40) = 0;
  }
  --this->m_cachedPoints;
}
