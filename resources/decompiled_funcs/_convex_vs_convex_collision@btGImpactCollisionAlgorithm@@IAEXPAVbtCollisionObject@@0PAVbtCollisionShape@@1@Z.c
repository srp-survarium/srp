void __userpurge btGImpactCollisionAlgorithm::convex_vs_convex_collision(
        btGImpactCollisionAlgorithm *this@<esi>,
        btCollisionObject *body1@<edi>,
        btCollisionShape *shape0@<ecx>,
        btCollisionShape *shape1@<edx>,
        btCollisionObject *body0)
{
  btCollisionShape *m_collisionShape; // eax
  btCollisionShape *v7; // ebp
  btCollisionShape *tmpShape1; // [esp+34h] [ebp+4h]

  m_collisionShape = body1->m_collisionShape;
  v7 = body0->m_collisionShape;
  body0->m_collisionShape = shape0;
  body1->m_collisionShape = shape1;
  tmpShape1 = m_collisionShape;
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
  body0->m_collisionShape = v7;
  body1->m_collisionShape = tmpShape1;
}
