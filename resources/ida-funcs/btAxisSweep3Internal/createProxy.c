btAxisSweep3Internal<unsigned short>::Handle *__thiscall btAxisSweep3Internal<unsigned short>::createProxy(
        btAxisSweep3Internal<unsigned short> *this,
        btAxisSweep3Internal<unsigned short> *aabbMin,
        const btVector3 *aabbMax,
        int shapeType,
        btVector3 *userPtr,
        void *collisionFilterGroup,
        int collisionFilterMask,
        btDispatcher *dispatcher,
        btDispatcher *multiSapProxy)
{
  btAxisSweep3Internal<unsigned short>::Handle *v10; // esi
  void *v12; // [esp+0h] [ebp-8h]

  v10 = &this->m_pHandles[btAxisSweep3Internal<unsigned short>::addHandle(
                            aabbMin,
                            this,
                            aabbMax,
                            userPtr,
                            collisionFilterGroup,
                            collisionFilterMask,
                            dispatcher,
                            multiSapProxy,
                            v12)];
  if ( this->m_raycastAccelerator )
    v10->m_dbvtProxy = this->m_raycastAccelerator->createProxy(
                         this->m_raycastAccelerator,
                         aabbMin,
                         aabbMax,
                         shapeType,
                         userPtr,
                         collisionFilterGroup,
                         collisionFilterMask,
                         dispatcher,
                         0);
  return v10;
}
