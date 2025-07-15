void __userpurge vostok::physics::old_bullet_character_controller::setup_crouch_state(
        bool crouch@<al>,
        vostok::physics::old_bullet_character_controller *this,
        const bool update_origin)
{
  vostok::physics::old_bullet_character_controller *p_m_current_shape_dim; // ecx
  float y; // eax
  float *v5; // edx
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  btDynamicsWorld *m_collision_world; // eax
  unsigned __int64 v10; // [esp+10h] [ebp-10h]
  float v11; // [esp+18h] [ebp-8h]

  v10 = this->m_shape_offset.mVec128.m128_u64[0];
  v11 = this->m_shape_offset.mVec128.m128_f32[2];
  this->m_in_crouch = crouch;
  p_m_current_shape_dim = (vostok::physics::old_bullet_character_controller *)&this->m_current_shape_dim;
  if ( crouch )
  {
    p_m_current_shape_dim->btActionInterface::__vftable = (vostok::physics::old_bullet_character_controller_vtbl *)LODWORD(this->m_crouch_shape_dim.x);
    y = this->m_crouch_shape_dim.y;
  }
  else
  {
    p_m_current_shape_dim->btActionInterface::__vftable = (vostok::physics::old_bullet_character_controller_vtbl *)LODWORD(this->m_stand_shape_dim.x);
    y = this->m_stand_shape_dim.y;
  }
  this->m_current_shape_dim.y = y;
  vostok::physics::old_bullet_character_controller::setup_shape_dim(p_m_current_shape_dim, (int)this);
  if ( update_origin )
  {
    v6 = v11 - v5[2];
    v7 = this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[0] - (float)(*(float *)&v10 - *v5);
    this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[1] = this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[1]
                                                                       - (float)(*((float *)&v10 + 1) - v5[1]);
    v8 = this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[2] - v6;
    this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[0] = v7;
    this->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[2] = v8;
  }
  btCollisionObject::setInterpolationWorldTransform(
    (btCollisionObject *)&this->m_ghost_object.m_worldTransform,
    (btVector3 *)&this->m_ghost_object);
  this->m_ghost_object.setCollisionShape(&this->m_ghost_object, &this->m_shape);
  m_collision_world = this->m_collision_world;
  if ( m_collision_world )
    this->m_ghost_object.m_hashPairCache->cleanProxyFromPairs(
      this->m_ghost_object.m_hashPairCache,
      this->m_ghost_object.m_broadphaseHandle,
      m_collision_world->m_dispatcher1);
}
