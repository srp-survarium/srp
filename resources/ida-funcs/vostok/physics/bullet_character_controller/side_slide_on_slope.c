bool __userpurge vostok::physics::bullet_character_controller::side_slide_on_slope@<al>(
        const btVector3 *move_vector@<eax>,
        const btVector3 *a2@<edi>,
        const btVector3 *a3@<esi>,
        const btVector3 *this,
        btVector3 *position_after_step_up,
        const btVector3 *pre_step_bottom_pos,
        float down_step,
        btVector3 *current_step_offset,
        btVector3 *in_out_normal,
        float *hit_fraction)
{
  float v10; // ecx
  bool result; // al

  result = s_cc_slide_on_impassabele_slope_value
        && (v10 = fabs(
                    (float)((float)(move_vector->mVec128.m128_f32[0] * move_vector->mVec128.m128_f32[0])
                          + (float)(move_vector->mVec128.m128_f32[1] * move_vector->mVec128.m128_f32[1]))
                  + (float)(move_vector->mVec128.m128_f32[2] * move_vector->mVec128.m128_f32[2])),
            v10 >= 0.0000099999997)
        && vostok::physics::bullet_character_controller::slide_in_impassable_case_impl(
             (vostok::physics::bullet_character_controller *)LODWORD(v10),
             a2,
             a3,
             this,
             move_vector,
             position_after_step_up,
             pre_step_bottom_pos,
             down_step,
             current_step_offset,
             in_out_normal,
             hit_fraction);
  return result;
}
