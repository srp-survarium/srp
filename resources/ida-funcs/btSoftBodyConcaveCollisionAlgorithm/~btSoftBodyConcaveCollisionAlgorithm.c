void __thiscall btSoftBodyConcaveCollisionAlgorithm::~btSoftBodyConcaveCollisionAlgorithm(
        btSoftBodyConcaveCollisionAlgorithm *this)
{
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btSoftBodyConcaveCollisionAlgorithm::`vftable';
  btSoftBodyTriangleCallback::~btSoftBodyTriangleCallback(&this->m_btSoftBodyTriangleCallback);
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
