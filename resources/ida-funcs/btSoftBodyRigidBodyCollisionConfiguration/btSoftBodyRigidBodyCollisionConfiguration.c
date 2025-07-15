btSoftBodyRigidBodyCollisionConfiguration *__userpurge btSoftBodyRigidBodyCollisionConfiguration::btSoftBodyRigidBodyCollisionConfiguration@<eax>(
        btSoftBodyRigidBodyCollisionConfiguration *this@<ecx>,
        btSoftBodyRigidBodyCollisionConfiguration *a2@<eax>,
        const btDefaultCollisionConstructionInfo *constructionInfo)
{
  btCollisionAlgorithmCreateFunc *v4; // eax
  btCollisionAlgorithmCreateFunc *v5; // eax
  btCollisionAlgorithmCreateFunc *v6; // eax
  btCollisionAlgorithmCreateFunc *v7; // eax
  btCollisionAlgorithmCreateFunc *v8; // eax
  btPoolAllocator *m_collisionAlgorithmPool; // eax
  btPoolAllocator *v10; // edx
  btPoolAllocator *v11; // eax

  btDefaultCollisionConfiguration::btDefaultCollisionConfiguration(this, a2, constructionInfo);
  a2->__vftable = (btSoftBodyRigidBodyCollisionConfiguration_vtbl *)&btSoftBodyRigidBodyCollisionConfiguration::`vftable';
  v4 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v4 )
  {
    v4->m_swapped = 0;
    v4->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSoftSoftCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v4 = 0;
  }
  a2->m_softSoftCreateFunc = v4;
  v5 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v5 )
  {
    v5->m_swapped = 0;
    v5->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSoftRigidCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v5 = 0;
  }
  a2->m_softRigidConvexCreateFunc = v5;
  v6 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v6 )
  {
    v6->m_swapped = 0;
    v6->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSoftRigidCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v6 = 0;
  }
  a2->m_swappedSoftRigidConvexCreateFunc = v6;
  v6->m_swapped = 1;
  v7 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v7 )
  {
    v7->m_swapped = 0;
    v7->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSoftBodyConcaveCollisionAlgorithm::CreateFunc::`vftable';
  }
  else
  {
    v7 = 0;
  }
  a2->m_softRigidConcaveCreateFunc = v7;
  v8 = (btCollisionAlgorithmCreateFunc *)btAlignedAllocInternal(8u);
  if ( v8 )
  {
    v8->m_swapped = 0;
    v8->__vftable = (btCollisionAlgorithmCreateFunc_vtbl *)&btSoftBodyConcaveCollisionAlgorithm::SwappedCreateFunc::`vftable';
  }
  else
  {
    v8 = 0;
  }
  a2->m_swappedSoftRigidConcaveCreateFunc = v8;
  v8->m_swapped = 1;
  if ( a2->m_ownsCollisionAlgorithmPool )
  {
    m_collisionAlgorithmPool = a2->m_collisionAlgorithmPool;
    if ( m_collisionAlgorithmPool )
    {
      if ( m_collisionAlgorithmPool->m_elemSize < 176 )
      {
        btAlignedFreeInternal(m_collisionAlgorithmPool->m_pool);
        btAlignedFreeInternal((void *)a2->m_collisionAlgorithmPool);
        v10 = (btPoolAllocator *)btAlignedAllocInternal(0x14u);
        if ( v10 )
          btPoolAllocator::btPoolAllocator(v10, 176, constructionInfo->m_defaultMaxCollisionAlgorithmPoolSize);
        else
          v11 = 0;
        a2->m_collisionAlgorithmPool = v11;
      }
    }
  }
  return a2;
}
