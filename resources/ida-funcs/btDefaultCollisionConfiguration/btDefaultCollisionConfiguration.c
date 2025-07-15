btDefaultCollisionConfiguration *__userpurge btDefaultCollisionConfiguration::btDefaultCollisionConfiguration@<eax>(
        btDefaultCollisionConfiguration *this@<ecx>,
        btDefaultCollisionConfiguration *a2@<edi>,
        const btDefaultCollisionConstructionInfo *constructionInfo)
{
  float *v3; // eax
  btConvexPenetrationDepthSolver *v4; // eax
  btCollisionAlgorithmCreateFunc *v5; // eax
  btConvexPenetrationDepthSolver *m_pdSolver; // ecx
  btVoronoiSimplexSolver *m_simplexSolver; // edx
  btCollisionAlgorithmCreateFunc *v8; // eax
  btCollisionAlgorithmCreateFunc *v9; // eax
  btCollisionAlgorithmCreateFunc *v10; // eax
  btCollisionAlgorithmCreateFunc *v11; // eax
  btCollisionAlgorithmCreateFunc *v12; // eax
  btCollisionAlgorithmCreateFunc *v13; // eax
  btCollisionAlgorithmCreateFunc *v14; // eax
  btCollisionAlgorithmCreateFunc *v15; // eax
  btCollisionAlgorithmCreateFunc *v16; // eax
  btCollisionAlgorithmCreateFunc *v17; // eax
  btCollisionAlgorithmCreateFunc *v18; // eax
  const btDefaultCollisionConstructionInfo *v19; // esi
  int *p_m_customCollisionAlgorithmMaxElementSize; // eax
  bool v21; // cc
  int *v22; // eax
  int *v23; // eax
  btStackAlloc *v24; // esi
  btPoolAllocator *m_persistentManifoldPool; // eax
  btPoolAllocator *v26; // edx
  btPoolAllocator *m_collisionAlgorithmPool; // eax
  btPoolAllocator *v28; // edx
  btStackAlloc *v30; // [esp-4h] [ebp-1Ch]
  int v31; // [esp+8h] [ebp-10h] BYREF
  int v32; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int m_defaultStackAllocatorSize; // [esp+10h] [ebp-8h] BYREF
  int v34; // [esp+14h] [ebp-4h] BYREF

  a2->__vftable = (btDefaultCollisionConfiguration_vtbl *)&btDefaultCollisionConfiguration::`vftable';
  v3 = (float *)btAlignedAllocInternal(0x190u);
  if ( v3 )
  {
    v3[80] = FLOAT_0_000099999997;
    *((_WORD *)v3 + 176) &= 0xFFF0u;
  }
  else
  {
    v3 = 0;
  }
  a2->m_simplexSolver = (btVoronoiSimplexSolver *)v3;
  if ( constructionInfo->m_useEpaPenetrationAlgorithm )
  {
    v4 = (btConvexPenetrationDepthSolver *)btAlignedAllocInternal(4u);
    if ( v4 )
    {
      v4->__vftable = (btConvexPenetrationDepthSolver_vtbl *)&btGjkEpaPenetrationDepthSolver::`vftable';
      goto LABEL_10;
    }
  }
  else
  {
    v4 = (btConvexPenetrationDepthSolver *)btAlignedAllocInternal(4u);
    if ( v4 )
    {
      v4->__vftable = (btConvexPenetrationDepthSolver_vtbl *)&btMinkowskiPenetrationDepthSolver::`vftable';
      goto LABEL_10;
    }
  }
  v4 = 0;
LABEL_10:
  a2->m_pdSolver = v4;
  v5 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(0x18u);
  if ( v5 )
  {
    m_pdSolver = a2->m_pdSolver;
    m_simplexSolver = a2->m_simplexSolver;
    v5->m_swapped = 0;
    v5->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexConvexAlgorithm::CreateFunc::`vftable';
    v5[2].__vftable = 0;
    *(_DWORD *)&v5[2].m_swapped = 3;
    *(_DWORD *)&v5[1].m_swapped = m_simplexSolver;
    v5[1].__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)m_pdSolver;
  }
  else
  {
    v5 = 0;
  }
  a2->m_convexConvexCreateFunc = v5;
  v8 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v8 )
  {
    v8->m_swapped = 0;
    v8->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexConcaveCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v8 = 0;
  }
  a2->m_convexConcaveCreateFunc = v8;
  v9 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v9 )
  {
    v9->m_swapped = 0;
    v9->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexConcaveCollisionAlgorithm::SwappedCreateFunc::`vftable';
  }
  else
  {
    v9 = 0;
  }
  a2->m_swappedConvexConcaveCreateFunc = v9;
  v10 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v10 )
  {
    v10->m_swapped = 0;
    v10->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btCompoundCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v10 = 0;
  }
  a2->m_compoundCreateFunc = v10;
  v11 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v11 )
  {
    v11->m_swapped = 0;
    v11->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btCompoundCollisionAlgorithm::SwappedCreateFunc::`vftable';
  }
  else
  {
    v11 = 0;
  }
  a2->m_swappedCompoundCreateFunc = v11;
  v12 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v12 )
  {
    v12->m_swapped = 0;
    v12->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btEmptyAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v12 = 0;
  }
  a2->m_emptyCreateFunc = v12;
  v13 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v13 )
  {
    v13->m_swapped = 0;
    v13->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSphereSphereCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v13 = 0;
  }
  a2->m_sphereSphereCF = v13;
  v14 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v14 )
  {
    v14->m_swapped = 0;
    v14->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSphereTriangleCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v14 = 0;
  }
  a2->m_sphereTriangleCF = v14;
  v15 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v15 )
  {
    v15->m_swapped = 0;
    v15->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSphereTriangleCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v15 = 0;
  }
  a2->m_triangleSphereCF = v15;
  v15->m_swapped = 1;
  v16 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v16 )
  {
    v16->m_swapped = 0;
    v16->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btBoxBoxCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v16 = 0;
  }
  a2->m_boxBoxCF = v16;
  v17 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(0x10u);
  if ( v17 )
  {
    v17->m_swapped = 0;
    v17->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexPlaneCollisionAlgorithm::CreateFunc::`vftable';
    v17[1].__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)1;
    *(_DWORD *)&v17[1].m_swapped = 0;
  }
  else
  {
    v17 = 0;
  }
  a2->m_convexPlaneCF = v17;
  v18 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(0x10u);
  if ( v18 )
  {
    v18->m_swapped = 0;
    v18->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexPlaneCollisionAlgorithm::CreateFunc::`vftable';
    v18[1].__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)1;
    *(_DWORD *)&v18[1].m_swapped = 0;
  }
  else
  {
    v18 = 0;
  }
  v19 = constructionInfo;
  a2->m_planeConvexCF = v18;
  v18->m_swapped = 1;
  p_m_customCollisionAlgorithmMaxElementSize = &constructionInfo->m_customCollisionAlgorithmMaxElementSize;
  v21 = constructionInfo->m_customCollisionAlgorithmMaxElementSize < 36;
  m_defaultStackAllocatorSize = 36;
  v32 = 96;
  v31 = 44;
  if ( v21 )
    p_m_customCollisionAlgorithmMaxElementSize = (int *)&m_defaultStackAllocatorSize;
  v34 = *p_m_customCollisionAlgorithmMaxElementSize;
  v22 = &v34;
  if ( v34 <= 96 )
    v22 = &v32;
  v34 = *v22;
  v23 = &v34;
  if ( v34 <= 44 )
    v23 = &v31;
  v34 = *v23;
  if ( constructionInfo->m_stackAlloc )
  {
    a2->m_ownsStackAllocator = 0;
    a2->m_stackAlloc = constructionInfo->m_stackAlloc;
  }
  else
  {
    a2->m_ownsStackAllocator = 1;
    v24 = (btStackAlloc *)btAlignedAllocInternal(0x14u);
    if ( v24 )
    {
      m_defaultStackAllocatorSize = constructionInfo->m_defaultStackAllocatorSize;
      v24->data = 0;
      v24->totalsize = 0;
      v24->usedsize = 0;
      v24->current = 0;
      v24->ischild = 0;
      btStackAlloc::destroy(v30, (int)v24);
      v24->data = (unsigned __int8 *)btAlignedAllocInternal(m_defaultStackAllocatorSize);
      v24->totalsize = m_defaultStackAllocatorSize;
    }
    else
    {
      v24 = 0;
    }
    a2->m_stackAlloc = v24;
    v19 = constructionInfo;
  }
  if ( v19->m_persistentManifoldPool )
  {
    a2->m_ownsPersistentManifoldPool = 0;
    m_persistentManifoldPool = v19->m_persistentManifoldPool;
  }
  else
  {
    a2->m_ownsPersistentManifoldPool = 1;
    v26 = (btPoolAllocator *)btAlignedAllocInternal(0x14u);
    if ( v26 )
    {
      btPoolAllocator::btPoolAllocator(v26, 1280, v19->m_defaultMaxPersistentManifoldPoolSize);
      v19 = constructionInfo;
    }
    else
    {
      m_persistentManifoldPool = 0;
    }
  }
  a2->m_persistentManifoldPool = m_persistentManifoldPool;
  if ( v19->m_collisionAlgorithmPool )
  {
    a2->m_ownsCollisionAlgorithmPool = 0;
    m_collisionAlgorithmPool = v19->m_collisionAlgorithmPool;
  }
  else
  {
    a2->m_ownsCollisionAlgorithmPool = 1;
    v28 = (btPoolAllocator *)btAlignedAllocInternal(0x14u);
    if ( v28 )
      btPoolAllocator::btPoolAllocator(v28, v34, v19->m_defaultMaxCollisionAlgorithmPoolSize);
    else
      m_collisionAlgorithmPool = 0;
  }
  a2->m_collisionAlgorithmPool = m_collisionAlgorithmPool;
  return a2;
}
