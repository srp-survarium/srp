void __thiscall btSoftBodyTriangleCallback::~btSoftBodyTriangleCallback(btSoftBodyTriangleCallback *this)
{
  btHashMap<btInternalVertexPair,btInternalEdge> *v2; // ecx

  this->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btSoftBodyTriangleCallback::`vftable';
  btSoftBodyTriangleCallback::clearCache(this, this);
  btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(v2, (int)&this->m_shapeCache);
  this->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
}
