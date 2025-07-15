btCollisionAlgorithm *__thiscall btCollisionDispatcher::findAlgorithm(
        btCollisionDispatcher *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btPersistentManifold *sharedManifold)
{
  btCollisionShape *m_collisionShape; // eax
  btCollisionAlgorithmCreateFunc *v5; // ecx
  btCollisionAlgorithmConstructionInfo ci; // [esp+8h] [ebp-8h] BYREF

  ci.m_manifold = sharedManifold;
  m_collisionShape = body0->m_collisionShape;
  ci.m_dispatcher1 = this;
  v5 = this->m_doubleDispatch[m_collisionShape->m_shapeType][body1->m_collisionShape->m_shapeType];
  return v5->CreateCollisionAlgorithm(v5, &ci, body0, body1);
}
