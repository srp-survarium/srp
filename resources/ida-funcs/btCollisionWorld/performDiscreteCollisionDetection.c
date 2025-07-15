void __thiscall btCollisionWorld::performDiscreteCollisionDetection(btCollisionWorld *this)
{
  btDispatcher *m_dispatcher1; // edi
  btDispatcher_vtbl *v3; // ebx
  int v4; // eax

  this->m_broadphasePairCache->calculateOverlappingPairs(this->m_broadphasePairCache, this->m_dispatcher1);
  m_dispatcher1 = this->m_dispatcher1;
  if ( m_dispatcher1 )
  {
    v3 = m_dispatcher1->__vftable;
    v4 = ((int (__thiscall *)(btBroadphaseInterface *, btDispatcherInfo *, btDispatcher *))this->m_broadphasePairCache->getOverlappingPairCache)(
           this->m_broadphasePairCache,
           &this->m_dispatchInfo,
           m_dispatcher1);
    ((void (__thiscall *)(btDispatcher *, int))v3->dispatchAllCollisionPairs)(m_dispatcher1, v4);
  }
}
