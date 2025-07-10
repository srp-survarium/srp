void __userpurge vostok::physics::bullet_character_controller::bullet_character_controller(
        vostok::physics::bullet_character_controller *this@<esi>,
        const vostok::math::float2 *stand_shape_dim@<ecx>,
        const vostok::math::float2 *crouch_shape_dim@<eax>,
        btPairCachingGhostObject *ghost_object,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask)
{
  float v6; // xmm1_4
  const vostok::math::float4x4 *v7; // xmm1_4

  this->__vftable = (vostok::physics::bullet_character_controller_vtbl *)&vostok::physics::bullet_character_controller::`vftable';
  v6 = SNaN;
  this->m_collision_world = 0;
  this->m_walk_vector.mVec128.m128_u64[0] = 0;
  this->m_walk_vector.mVec128.m128_u64[1] = 0;
  this->m_normalizedDirection.mVec128.m128_u64[0] = 0;
  this->m_normalizedDirection.mVec128.m128_u64[1] = 0;
  this->m_current_pos.mVec128.m128_u64[0] = 0;
  this->m_current_pos.mVec128.m128_u64[1] = 0;
  this->m_pre_step_position.mVec128.m128_u64[0] = 0;
  this->m_pre_step_position.mVec128.m128_u64[1] = 0;
  this->m_current_step_offset = 0.0;
  this->m_current_shape_dim.x = v6;
  this->m_current_shape_dim.y = v6;
  this->m_stand_shape_dim.x = stand_shape_dim->x;
  v7 = clear_value;
  this->m_stand_shape_dim.y = stand_shape_dim->y;
  this->m_crouch_shape_dim = *crouch_shape_dim;
  this->m_ghost_object = ghost_object;
  this->m_shape.m_userPointer = 0;
  this->m_shape.m_localScaling.mVec128.m128_i32[3] = 0;
  this->m_shape.m_localScaling.mVec128.m128_i32[0] = (int)v7;
  this->m_shape.m_localScaling.mVec128.m128_i32[1] = (int)v7;
  this->m_shape.m_localScaling.mVec128.m128_i32[2] = (int)v7;
  this->m_shape.m_collisionMargin = 0.039999999;
  this->m_shape.__vftable = (btCapsuleShape_vtbl *)&btCapsuleShape::`vftable';
  this->m_shape.m_shapeType = 10;
  this->m_shape.m_upAxis = 1;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_i32[3] = 0;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_i32[0] = (int)v7;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[1] = FLOAT_0_5;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_i32[2] = (int)v7;
  this->m_vertical_velocity = 0.0;
  this->m_max_fall_speed = 55.0;
  this->m_jump_speed = FLOAT_10_0;
  this->m_in_crouch = 0;
  this->m_collision_filter_group = 4;
  this->m_collision_filter_mask = 2;
  this->m_max_slope_in_radians = pi_d3;
  this->m_max_slope_angle_cos = cosf(1.0471976);
  this->m_gravity = 29.400002;
  this->m_was_on_ground = 0;
  this->m_jumping = 0;
  this->m_useGhostObjectSweepTest = 1;
  this->m_walk_vector_applied = 0;
  this->m_on_steep_slope = 0;
  this->m_has_updates = 0;
  this->m_positions._M_impl._M_node._M_data._M_next = &this->m_positions._M_impl._M_node._M_data;
  this->m_positions._M_impl._M_node._M_data._M_prev = &this->m_positions._M_impl._M_node._M_data;
  vostok::physics::bullet_character_controller::setup_crouch_state(this, 0, (int)this);
}
