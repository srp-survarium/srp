btPoolAllocator *__thiscall btCollisionDispatcher::getInternalManifoldPool(btCollisionDispatcher *this)
{
  return this->m_persistentManifoldPoolAllocator;
}
