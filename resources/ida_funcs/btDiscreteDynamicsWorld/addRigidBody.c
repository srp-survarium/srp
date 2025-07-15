void __thiscall btDiscreteDynamicsWorld::addRigidBody(btDiscreteDynamicsWorld *this, btRigidBody *body)
{
  btRigidBody *v2; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // edi
  btRigidBody **v7; // ebp
  int v8; // edx
  int v9; // eax
  btRigidBody **v10; // ecx
  btRigidBody **m_data; // eax
  btRigidBody **v12; // eax
  int m_activationState1; // eax
  bool v14; // al
  const btVector3 *v15; // [esp+0h] [ebp-8h]

  v2 = body;
  if ( (body->m_collisionFlags & 3) == 0 && (body->m_rigidbodyFlags & 1) == 0 )
    btRigidBody::setGravity((btRigidBody *)&this->m_gravity, v15);
  if ( body->m_collisionShape )
  {
    if ( (body->m_collisionFlags & 1) != 0 )
    {
      m_activationState1 = body->m_activationState1;
      if ( m_activationState1 != 4 && m_activationState1 != 5 )
        body->m_activationState1 = 2;
    }
    else
    {
      m_capacity = this->m_nonStaticRigidBodies.m_capacity;
      m_size = this->m_nonStaticRigidBodies.m_size;
      if ( m_size == m_capacity )
      {
        v6 = 2 * m_size;
        if ( !m_size )
          v6 = 1;
        if ( m_capacity < v6 )
        {
          if ( v6 )
          {
            ++gNumAlignedAllocs;
            v7 = (btRigidBody **)sAlignedAllocFunc(4 * v6, 16);
          }
          else
          {
            v7 = 0;
          }
          v8 = this->m_nonStaticRigidBodies.m_size;
          v9 = 0;
          if ( v8 > 0 )
          {
            v10 = v7;
            do
            {
              if ( v10 )
              {
                *v10 = this->m_nonStaticRigidBodies.m_data[v9];
                v2 = body;
              }
              ++v9;
              ++v10;
            }
            while ( v9 < v8 );
          }
          m_data = this->m_nonStaticRigidBodies.m_data;
          if ( m_data )
          {
            if ( this->m_nonStaticRigidBodies.m_ownsMemory )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(m_data);
            }
            this->m_nonStaticRigidBodies.m_data = 0;
          }
          this->m_nonStaticRigidBodies.m_data = v7;
          this->m_nonStaticRigidBodies.m_ownsMemory = 1;
          this->m_nonStaticRigidBodies.m_capacity = v6;
        }
      }
      v12 = &this->m_nonStaticRigidBodies.m_data[this->m_nonStaticRigidBodies.m_size];
      if ( v12 )
        *v12 = v2;
      ++this->m_nonStaticRigidBodies.m_size;
    }
    v14 = (v2->m_collisionFlags & 1) == 0 && (v2->m_collisionFlags & 2) == 0;
    this->addCollisionObject(this, v2, !v14 + 1, 2 * v14 - 3);
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
  btRigidBody **v9; // ebp
  int v10; // edx
  int v11; // eax
  btRigidBody **v12; // ecx
  btRigidBody **m_data; // eax
  btRigidBody **v14; // eax
  int m_activationState1; // eax
  const btVector3 *v16; // [esp+0h] [ebp-8h]

  v4 = body;
  if ( (body->m_collisionFlags & 3) == 0 && (body->m_rigidbodyFlags & 1) == 0 )
    btRigidBody::setGravity((btRigidBody *)&this->m_gravity, v16);
  if ( body->m_collisionShape )
  {
    if ( (body->m_collisionFlags & 1) != 0 )
    {
      m_activationState1 = body->m_activationState1;
      if ( m_activationState1 != 4 && m_activationState1 != 5 )
        body->m_activationState1 = 2;
    }
    else
    {
      m_capacity = this->m_nonStaticRigidBodies.m_capacity;
      m_size = this->m_nonStaticRigidBodies.m_size;
      if ( m_size == m_capacity )
      {
        v8 = 2 * m_size;
        if ( !m_size )
          v8 = 1;
        if ( m_capacity < v8 )
        {
          if ( v8 )
          {
            ++gNumAlignedAllocs;
            v9 = (btRigidBody **)sAlignedAllocFunc(4 * v8, 16);
          }
          else
          {
            v9 = 0;
          }
          v10 = this->m_nonStaticRigidBodies.m_size;
          v11 = 0;
          if ( v10 > 0 )
          {
            v12 = v9;
            do
            {
              if ( v12 )
              {
                *v12 = this->m_nonStaticRigidBodies.m_data[v11];
                v4 = body;
              }
              ++v11;
              ++v12;
            }
            while ( v11 < v10 );
          }
          m_data = this->m_nonStaticRigidBodies.m_data;
          if ( m_data )
          {
            if ( this->m_nonStaticRigidBodies.m_ownsMemory )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(m_data);
            }
            this->m_nonStaticRigidBodies.m_data = 0;
          }
          this->m_nonStaticRigidBodies.m_data = v9;
          this->m_nonStaticRigidBodies.m_ownsMemory = 1;
          this->m_nonStaticRigidBodies.m_capacity = v8;
        }
      }
      v14 = &this->m_nonStaticRigidBodies.m_data[this->m_nonStaticRigidBodies.m_size];
      if ( v14 )
        *v14 = v4;
      ++this->m_nonStaticRigidBodies.m_size;
    }
    this->addCollisionObject(this, v4, group, mask);
  }
}
