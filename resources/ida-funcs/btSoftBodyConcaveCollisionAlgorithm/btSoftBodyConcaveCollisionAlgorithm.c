void __userpurge btSoftBodyConcaveCollisionAlgorithm::btSoftBodyConcaveCollisionAlgorithm(
        btSoftBodyConcaveCollisionAlgorithm *this@<edi>,
        const btCollisionAlgorithmConstructionInfo *ci@<eax>,
        bool isSwapped@<cl>,
        btSoftBody *body0,
        btSoftBody *body1)
{
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  this->m_dispatcher = ci->m_dispatcher1;
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btSoftBodyConcaveCollisionAlgorithm::`vftable';
  this->m_isSwapped = isSwapped;
  btSoftBodyTriangleCallback::btSoftBodyTriangleCallback(
    &this->m_btSoftBodyTriangleCallback,
    ci->m_dispatcher1,
    body0,
    body1,
    isSwapped);
}
