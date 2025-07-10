void __thiscall vostok::physics::bullet_physics_world::debug_draw_world(vostok::physics::bullet_physics_world *this)
{
  vostok::physics::bullet_physics_world *v1; // ebx
  btAlignedObjectArray<btCollisionObject *> *p_m_collisionObjects; // esi
  int v3; // edi
  float v4; // xmm0_4
  btCollisionObject *v5; // edx
  __int16 m_collisionFilterGroup; // cx
  int v7; // eax
  _DWORD v9[12]; // [esp+40h] [ebp-30h] BYREF

  v1 = this;
  p_m_collisionObjects = &this->m_dynamicsWorld->m_collisionObjects;
  v3 = 0;
  if ( this->m_dynamicsWorld->m_collisionObjects.m_size > 0 )
  {
    v4 = s_aim_transition_time;
    while ( 1 )
    {
      v5 = p_m_collisionObjects->m_data[v3];
      *(float *)v9 = v4;
      v9[1] = 0;
      *(float *)&v9[2] = v4;
      v9[3] = 0;
      *(float *)&v9[4] = v4;
      *(float *)&v9[5] = v4;
      memset(&v9[6], 0, 12);
      *(float *)&v9[9] = v4;
      *(float *)&v9[10] = v4;
      v9[11] = 0;
      m_collisionFilterGroup = v5->m_broadphaseHandle->m_collisionFilterGroup;
      v7 = -1;
      if ( s_debug_draw_walkable && (m_collisionFilterGroup & 6) != 0 )
        v7 = 0;
      if ( s_debug_draw_hittable && (m_collisionFilterGroup & 8) != 0 )
        v7 = 1;
      if ( s_debug_draw_sensor && (m_collisionFilterGroup & 0x81) != 0 )
        break;
      if ( v7 != -1 )
        goto LABEL_13;
LABEL_14:
      if ( ++v3 >= p_m_collisionObjects->m_size )
        return;
    }
    v7 = 2;
LABEL_13:
    v1->m_dynamicsWorld->debugDrawObject(
      v1->m_dynamicsWorld,
      &v5->m_worldTransform,
      v5->m_collisionShape,
      (const btVector3 *)&v9[4 * v7]);
    v4 = s_aim_transition_time;
    v1 = this;
    goto LABEL_14;
  }
}
