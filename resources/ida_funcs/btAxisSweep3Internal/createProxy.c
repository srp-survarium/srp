btAxisSweep3Internal<unsigned short>::Handle *__thiscall btAxisSweep3Internal<unsigned short>::createProxy(
        btAxisSweep3Internal<unsigned short> *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        int shapeType,
        void *userPtr,
        int collisionFilterGroup,
        int collisionFilterMask,
        btDispatcher *dispatcher,
        void *multiSapProxy)
{
  btAxisSweep3Internal<unsigned short>::Handle *v10; // esi

  v10 = &this->m_pHandles[btAxisSweep3Internal<unsigned short>::addHandle(
                            this,
                            aabbMin,
                            aabbMax,
                            userPtr,
                            collisionFilterGroup,
                            collisionFilterMask,
                            dispatcher,
                            multiSapProxy)];
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
