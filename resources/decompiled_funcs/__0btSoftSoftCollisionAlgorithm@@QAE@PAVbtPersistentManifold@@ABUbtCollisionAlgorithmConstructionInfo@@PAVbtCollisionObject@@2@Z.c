void __usercall btSoftSoftCollisionAlgorithm::btSoftSoftCollisionAlgorithm(
        btSoftSoftCollisionAlgorithm *this@<eax>,
        const btCollisionAlgorithmConstructionInfo *ci@<ecx>)
{
  this->__vftable = (btSoftSoftCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = ci->m_dispatcher1;
  this->__vftable = (btSoftSoftCollisionAlgorithm_vtbl *)&btSoftSoftCollisionAlgorithm::`vftable';
}
