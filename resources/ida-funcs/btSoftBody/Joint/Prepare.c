void __thiscall btSoftBody::Joint::Prepare(btSoftBody::Joint *this, float dt, int __formal)
{
  btRigidBody *m_rigid; // edx
  btCollisionObject *m_collisionObject; // edx
  btRigidBody *v6; // edx
  btCollisionObject *v7; // edx

  m_rigid = this->m_bodies[0].m_rigid;
  if ( m_rigid )
    btCollisionObject::activate((btCollisionObject *)this, (int)m_rigid);
  m_collisionObject = this->m_bodies[0].m_collisionObject;
  if ( m_collisionObject )
    btCollisionObject::activate((btCollisionObject *)this, (int)m_collisionObject);
  v6 = this->m_bodies[1].m_rigid;
  if ( v6 )
    btCollisionObject::activate((btCollisionObject *)this, (int)v6);
  v7 = this->m_bodies[1].m_collisionObject;
  if ( v7 )
    btCollisionObject::activate((btCollisionObject *)this, (int)v7);
}
