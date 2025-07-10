void __thiscall btAxisSweep3Internal<unsigned short>::destroyProxy(
        btAxisSweep3Internal<unsigned short> *this,
        btBroadphaseProxy *proxy,
        btDispatcher *dispatcher)
{
  if ( this->m_raycastAccelerator )
    this->m_raycastAccelerator->destroyProxy(
      this->m_raycastAccelerator,
      (btBroadphaseProxy *)proxy[1].m_uniqueId,
      dispatcher);
  btAxisSweep3Internal<unsigned short>::removeHandle(
    (btAxisSweep3Internal<unsigned short> *)LOWORD(proxy->m_uniqueId),
    proxy->m_uniqueId,
    dispatcher);
}
