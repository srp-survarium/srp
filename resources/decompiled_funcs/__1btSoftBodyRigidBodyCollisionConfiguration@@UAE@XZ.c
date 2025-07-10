void __thiscall btSoftBodyRigidBodyCollisionConfiguration::~btSoftBodyRigidBodyCollisionConfiguration(
        btSoftBodyRigidBodyCollisionConfiguration *this)
{
  btCollisionAlgorithmCreateFunc *m_softSoftCreateFunc; // ecx
  btCollisionAlgorithmCreateFunc *v3; // eax
  btCollisionAlgorithmCreateFunc *m_softRigidConvexCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_swappedSoftRigidConvexCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_softRigidConcaveCreateFunc; // eax
  btCollisionAlgorithmCreateFunc *m_swappedSoftRigidConcaveCreateFunc; // eax

  m_softSoftCreateFunc = this->m_softSoftCreateFunc;
  this->__vftable = (btSoftBodyRigidBodyCollisionConfiguration_vtbl *)&stru_957BE0.m_raw_resource_ptr;
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))m_softSoftCreateFunc->~btCollisionAlgorithmCreateFunc)(
    m_softSoftCreateFunc,
    0);
  v3 = this->m_softSoftCreateFunc;
  if ( v3 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v3);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_softRigidConvexCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_softRigidConvexCreateFunc,
    0);
  m_softRigidConvexCreateFunc = this->m_softRigidConvexCreateFunc;
  if ( m_softRigidConvexCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_softRigidConvexCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedSoftRigidConvexCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedSoftRigidConvexCreateFunc,
    0);
  m_swappedSoftRigidConvexCreateFunc = this->m_swappedSoftRigidConvexCreateFunc;
  if ( m_swappedSoftRigidConvexCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_swappedSoftRigidConvexCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_softRigidConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_softRigidConcaveCreateFunc,
    0);
  m_softRigidConcaveCreateFunc = this->m_softRigidConcaveCreateFunc;
  if ( m_softRigidConcaveCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_softRigidConcaveCreateFunc);
  }
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedSoftRigidConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedSoftRigidConcaveCreateFunc,
    0);
  m_swappedSoftRigidConcaveCreateFunc = this->m_swappedSoftRigidConcaveCreateFunc;
  if ( m_swappedSoftRigidConcaveCreateFunc )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_swappedSoftRigidConcaveCreateFunc);
  }
  btDefaultCollisionConfiguration::~btDefaultCollisionConfiguration(this);
}
