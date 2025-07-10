void __userpurge btGImpactCollisionAlgorithm::shape_vs_shape_collision(
        btGImpactCollisionAlgorithm *this@<esi>,
        btCollisionShape *shape0@<edx>,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btCollisionShape *shape1)
{
  btCollisionShape *m_collisionShape; // ecx
  btCollisionAlgorithm *v8; // edi
  btCollisionShape *tmpShape1; // [esp+3Ch] [ebp+4h]
  btCollisionShape *tmpShape0; // [esp+40h] [ebp+8h]

  m_collisionShape = body1->m_collisionShape;
  tmpShape0 = body0->m_collisionShape;
  body0->m_collisionShape = shape0;
  body1->m_collisionShape = shape1;
  tmpShape1 = m_collisionShape;
  if ( !this->m_manifoldPtr )
    this->m_manifoldPtr = this->m_dispatcher->getNewManifold(this->m_dispatcher, body0, body1);
  this->m_resultOut->m_manifoldPtr = this->m_manifoldPtr;
  v8 = this->m_dispatcher->findAlgorithm(this->m_dispatcher, body0, body1, this->m_manifoldPtr);
  this->m_resultOut->setShapeIdentifiersA(this->m_resultOut, this->m_part0, this->m_triface0);
  this->m_resultOut->setShapeIdentifiersB(this->m_resultOut, this->m_part1, this->m_triface1);
  v8->processCollision(v8, body0, body1, this->m_dispatchInfo, this->m_resultOut);
  ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))v8->~btCollisionAlgorithm)(v8, 0);
  this->m_dispatcher->freeCollisionAlgorithm(this->m_dispatcher, v8);
  body0->m_collisionShape = tmpShape0;
  body1->m_collisionShape = tmpShape1;
}
