btSoftBodyConcaveCollisionAlgorithm *__thiscall btSoftBodyConcaveCollisionAlgorithm::`vector deleting destructor'(
        btSoftBodyConcaveCollisionAlgorithm *this,
        char a2)
{
  btSoftBodyTriangleCallback *p_m_btSoftBodyTriangleCallback; // edi
  btHashMap<btInternalVertexPair,btInternalEdge> *v4; // ecx

  p_m_btSoftBodyTriangleCallback = &this->m_btSoftBodyTriangleCallback;
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btSoftBodyConcaveCollisionAlgorithm::`vftable';
  this->m_btSoftBodyTriangleCallback.__vftable = (btSoftBodyTriangleCallback_vtbl *)&btSoftBodyTriangleCallback::`vftable';
  btSoftBodyTriangleCallback::clearCache((btSoftBodyTriangleCallback *)this);
  btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(v4);
  p_m_btSoftBodyTriangleCallback->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
  this->__vftable = (btSoftBodyConcaveCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
