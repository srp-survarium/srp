void __thiscall btCompoundCollisionAlgorithm::getAllContactManifolds(
        btCompoundCollisionAlgorithm *this,
        btAlignedObjectArray<btPersistentManifold *> *manifoldArray)
{
  int i; // edi
  btCollisionAlgorithm **v4; // eax

  for ( i = 0; i < this->m_childCollisionAlgorithms.m_size; ++i )
  {
    v4 = &this->m_childCollisionAlgorithms.m_data[i];
    if ( *v4 )
      (*v4)->getAllContactManifolds(*v4, manifoldArray);
  }
}
