btDefaultCollisionConfiguration *__thiscall btDefaultCollisionConfiguration::btDefaultCollisionConfiguration(
        btDefaultCollisionConfiguration *this,
        int constructionInfo,
        const btDefaultCollisionConstructionInfo *constructionInfoa)
{
  btDefaultCollisionConfiguration *v3; // ebp
  float *v4; // eax
  const btDefaultCollisionConstructionInfo *v5; // edi
  btConvexPenetrationDepthSolver *v6; // eax
  btCollisionAlgorithmCreateFunc *v7; // eax
  btConvexPenetrationDepthSolver *m_pdSolver; // ecx
  btVoronoiSimplexSolver *m_simplexSolver; // edx
  btCollisionAlgorithmCreateFunc *v10; // eax
  btCollisionAlgorithmCreateFunc *v11; // eax
  btCollisionAlgorithmCreateFunc *v12; // eax
  btCollisionAlgorithmCreateFunc *v13; // eax
  btCollisionAlgorithmCreateFunc *v14; // eax
  btCollisionAlgorithmCreateFunc *v15; // eax
  btCollisionAlgorithmCreateFunc *v16; // eax
  btCollisionAlgorithmCreateFunc *v17; // eax
  btCollisionAlgorithmCreateFunc *v18; // eax
  btCollisionAlgorithmCreateFunc *v19; // eax
  btCollisionAlgorithmCreateFunc *v20; // eax
  bool v21; // cc
  int *p_m_customCollisionAlgorithmMaxElementSize; // eax
  int *p_constructionInfo; // eax
  int *p_maxSize3; // eax
  btStackAlloc *v25; // eax
  btStackAlloc *v26; // esi
  unsigned int m_defaultStackAllocatorSize; // edi
  btPoolAllocator *v28; // esi
  btPoolAllocator *v29; // eax
  btPoolAllocator *v31; // esi
  btPoolAllocator *v32; // eax
  int maxSize2; // [esp+10h] [ebp-8h] BYREF
  int maxSize3; // [esp+14h] [ebp-4h] BYREF

  v3 = (btDefaultCollisionConfiguration *)constructionInfo;
  ++gNumAlignedAllocs;
  *(_DWORD *)constructionInfo = &btDefaultCollisionConfiguration::`vftable';
  v4 = (float *)sAlignedAllocFunc(0x190u, 16);
  if ( v4 )
  {
    v4[80] = FLOAT_0_000099999997;
    *((_WORD *)v4 + 176) &= 0xFFF0u;
  }
  else
  {
    v4 = 0;
  }
  v5 = constructionInfoa;
  ++gNumAlignedAllocs;
  v3->m_simplexSolver = (btVoronoiSimplexSolver *)v4;
  if ( v5->m_useEpaPenetrationAlgorithm )
  {
    v6 = (btConvexPenetrationDepthSolver *)sAlignedAllocFunc(4u, 16);
    if ( v6 )
    {
      v6->__vftable = (btConvexPenetrationDepthSolver_vtbl *)&btGjkEpaPenetrationDepthSolver::`vftable';
      goto LABEL_10;
    }
  }
  else
  {
    v6 = (btConvexPenetrationDepthSolver *)sAlignedAllocFunc(4u, 16);
    if ( v6 )
    {
      v6->__vftable = (btConvexPenetrationDepthSolver_vtbl *)&btMinkowskiPenetrationDepthSolver::`vftable';
      goto LABEL_10;
    }
  }
  v6 = 0;
LABEL_10:
  ++gNumAlignedAllocs;
  v3->m_pdSolver = v6;
  v7 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(0x18u, 16);
  if ( v7 )
  {
    m_pdSolver = v3->m_pdSolver;
    m_simplexSolver = v3->m_simplexSolver;
    v7->m_swapped = 0;
    v7->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexConvexAlgorithm::CreateFunc::`vftable';
    v7[2].__vftable = 0;
    *(_DWORD *)&v7[2].m_swapped = 3;
    *(_DWORD *)&v7[1].m_swapped = m_simplexSolver;
    v7[1].__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)m_pdSolver;
  }
  else
  {
    v7 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_convexConvexCreateFunc = v7;
  v10 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v10 )
  {
    v10->m_swapped = 0;
    v10->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexConcaveCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v10 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_convexConcaveCreateFunc = v10;
  v11 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v11 )
  {
    v11->m_swapped = 0;
    v11->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexConcaveCollisionAlgorithm::SwappedCreateFunc::`vftable';
  }
  else
  {
    v11 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_swappedConvexConcaveCreateFunc = v11;
  v12 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v12 )
  {
    v12->m_swapped = 0;
    v12->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btCompoundCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v12 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_compoundCreateFunc = v12;
  v13 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v13 )
  {
    v13->m_swapped = 0;
    v13->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btCompoundCollisionAlgorithm::SwappedCreateFunc::`vftable';
  }
  else
  {
    v13 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_swappedCompoundCreateFunc = v13;
  v14 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v14 )
  {
    v14->m_swapped = 0;
    v14->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btEmptyAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v14 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_emptyCreateFunc = v14;
  v15 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v15 )
  {
    v15->m_swapped = 0;
    v15->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSphereSphereCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v15 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_sphereSphereCF = v15;
  v16 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v16 )
  {
    v16->m_swapped = 0;
    v16->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSphereTriangleCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v16 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_sphereTriangleCF = v16;
  v17 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v17 )
  {
    v17->m_swapped = 0;
    v17->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSphereTriangleCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v17 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_triangleSphereCF = v17;
  v17->m_swapped = 1;
  v18 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v18 )
  {
    v18->m_swapped = 0;
    v18->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btBoxBoxCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v18 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_boxBoxCF = v18;
  v19 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(0x10u, 16);
  if ( v19 )
  {
    v19->m_swapped = 0;
    v19->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexPlaneCollisionAlgorithm::CreateFunc::`vftable';
    v19[1].__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)1;
    *(_DWORD *)&v19[1].m_swapped = 0;
  }
  else
  {
    v19 = 0;
  }
  ++gNumAlignedAllocs;
  v3->m_convexPlaneCF = v19;
  v20 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(0x10u, 16);
  if ( v20 )
  {
    v20->m_swapped = 0;
    v20->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btConvexPlaneCollisionAlgorithm::CreateFunc::`vftable';
    v20[1].__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)1;
    *(_DWORD *)&v20[1].m_swapped = 0;
  }
  else
  {
    v20 = 0;
  }
  v3->m_planeConvexCF = v20;
  v20->m_swapped = 1;
  v21 = v5->m_customCollisionAlgorithmMaxElementSize < 36;
  p_m_customCollisionAlgorithmMaxElementSize = &v5->m_customCollisionAlgorithmMaxElementSize;
  constructionInfo = 36;
  maxSize2 = 96;
  maxSize3 = 44;
  if ( v21 )
    p_m_customCollisionAlgorithmMaxElementSize = &constructionInfo;
  constructionInfo = *p_m_customCollisionAlgorithmMaxElementSize;
  p_constructionInfo = &constructionInfo;
  if ( constructionInfo <= 96 )
    p_constructionInfo = &maxSize2;
  constructionInfo = *p_constructionInfo;
  p_maxSize3 = &constructionInfo;
  if ( constructionInfo <= 44 )
    p_maxSize3 = &maxSize3;
  constructionInfo = *p_maxSize3;
  if ( v5->m_stackAlloc )
  {
    v3->m_ownsStackAllocator = 0;
    v3->m_stackAlloc = v5->m_stackAlloc;
  }
  else
  {
    ++gNumAlignedAllocs;
    v3->m_ownsStackAllocator = 1;
    v25 = (btStackAlloc *)sAlignedAllocFunc(0x14u, 16);
    v26 = v25;
    if ( v25 )
    {
      m_defaultStackAllocatorSize = v5->m_defaultStackAllocatorSize;
      v25->data = 0;
      v25->totalsize = 0;
      v25->usedsize = 0;
      v25->current = 0;
      v25->ischild = 0;
      btStackAlloc::create(v25, m_defaultStackAllocatorSize);
      v5 = constructionInfoa;
    }
    else
    {
      v26 = 0;
    }
    v3->m_stackAlloc = v26;
  }
  if ( v5->m_persistentManifoldPool )
  {
    v3->m_ownsPersistentManifoldPool = 0;
    v3->m_persistentManifoldPool = v5->m_persistentManifoldPool;
  }
  else
  {
    ++gNumAlignedAllocs;
    v3->m_ownsPersistentManifoldPool = 1;
    v28 = (btPoolAllocator *)sAlignedAllocFunc(0x14u, 16);
    if ( v28 )
      btPoolAllocator::btPoolAllocator(v28, 1280, v5->m_defaultMaxPersistentManifoldPoolSize);
    else
      v29 = 0;
    v3->m_persistentManifoldPool = v29;
  }
  if ( v5->m_collisionAlgorithmPool )
  {
    v3->m_ownsCollisionAlgorithmPool = 0;
    v3->m_collisionAlgorithmPool = v5->m_collisionAlgorithmPool;
    return v3;
  }
  else
  {
    ++gNumAlignedAllocs;
    v3->m_ownsCollisionAlgorithmPool = 1;
    v31 = (btPoolAllocator *)sAlignedAllocFunc(0x14u, 16);
    if ( v31 )
    {
      btPoolAllocator::btPoolAllocator(v31, constructionInfo, v5->m_defaultMaxCollisionAlgorithmPoolSize);
      v3->m_collisionAlgorithmPool = v32;
    }
    else
    {
      v3->m_collisionAlgorithmPool = 0;
    }
    return v3;
  }
}
