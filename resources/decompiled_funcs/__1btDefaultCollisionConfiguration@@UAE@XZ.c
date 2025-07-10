void __thiscall btDefaultCollisionConfiguration::~btDefaultCollisionConfiguration(
        btDefaultCollisionConfiguration *this)
{
  bool v2; // zf
  btStackAlloc *m_stackAlloc; // edi
  unsigned __int8 *data; // eax
  btStackAlloc *v5; // edi
  unsigned __int8 *v6; // eax
  btStackAlloc *v7; // eax
  unsigned __int8 *m_pool; // eax
  btPoolAllocator *m_collisionAlgorithmPool; // eax
  unsigned __int8 *v10; // eax
  btPoolAllocator *m_persistentManifoldPool; // eax
  btCollisionAlgorithmCreateFunc *m_convexConvexCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_convexConcaveCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_swappedConvexConcaveCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_compoundCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_swappedCompoundCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_emptyCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_sphereSphereCF; // eax
  btCollisionAlgorithmCreateFunc *m_sphereTriangleCF; // eax
  btCollisionAlgorithmCreateFunc *m_triangleSphereCF; // eax
  btCollisionAlgorithmCreateFunc *m_boxBoxCF; // eax
  btCollisionAlgorithmCreateFunc *m_convexPlaneCF; // eax
  btCollisionAlgorithmCreateFunc *m_planeConvexCF; // eax
  btVoronoiSimplexSolver *m_simplexSolver; // eax
  btConvexPenetrationDepthSolver *m_pdSolver; // eax

  v2 = !this->m_ownsStackAllocator;
  this->__vftable = (btDefaultCollisionConfiguration_vtbl *)&btDefaultCollisionConfiguration::`vftable';
  if ( !v2 )
  {
    m_stackAlloc = this->m_stackAlloc;
    if ( !m_stackAlloc->usedsize )
    {
      if ( !m_stackAlloc->ischild )
      {
        data = m_stackAlloc->data;
        if ( m_stackAlloc->data )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(data);
        }
      }
      m_stackAlloc->data = 0;
      m_stackAlloc->usedsize = 0;
    }
    v5 = this->m_stackAlloc;
    if ( !v5->usedsize )
    {
      if ( !v5->ischild )
      {
        v6 = v5->data;
        if ( v5->data )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v6);
        }
      }
      v5->data = 0;
      v5->usedsize = 0;
    }
    v7 = this->m_stackAlloc;
    if ( v7 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v7);
    }
  }
  if ( this->m_ownsCollisionAlgorithmPool )
  {
    m_pool = this->m_collisionAlgorithmPool->m_pool;
    if ( m_pool )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_pool);
    }
    m_collisionAlgorithmPool = this->m_collisionAlgorithmPool;
    if ( m_collisionAlgorithmPool )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc((void *)m_collisionAlgorithmPool);
    }
  }
  if ( this->m_ownsPersistentManifoldPool )
  {
    v10 = this->m_persistentManifoldPool->m_pool;
    if ( v10 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v10);
    }
    m_persistentManifoldPool = this->m_persistentManifoldPool;
    if ( m_persistentManifoldPool )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc((void *)m_persistentManifoldPool);
    }
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_convexConvexCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_convexConvexCreateFunc,
    0);
  m_convexConvexCreateFunc = this->m_convexConvexCreateFunc;
  if ( m_convexConvexCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_convexConvexCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_convexConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_convexConcaveCreateFunc,
    0);
  m_convexConcaveCreateFunc = this->m_convexConcaveCreateFunc;
  if ( m_convexConcaveCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_convexConcaveCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedConvexConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedConvexConcaveCreateFunc,
    0);
  m_swappedConvexConcaveCreateFunc = this->m_swappedConvexConcaveCreateFunc;
  if ( m_swappedConvexConcaveCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_swappedConvexConcaveCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_compoundCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_compoundCreateFunc,
    0);
  m_compoundCreateFunc = this->m_compoundCreateFunc;
  if ( m_compoundCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_compoundCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedCompoundCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedCompoundCreateFunc,
    0);
  m_swappedCompoundCreateFunc = this->m_swappedCompoundCreateFunc;
  if ( m_swappedCompoundCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_swappedCompoundCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_emptyCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_emptyCreateFunc,
    0);
  m_emptyCreateFunc = this->m_emptyCreateFunc;
  if ( m_emptyCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_emptyCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_sphereSphereCF->~btCollisionAlgorithmCreateFunc)(
    this->m_sphereSphereCF,
    0);
  m_sphereSphereCF = this->m_sphereSphereCF;
  if ( m_sphereSphereCF )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_sphereSphereCF);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_sphereTriangleCF->~btCollisionAlgorithmCreateFunc)(
    this->m_sphereTriangleCF,
    0);
  m_sphereTriangleCF = this->m_sphereTriangleCF;
  if ( m_sphereTriangleCF )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_sphereTriangleCF);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_triangleSphereCF->~btCollisionAlgorithmCreateFunc)(
    this->m_triangleSphereCF,
    0);
  m_triangleSphereCF = this->m_triangleSphereCF;
  if ( m_triangleSphereCF )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_triangleSphereCF);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_boxBoxCF->~btCollisionAlgorithmCreateFunc)(
    this->m_boxBoxCF,
    0);
  m_boxBoxCF = this->m_boxBoxCF;
  if ( m_boxBoxCF )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_boxBoxCF);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_convexPlaneCF->~btCollisionAlgorithmCreateFunc)(
    this->m_convexPlaneCF,
    0);
  m_convexPlaneCF = this->m_convexPlaneCF;
  if ( m_convexPlaneCF )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_convexPlaneCF);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_planeConvexCF->~btCollisionAlgorithmCreateFunc)(
    this->m_planeConvexCF,
    0);
  m_planeConvexCF = this->m_planeConvexCF;
  if ( m_planeConvexCF )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_planeConvexCF);
  }
  m_simplexSolver = this->m_simplexSolver;
  if ( m_simplexSolver )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_simplexSolver);
  }
  ((void (__thiscall *)(btConvexPenetrationDepthSolver *, _DWORD))this->m_pdSolver->~btConvexPenetrationDepthSolver)(
    this->m_pdSolver,
    0);
  m_pdSolver = this->m_pdSolver;
  if ( m_pdSolver )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_pdSolver);
  }
  this->__vftable = (btDefaultCollisionConfiguration_vtbl *)&btCollisionConfiguration::`vftable';
}
