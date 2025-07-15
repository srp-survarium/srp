btSoftBodyTriangleCallback *__thiscall btSoftBodyTriangleCallback::`vector deleting destructor'(
        btSoftBodyTriangleCallback *this,
        char a2)
{
  btHashMap<btInternalVertexPair,btInternalEdge> *v3; // ecx

  this->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btSoftBodyTriangleCallback::`vftable';
  btSoftBodyTriangleCallback::clearCache(this);
  btHashMap<btHashPtr,int>::~btHashMap<btHashPtr,int>(v3);
  this->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
