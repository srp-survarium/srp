btPersistentManifold *__thiscall btCollisionDispatcher::getManifoldByIndexInternal(
        btCollisionDispatcher *this,
        int index)
{
  return this->m_manifoldsPtr.m_data[index];
}
