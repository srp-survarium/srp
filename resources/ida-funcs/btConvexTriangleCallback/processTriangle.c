void __thiscall btConvexTriangleCallback::processTriangle(
        btConvexTriangleCallback *this,
        btTriangleShape *triangle,
        int partId,
        int triangleIndex)
{
  btDispatcher *m_dispatcher; // ebx
  btCollisionObject *m_triBody; // edi
  float m_collisionMarginTriangle; // xmm0_4
  btDispatcher_vtbl *v8; // eax
  btPolyhedralConvexShape_vtbl *v9; // eax
  btManifoldResult *m_resultOut; // ecx
  btManifoldResult_vtbl *v11; // eax
  btCollisionObject *m_convexBody; // [esp+4h] [ebp-ACh]
  btCollisionObject *v13; // [esp+8h] [ebp-A8h]
  btPersistentManifold *m_manifoldPtr; // [esp+Ch] [ebp-A4h]
  const btVector3 *v15; // [esp+10h] [ebp-A0h]
  int v16; // [esp+10h] [ebp-A0h]
  int v17; // [esp+28h] [ebp-88h]
  btCollisionShape *m_collisionShape; // [esp+2Ch] [ebp-84h]
  btPolyhedralConvexShape v19; // [esp+30h] [ebp-80h] BYREF

  m_dispatcher = this->m_dispatcher;
  m_triBody = this->m_triBody;
  if ( this->m_convexBody->m_collisionShape->m_shapeType < 20 )
  {
    btTriangleShape::btTriangleShape(
      triangle,
      &v19,
      &triangle->m_localScaling,
      &triangle->m_implicitShapeDimensions,
      v15);
    m_collisionMarginTriangle = this->m_collisionMarginTriangle;
    m_collisionShape = m_triBody->m_collisionShape;
    m_triBody->m_collisionShape = &v19;
    m_manifoldPtr = this->m_manifoldPtr;
    v8 = m_dispatcher->__vftable;
    v13 = this->m_triBody;
    m_convexBody = this->m_convexBody;
    v19.m_collisionMargin = m_collisionMarginTriangle;
    v9 = (btPolyhedralConvexShape_vtbl *)((int (__thiscall *)(btDispatcher *, btCollisionObject *, btCollisionObject *, btPersistentManifold *, int))v8->findAlgorithm)(
                                           m_dispatcher,
                                           m_convexBody,
                                           v13,
                                           m_manifoldPtr,
                                           v16);
    m_resultOut = this->m_resultOut;
    v19.__vftable = v9;
    v11 = m_resultOut->__vftable;
    if ( this->m_resultOut->m_body0 == this->m_triBody )
      ((void (__cdecl *)(int, int))v11->setShapeIdentifiersA)(partId, triangleIndex);
    else
      ((void (__cdecl *)(int, int))v11->setShapeIdentifiersB)(partId, triangleIndex);
    (*(void (__thiscall **)(int, btCollisionObject *, btCollisionObject *, const btDispatcherInfo *, btManifoldResult *))(*(_DWORD *)v17 + 4))(
      v17,
      this->m_convexBody,
      this->m_triBody,
      this->m_dispatchInfoPtr,
      this->m_resultOut);
    (**(void (__thiscall ***)(int, _DWORD))v17)(v17, 0);
    ((void (__thiscall *)(btDispatcher *))m_dispatcher->freeCollisionAlgorithm)(m_dispatcher);
    m_triBody->m_collisionShape = m_collisionShape;
    btPolyhedralConvexShape::~btPolyhedralConvexShape(&v19);
  }
}
