void __thiscall btCompoundCollisionAlgorithm::getAllContactManifolds(
        btCompoundCollisionAlgorithm *this,
        btAlignedObjectArray<btPersistentManifold *> *manifoldArray)
{
  int i; // esi
  btCollisionAlgorithm **m_data; // eax
  bool v5; // zf
  btCollisionAlgorithm **v6; // eax

  for ( i = 0; i < this->m_childCollisionAlgorithms.m_size; ++i )
  {
    m_data = this->m_childCollisionAlgorithms.m_data;
    v5 = m_data[i] == 0;
    v6 = &m_data[i];
    if ( !v5 )
      (*v6)->getAllContactManifolds(*v6, manifoldArray);
  }
}
