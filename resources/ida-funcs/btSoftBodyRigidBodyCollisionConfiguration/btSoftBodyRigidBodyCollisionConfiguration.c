btSoftBodyRigidBodyCollisionConfiguration *__userpurge btSoftBodyRigidBodyCollisionConfiguration::btSoftBodyRigidBodyCollisionConfiguration@<eax>(
        btSoftBodyRigidBodyCollisionConfiguration *this@<ecx>,
        btSoftBodyRigidBodyCollisionConfiguration *a2@<edi>,
        const btDefaultCollisionConstructionInfo *constructionInfo)
{
  btCollisionAlgorithmCreateFunc *v3; // eax
  btCollisionAlgorithmCreateFunc *v4; // eax
  btCollisionAlgorithmCreateFunc *v5; // eax
  btCollisionAlgorithmCreateFunc *v6; // eax
  btCollisionAlgorithmCreateFunc *v7; // eax
  int *p_m_elemSize; // eax
  void *v9; // eax
  btPoolAllocator *m_collisionAlgorithmPool; // eax
  btPoolAllocator *v11; // esi
  btPoolAllocator *v12; // eax

  btDefaultCollisionConfiguration::btDefaultCollisionConfiguration(this, (int)a2, constructionInfo);
  ++gNumAlignedAllocs;
  a2->__vftable = (btSoftBodyRigidBodyCollisionConfiguration_vtbl *)&stru_957BE0.m_raw_resource_ptr;
  v3 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v3 )
  {
    v3->m_swapped = 0;
    v3->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSoftSoftCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v3 = 0;
  }
  ++gNumAlignedAllocs;
  a2->m_softSoftCreateFunc = v3;
  v4 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v4 )
  {
    v4->m_swapped = 0;
    v4->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&stru_957BE0.vostok::resources::unmanaged_resource::m_flags;
  }
  else
  {
    v4 = 0;
  }
  ++gNumAlignedAllocs;
  a2->m_softRigidConvexCreateFunc = v4;
  v5 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v5 )
  {
    v5->m_swapped = 0;
    v5->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&stru_957BE0.vostok::resources::unmanaged_resource::m_flags;
  }
  else
  {
    v5 = 0;
  }
  ++gNumAlignedAllocs;
  a2->m_swappedSoftRigidConvexCreateFunc = v5;
  v5->m_swapped = 1;
  v6 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v6 )
  {
    v6->m_swapped = 0;
    v6->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)(&stru_957BE0.m_bones_count + 1);
  }
  else
  {
    v6 = 0;
  }
  ++gNumAlignedAllocs;
  a2->m_softRigidConcaveCreateFunc = v6;
  v7 = (btCollisionAlgorithmCreateFunc *)sAlignedAllocFunc(8u, 16);
  if ( v7 )
  {
    v7->m_swapped = 0;
    v7->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSoftBodyConcaveCollisionAlgorithm::SwappedCreateFunc::`vftable';
  }
  else
  {
    v7 = 0;
  }
  a2->m_swappedSoftRigidConcaveCreateFunc = v7;
  v7->m_swapped = 1;
  if ( a2->m_ownsCollisionAlgorithmPool )
  {
    p_m_elemSize = &a2->m_collisionAlgorithmPool->m_elemSize;
    if ( p_m_elemSize )
    {
      if ( *p_m_elemSize < 176 )
      {
        v9 = (void *)p_m_elemSize[4];
        if ( v9 )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v9);
        }
        m_collisionAlgorithmPool = a2->m_collisionAlgorithmPool;
        if ( m_collisionAlgorithmPool )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc((void *)m_collisionAlgorithmPool);
        }
        ++gNumAlignedAllocs;
        v11 = (btPoolAllocator *)sAlignedAllocFunc(0x14u, 16);
        if ( v11 )
        {
          btPoolAllocator::btPoolAllocator(v11, 176, constructionInfo->m_defaultMaxCollisionAlgorithmPoolSize);
          a2->m_collisionAlgorithmPool = v12;
          return a2;
        }
        a2->m_collisionAlgorithmPool = 0;
      }
    }
  }
  return a2;
}
