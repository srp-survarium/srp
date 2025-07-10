void __thiscall btConvexTriangleCallback::processTriangle(
        btConvexTriangleCallback *this,
        btVector3 *triangle,
        int partId,
        int triangleIndex)
{
  btDispatcher *m_dispatcher; // ebx
  float m_collisionMarginTriangle; // xmm0_4
  btCollisionAlgorithm *(__thiscall *findAlgorithm)(btDispatcher *, btCollisionObject *, btCollisionObject *, btPersistentManifold *); // edx
  int v8; // esi
  btManifoldResult *m_resultOut; // ecx
  btCollisionObject *m_convexBody; // [esp+180h] [ebp-ACh]
  btCollisionObject *v11; // [esp+184h] [ebp-A8h]
  btPersistentManifold *m_manifoldPtr; // [esp+188h] [ebp-A4h]
  btCollisionObject *m_triBody; // [esp+1A4h] [ebp-88h]
  btCollisionShape *m_collisionShape; // [esp+1A8h] [ebp-84h]
  btTriangleShape v15; // [esp+1ACh] [ebp-80h] BYREF

  m_dispatcher = this->m_dispatcher;
  m_triBody = this->m_triBody;
  if ( this->m_convexBody->m_collisionShape->m_shapeType < 20 )
  {
    btTriangleShape::btTriangleShape(&v15);
    m_collisionMarginTriangle = this->m_collisionMarginTriangle;
    m_collisionShape = m_triBody->m_collisionShape;
    m_triBody->m_collisionShape = &v15;
    m_manifoldPtr = this->m_manifoldPtr;
    v11 = this->m_triBody;
    findAlgorithm = m_dispatcher->findAlgorithm;
    m_convexBody = this->m_convexBody;
    v15.m_collisionMargin = m_collisionMarginTriangle;
    v8 = (int)findAlgorithm(m_dispatcher, m_convexBody, v11, m_manifoldPtr);
    m_resultOut = this->m_resultOut;
    if ( m_resultOut->m_body0 == this->m_triBody )
      m_resultOut->setShapeIdentifiersA(m_resultOut, partId, triangleIndex);
    else
      m_resultOut->setShapeIdentifiersB(m_resultOut, partId, triangleIndex);
    (*(void (__thiscall **)(int, btCollisionObject *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))(*(_DWORD *)v8 + 4))(
      v8,
      this->m_convexBody,
      this->m_triBody,
      this->m_dispatchInfoPtr,
      this->m_resultOut);
    (**(void (__thiscall ***)(int, _DWORD))v8)(v8, 0);
    m_dispatcher->freeCollisionAlgorithm(m_dispatcher, (void *)v8);
    m_triBody->m_collisionShape = m_collisionShape;
    v15.__vftable = (btTriangleShape_vtbl *)&btPolyhedralConvexShape::`vftable';
    if ( v15.m_polyhedron )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v15.m_polyhedron);
    }
  }
}
