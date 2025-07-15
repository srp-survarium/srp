btCollisionAlgorithm *__thiscall btCollisionDispatcher::findAlgorithm(
        btCollisionDispatcher *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        btPersistentManifold *sharedManifold)
{
  btCollisionShape *m_collisionShape; // edx
  btCollisionAlgorithmCreateFunc *v5; // ecx
  _DWORD v7[2]; // [esp+8h] [ebp-8h] BYREF

  v7[1] = sharedManifold;
  m_collisionShape = body0->m_collisionShape;
  v7[0] = this;
  v5 = this->m_doubleDispatch[m_collisionShape->m_shapeType][body1->m_collisionShape->m_shapeType];
  return v5->CreateCollisionAlgorithm(v5, (btCollisionAlgorithmConstructionInfo *)v7, body0, body1);
}
