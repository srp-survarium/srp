void __thiscall btCollisionObject::setCollisionShape(btCollisionObject *this, btCollisionShape *collisionShape)
{
  this->m_collisionShape = collisionShape;
  this->m_rootCollisionShape = collisionShape;
}
