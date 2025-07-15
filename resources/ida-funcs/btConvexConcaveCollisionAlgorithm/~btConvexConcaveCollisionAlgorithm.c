void __thiscall btConvexConcaveCollisionAlgorithm::~btConvexConcaveCollisionAlgorithm(
        btConvexConcaveCollisionAlgorithm *this)
{
  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btConvexConcaveCollisionAlgorithm::`vftable';
  btConvexTriangleCallback::~btConvexTriangleCallback(&this->m_btConvexTriangleCallback);
  this->__vftable = (btConvexConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
