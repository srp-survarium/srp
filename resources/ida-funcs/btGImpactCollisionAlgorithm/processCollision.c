void __thiscall btGImpactCollisionAlgorithm::processCollision(
        btGImpactCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btPersistentManifold *m_manifoldPtr; // eax
  btCollisionAlgorithm *m_convex_algorithm; // ecx
  btGImpactMeshShapePart *m_collisionShape; // eax
  btGImpactShapeInterface *v9; // ecx

  m_manifoldPtr = this->m_manifoldPtr;
  if ( m_manifoldPtr )
  {
    this->m_dispatcher->releaseManifold(this->m_dispatcher, m_manifoldPtr);
    this->m_manifoldPtr = 0;
  }
  m_convex_algorithm = this->m_convex_algorithm;
  if ( m_convex_algorithm )
  {
    ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))m_convex_algorithm->~btCollisionAlgorithm)(
      m_convex_algorithm,
      0);
    this->m_dispatcher->freeCollisionAlgorithm(this->m_dispatcher, this->m_convex_algorithm);
    this->m_convex_algorithm = 0;
  }
  this->m_triface0 = -1;
  this->m_part0 = -1;
  this->m_triface1 = -1;
  this->m_part1 = -1;
  this->m_resultOut = resultOut;
  this->m_dispatchInfo = dispatchInfo;
  m_collisionShape = (btGImpactMeshShapePart *)body0->m_collisionShape;
  v9 = (btGImpactShapeInterface *)body1->m_collisionShape;
  if ( m_collisionShape->m_shapeType == 25 )
  {
    if ( v9->m_shapeType == 25 )
      btGImpactCollisionAlgorithm::gimpact_vs_gimpact(
        this,
        body0,
        body1,
        m_collisionShape,
        (btGImpactShapeInterface *)body1->m_collisionShape);
    else
      btGImpactCollisionAlgorithm::gimpact_vs_shape(this, body0, body1, (btStaticPlaneShape *)m_collisionShape, v9, 0);
  }
  else if ( v9->m_shapeType == 25 )
  {
    btGImpactCollisionAlgorithm::gimpact_vs_shape(this, body1, body0, (btStaticPlaneShape *)v9, m_collisionShape, 1);
  }
}
