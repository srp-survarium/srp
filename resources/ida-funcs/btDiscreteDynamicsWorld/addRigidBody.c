void __thiscall btDiscreteDynamicsWorld::addRigidBody(btDiscreteDynamicsWorld *this, btRigidBody *body)
{
  btRigidBody *v2; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  btRigidBody **v9; // eax
  btRigidBody **v10; // eax
  bool v11; // al
  btRigidBody **v12; // [esp+8h] [ebp-4h]

  v2 = body;
  if ( (body->m_collisionFlags & 3) == 0 && (body->m_rigidbodyFlags & 1) == 0 )
    btRigidBody::setGravity((btRigidBody *)&this->m_gravity, (int)body);
  if ( body->m_collisionShape )
  {
    if ( (body->m_collisionFlags & 1) != 0 )
    {
      btCollisionObject::setActivationState((btCollisionObject *)this, (int)body, 2);
    }
    else
    {
      m_capacity = this->m_nonStaticRigidBodies.m_capacity;
      m_size = this->m_nonStaticRigidBodies.m_size;
      if ( m_size == m_capacity )
      {
        v6 = m_size ? 2 * m_size : 1;
        if ( m_capacity < v6 )
        {
          if ( v6 )
            v12 = (btRigidBody **)btAlignedAllocInternal(4 * v6);
          else
            v12 = 0;
          v7 = this->m_nonStaticRigidBodies.m_size;
          v8 = 0;
          if ( v7 > 0 )
          {
            v9 = v12;
            do
            {
              if ( v9 )
              {
                *v9 = this->m_nonStaticRigidBodies.m_data[v8];
                v2 = body;
              }
              ++v8;
              ++v9;
            }
            while ( v8 < v7 );
          }
          if ( this->m_nonStaticRigidBodies.m_data )
          {
            if ( this->m_nonStaticRigidBodies.m_ownsMemory )
              btAlignedFreeInternal(this->m_nonStaticRigidBodies.m_data);
            this->m_nonStaticRigidBodies.m_data = 0;
          }
          this->m_nonStaticRigidBodies.m_ownsMemory = 1;
          this->m_nonStaticRigidBodies.m_data = v12;
          this->m_nonStaticRigidBodies.m_capacity = v6;
        }
      }
      v10 = &this->m_nonStaticRigidBodies.m_data[this->m_nonStaticRigidBodies.m_size];
      if ( v10 )
        *v10 = v2;
      ++this->m_nonStaticRigidBodies.m_size;
    }
    v11 = (v2->m_collisionFlags & 1) == 0 && (v2->m_collisionFlags & 2) == 0;
    this->addCollisionObject(this, v2, !v11 + 1, 2 * v11 - 3);
  }
}


void __thiscall btDiscreteDynamicsWorld::addRigidBody(
        btDiscreteDynamicsWorld *this,
        btRigidBody *body,
        int group,
        int mask)
{
  btRigidBody *v4; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  btRigidBody **v11; // eax
  btRigidBody **v12; // eax
  btRigidBody **v13; // [esp+8h] [ebp-4h]

  v4 = body;
  if ( (body->m_collisionFlags & 3) == 0 && (body->m_rigidbodyFlags & 1) == 0 )
    btRigidBody::setGravity((btRigidBody *)&this->m_gravity, (int)body);
  if ( body->m_collisionShape )
  {
    if ( (body->m_collisionFlags & 1) != 0 )
    {
      btCollisionObject::setActivationState((btCollisionObject *)this, (int)body, 2);
    }
    else
    {
      m_capacity = this->m_nonStaticRigidBodies.m_capacity;
      m_size = this->m_nonStaticRigidBodies.m_size;
      if ( m_size == m_capacity )
      {
        v8 = m_size ? 2 * m_size : 1;
        if ( m_capacity < v8 )
        {
          if ( v8 )
            v13 = (btRigidBody **)btAlignedAllocInternal(4 * v8);
          else
            v13 = 0;
          v9 = this->m_nonStaticRigidBodies.m_size;
          v10 = 0;
          if ( v9 > 0 )
          {
            v11 = v13;
            do
            {
              if ( v11 )
              {
                *v11 = this->m_nonStaticRigidBodies.m_data[v10];
                v4 = body;
              }
              ++v10;
              ++v11;
            }
            while ( v10 < v9 );
          }
          if ( this->m_nonStaticRigidBodies.m_data )
          {
            if ( this->m_nonStaticRigidBodies.m_ownsMemory )
              btAlignedFreeInternal(this->m_nonStaticRigidBodies.m_data);
            this->m_nonStaticRigidBodies.m_data = 0;
          }
          this->m_nonStaticRigidBodies.m_ownsMemory = 1;
          this->m_nonStaticRigidBodies.m_data = v13;
          this->m_nonStaticRigidBodies.m_capacity = v8;
        }
      }
      v12 = &this->m_nonStaticRigidBodies.m_data[this->m_nonStaticRigidBodies.m_size];
      if ( v12 )
        *v12 = v4;
      ++this->m_nonStaticRigidBodies.m_size;
    }
    this->addCollisionObject(this, v4, group, mask);
  }
}
