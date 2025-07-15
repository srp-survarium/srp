void __userpurge btGImpactCollisionAlgorithm::convex_vs_convex_collision(
        btGImpactCollisionAlgorithm *this@<esi>,
        btCollisionObject *body1@<edi>,
        btCollisionObject *body0,
        btCollisionShape *shape0,
        btCollisionShape *shape1)
{
  btCollisionShape *v6; // [esp+4h] [ebp-4h]
  btCollisionShape *m_collisionShape; // [esp+10h] [ebp+8h]

  m_collisionShape = body0->m_collisionShape;
  v6 = body1->m_collisionShape;
  body0->m_collisionShape = shape0;
  body1->m_collisionShape = shape1;
  this->m_resultOut->setShapeIdentifiersA(this->m_resultOut, this->m_part0, this->m_triface0);
  this->m_resultOut->setShapeIdentifiersB(this->m_resultOut, this->m_part1, this->m_triface1);
  if ( !this->m_convex_algorithm )
  {
    if ( !this->m_manifoldPtr )
      this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, body0, body1);
    this->m_resultOut->m_manifoldPtr = this->m_manifoldPtr;
    this->m_convex_algorithm = this->m_dispatcher->findAlgorithm(this->m_dispatcher, body0, body1, this->m_manifoldPtr);
  }
  this->m_convex_algorithm->processCollision(
    this->m_convex_algorithm,
    body0,
    body1,
    this->m_dispatchInfo,
    this->m_resultOut);
  body0->m_collisionShape = m_collisionShape;
  body1->m_collisionShape = v6;
}
