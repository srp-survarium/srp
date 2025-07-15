void __userpurge vostok::physics::bullet_character_controller::step_forward(
        const btVector3 *move_vector@<eax>,
        vostok::physics::bullet_character_controller *this)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  btVector3 original_move_direction; // [esp+10h] [ebp-10h] BYREF

  v2 = move_vector->mVec128.m128_f32[0];
  if ( fabs(
         (float)((float)(move_vector->mVec128.m128_f32[1] * move_vector->mVec128.m128_f32[1])
               + (float)(move_vector->mVec128.m128_f32[2] * move_vector->mVec128.m128_f32[2]))
       + (float)(v2 * v2)) >= 0.0000099999997 )
  {
    v3 = s_bm_current_air_resistance
       / fsqrt(
           (float)((float)(move_vector->mVec128.m128_f32[1] * move_vector->mVec128.m128_f32[1])
                 + (float)(move_vector->mVec128.m128_f32[2] * move_vector->mVec128.m128_f32[2]))
         + (float)(v2 * v2));
    original_move_direction.mVec128.m128_f32[0] = v2 * v3;
    v4 = v3 * move_vector->mVec128.m128_f32[1];
    original_move_direction.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v3 * move_vector->mVec128.m128_f32[2]);
    original_move_direction.mVec128.m128_f32[1] = v4;
    vostok::physics::bullet_character_controller::step_forward_impl(this, &original_move_direction, move_vector, 0);
  }
}
