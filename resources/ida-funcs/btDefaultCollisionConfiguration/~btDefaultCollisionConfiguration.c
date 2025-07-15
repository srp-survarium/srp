void __thiscall btDefaultCollisionConfiguration::~btDefaultCollisionConfiguration(
        btDefaultCollisionConfiguration *this)
{
  btStackAlloc *v2; // ecx

  this->__vftable = (btDefaultCollisionConfiguration_vtbl *)&btDefaultCollisionConfiguration::`vftable';
  if ( this->m_ownsStackAllocator )
  {
    btStackAlloc::destroy((btStackAlloc *)this, (int)this->m_stackAlloc);
    btStackAlloc::destroy(v2, (int)this->m_stackAlloc);
    btAlignedFreeInternal(this->m_stackAlloc);
  }
  if ( this->m_ownsCollisionAlgorithmPool )
  {
    btAlignedFreeInternal(this->m_collisionAlgorithmPool->m_pool);
    btAlignedFreeInternal((void *)this->m_collisionAlgorithmPool);
  }
  if ( this->m_ownsPersistentManifoldPool )
  {
    btAlignedFreeInternal(this->m_persistentManifoldPool->m_pool);
    btAlignedFreeInternal((void *)this->m_persistentManifoldPool);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_convexConvexCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_convexConvexCreateFunc,
    0);
  btAlignedFreeInternal(this->m_convexConvexCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_convexConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_convexConcaveCreateFunc,
    0);
  btAlignedFreeInternal(this->m_convexConcaveCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedConvexConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedConvexConcaveCreateFunc,
    0);
  btAlignedFreeInternal(this->m_swappedConvexConcaveCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_compoundCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_compoundCreateFunc,
    0);
  btAlignedFreeInternal(this->m_compoundCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedCompoundCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedCompoundCreateFunc,
    0);
  btAlignedFreeInternal(this->m_swappedCompoundCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_emptyCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_emptyCreateFunc,
    0);
  btAlignedFreeInternal(this->m_emptyCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_sphereSphereCF->~btCollisionAlgorithmCreateFunc)(
    this->m_sphereSphereCF,
    0);
  btAlignedFreeInternal(this->m_sphereSphereCF);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_sphereTriangleCF->~btCollisionAlgorithmCreateFunc)(
    this->m_sphereTriangleCF,
    0);
  btAlignedFreeInternal(this->m_sphereTriangleCF);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_triangleSphereCF->~btCollisionAlgorithmCreateFunc)(
    this->m_triangleSphereCF,
    0);
  btAlignedFreeInternal(this->m_triangleSphereCF);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_boxBoxCF->~btCollisionAlgorithmCreateFunc)(
    this->m_boxBoxCF,
    0);
  btAlignedFreeInternal(this->m_boxBoxCF);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_convexPlaneCF->~btCollisionAlgorithmCreateFunc)(
    this->m_convexPlaneCF,
    0);
  btAlignedFreeInternal(this->m_convexPlaneCF);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_planeConvexCF->~btCollisionAlgorithmCreateFunc)(
    this->m_planeConvexCF,
    0);
  btAlignedFreeInternal(this->m_planeConvexCF);
  btAlignedFreeInternal(this->m_simplexSolver);
  ((void (__thiscall *)(btConvexPenetrationDepthSolver *, _DWORD))this->m_pdSolver->~btConvexPenetrationDepthSolver)(
    this->m_pdSolver,
    0);
  btAlignedFreeInternal(this->m_pdSolver);
  this->__vftable = (btDefaultCollisionConfiguration_vtbl *)&btCollisionConfiguration::`vftable';
}
