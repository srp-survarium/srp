void __thiscall vostok::physics::bullet_character_controller::step_up(
        vostok::physics::bullet_character_controller *this,
        vostok::physics::bullet_character_controller *current_step_offset,
        float *a3)
{
  btCapsuleShape *p_m_shape; // ebx
  float v4; // xmm1_4
  int m_upAxis; // eax
  float v6; // xmm1_4
  int v7; // edx
  float v8; // xmm0_4
  vostok::math::float2 shape_dim; // [esp+10h] [ebp-30h] BYREF
  unsigned __int64 v10; // [esp+18h] [ebp-28h]
  float v11; // [esp+20h] [ebp-20h] BYREF
  float v12; // [esp+24h] [ebp-1Ch]
  float v13; // [esp+28h] [ebp-18h]
  float v14[4]; // [esp+30h] [ebp-10h] BYREF

  p_m_shape = &current_step_offset->m_shape;
  v4 = current_step_offset->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[(current_step_offset->m_shape.m_upAxis + 2)
                                                                             % 3]
     + current_step_offset->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[current_step_offset->m_shape.m_upAxis];
  v11 = (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * v4)
      + current_step_offset->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[0];
  v12 = current_step_offset->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[1]
      + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * v4);
  v13 = current_step_offset->m_ghost_object.m_worldTransform.m_origin.mVec128.m128_f32[2]
      + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * v4);
  vostok::physics::capsule_center_to_bottom_position(
    &current_step_offset->m_ghost_object.m_worldTransform.m_origin,
    &current_step_offset->m_shape,
    (int)v14);
  m_upAxis = current_step_offset->m_shape.m_upAxis;
  v6 = 0.0;
  if ( (float)(current_step_offset->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis]
             - (float)(s_cc_step_height * 0.5)) >= 0.0 )
    v6 = current_step_offset->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis]
       - (float)(s_cc_step_height * 0.5);
  v7 = (current_step_offset->m_shape.m_upAxis + 2) % 3;
  shape_dim.x = p_m_shape->m_implicitShapeDimensions.mVec128.m128_f32[(m_upAxis + 2) % 3] * 2.0;
  shape_dim.y = (float)(p_m_shape->m_implicitShapeDimensions.mVec128.m128_f32[v7] + v6) * 2.0;
  vostok::physics::bullet_character_controller::setup_shape_dim(
    &shape_dim,
    (int)p_m_shape,
    (int)&current_step_offset->m_ghost_object.m_worldTransform.m_origin,
    (int)current_step_offset,
    current_step_offset);
  v8 = current_step_offset->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[(current_step_offset->m_shape.m_upAxis + 2)
                                                                             % 3]
     + current_step_offset->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[current_step_offset->m_shape.m_upAxis];
  shape_dim.x = v11 - (float)(v8 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
  shape_dim.y = v12 - (float)(v8 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]);
  *(float *)&v10 = v13 - (float)(v8 * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]);
  HIDWORD(v10) = 0;
  *(vostok::math::float2 *)current_step_offset->m_current_pos.mVec128.m128_f32 = shape_dim;
  current_step_offset->m_current_pos.mVec128.m128_u64[1] = v10;
  vostok::physics::capsule_center_to_bottom_position(&current_step_offset->m_current_pos, p_m_shape, (int)&v11);
  *a3 = (float)((float)((float)(v12 - v14[1])
                      * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
              + (float)((float)(v13 - v14[2])
                      * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
      + (float)((float)(v11 - v14[0]) * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
}
