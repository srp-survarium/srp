void __thiscall btSoftBodyConcaveCollisionAlgorithm::~btSoftBodyConcaveCollisionAlgorithm(
        btSoftBodyConcaveCollisionAlgorithm *this)
{
  btSoftBodyTriangleCallback *p_m_btSoftBodyTriangleCallback; // edi
  btHashMap<btInternalVertexPair,btInternalEdge> *v3; // ecx

  p_m_btSoftBodyTriangleCallback = &this->m_btSoftBodyTriangleCallback;
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btSoftBodyConcaveCollisionAlgorithm::`vftable';
  this->m_btSoftBodyTriangleCallback.__vftable = (btSoftBodyTriangleCallback_vtbl *)&btSoftBodyTriangleCallback::`vftable';
  btSoftBodyTriangleCallback::clearCache(
    (btSoftBodyTriangleCallback *)this,
    &this->m_btSoftBodyTriangleCallback.__vftable);
  btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(v3, (int)&p_m_btSoftBodyTriangleCallback->m_shapeCache);
  p_m_btSoftBodyTriangleCallback->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
}
