void __thiscall btSoftBodyTriangleCallback::~btSoftBodyTriangleCallback(btSoftBodyTriangleCallback *this)
{
  btHashMap<btHashKey<btTriIndex>,btTriIndex> *v2; // ecx

  this->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btSoftBodyTriangleCallback::`vftable';
  btSoftBodyTriangleCallback::clearCache(this, this);
  btHashMap<btHashKey<btTriIndex>,btTriIndex>::~btHashMap<btHashKey<btTriIndex>,btTriIndex>(
    v2,
    (int)&this->m_shapeCache);
  this->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
}
