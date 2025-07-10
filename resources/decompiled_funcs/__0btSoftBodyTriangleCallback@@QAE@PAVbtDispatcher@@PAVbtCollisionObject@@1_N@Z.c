void __stdcall btSoftBodyTriangleCallback::btSoftBodyTriangleCallback(
        btSoftBodyTriangleCallback *this,
        btSoftBody *body0)
{
  btDispatcher *dispatcher; // eax
  bool isSwapped; // dl
  btSoftBody *body1; // esi
  btSoftBody *v5; // ecx
  btCollisionObject *v6; // eax

  this->m_dispatcher = dispatcher;
  this->__vftable = (btSoftBodyTriangleCallback_vtbl *)&btSoftBodyTriangleCallback::`vftable';
  this->m_dispatchInfoPtr = 0;
  this->m_shapeCache.m_hashTable.m_data = 0;
  this->m_shapeCache.m_hashTable.m_size = 0;
  this->m_shapeCache.m_hashTable.m_capacity = 0;
  this->m_shapeCache.m_hashTable.m_ownsMemory = 1;
  this->m_shapeCache.m_next.m_ownsMemory = 1;
  this->m_shapeCache.m_next.m_data = 0;
  this->m_shapeCache.m_next.m_size = 0;
  this->m_shapeCache.m_next.m_capacity = 0;
  this->m_shapeCache.m_valueArray.m_ownsMemory = 1;
  this->m_shapeCache.m_valueArray.m_data = 0;
  this->m_shapeCache.m_valueArray.m_size = 0;
  this->m_shapeCache.m_valueArray.m_capacity = 0;
  this->m_shapeCache.m_keyArray.m_ownsMemory = 1;
  this->m_shapeCache.m_keyArray.m_data = 0;
  this->m_shapeCache.m_keyArray.m_size = 0;
  this->m_shapeCache.m_keyArray.m_capacity = 0;
  v5 = body1;
  if ( !isSwapped )
    v5 = body0;
  this->m_softBody = v5;
  v6 = body0;
  if ( !isSwapped )
    v6 = body1;
  this->m_triBody = v6;
  btSoftBodyTriangleCallback::clearCache((btSoftBodyTriangleCallback *)v5, this);
}
