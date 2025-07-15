void __userpurge btSoftRigidCollisionAlgorithm::btSoftRigidCollisionAlgorithm(
        btSoftRigidCollisionAlgorithm *this@<eax>,
        const btCollisionAlgorithmConstructionInfo *ci@<ecx>,
        btPersistentManifold *__formal,
        btCollisionObject *__formala,
        btCollisionObject *a5,
        bool isSwapped)
{
  this->__vftable = (btSoftRigidCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = ci->m_dispatcher1;
  this->__vftable = (btSoftRigidCollisionAlgorithm_vtbl *)&btSoftRigidCollisionAlgorithm::`vftable';
  this->m_isSwapped = (char)__formal;
}
