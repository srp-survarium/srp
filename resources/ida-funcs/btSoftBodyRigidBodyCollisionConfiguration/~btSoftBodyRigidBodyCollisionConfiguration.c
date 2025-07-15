void __thiscall btSoftBodyRigidBodyCollisionConfiguration::~btSoftBodyRigidBodyCollisionConfiguration(
        btSoftBodyRigidBodyCollisionConfiguration *this)
{
  btCollisionAlgorithmCreateFunc *m_softSoftCreateFunc; // ecx

  m_softSoftCreateFunc = this->m_softSoftCreateFunc;
  this->__vftable = (btSoftBodyRigidBodyCollisionConfiguration_vtbl *)&btSoftBodyRigidBodyCollisionConfiguration::`vftable';
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))m_softSoftCreateFunc->~btCollisionAlgorithmCreateFunc)(
    m_softSoftCreateFunc,
    0);
  btAlignedFreeInternal(this->m_softSoftCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_softRigidConvexCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_softRigidConvexCreateFunc,
    0);
  btAlignedFreeInternal(this->m_softRigidConvexCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedSoftRigidConvexCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedSoftRigidConvexCreateFunc,
    0);
  btAlignedFreeInternal(this->m_swappedSoftRigidConvexCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_softRigidConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_softRigidConcaveCreateFunc,
    0);
  btAlignedFreeInternal(this->m_softRigidConcaveCreateFunc);
  ((void (__thiscall *)(btCollisionAlgorithmCreateFunc *, _DWORD))this->m_swappedSoftRigidConcaveCreateFunc->~btCollisionAlgorithmCreateFunc)(
    this->m_swappedSoftRigidConcaveCreateFunc,
    0);
  btAlignedFreeInternal(this->m_swappedSoftRigidConcaveCreateFunc);
  btDefaultCollisionConfiguration::~btDefaultCollisionConfiguration(this);
}
