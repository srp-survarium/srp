void __thiscall btGImpactCollisionAlgorithm::~btGImpactCollisionAlgorithm(btGImpactCollisionAlgorithm *this)
{
  btPersistentManifold *m_manifoldPtr; // eax
  btCollisionAlgorithm *m_convex_algorithm; // ecx

  m_manifoldPtr = this->m_manifoldPtr;
  this->__vftable = (btGImpactCollisionAlgorithm_vtbl *)&btGImpactCollisionAlgorithm::`vftable';
  if ( m_manifoldPtr )
  {
    this->m_dispatcher->releaseManifold(this->m_dispatcher, m_manifoldPtr);
    this->m_manifoldPtr = 0;
  }
  m_convex_algorithm = this->m_convex_algorithm;
  if ( m_convex_algorithm )
  {
    ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))m_convex_algorithm->~btCollisionAlgorithm)(
      m_convex_algorithm,
      0);
    this->m_dispatcher->freeCollisionAlgorithm(this->m_dispatcher, this->m_convex_algorithm);
    this->m_convex_algorithm = 0;
  }
  this->m_triface0 = -1;
  this->m_part0 = -1;
  this->m_triface1 = -1;
  this->m_part1 = -1;
  this->__vftable = (btGImpactCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
