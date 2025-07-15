BOOL __usercall vostok::physics::bullet_character_controller::on_ground@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        float *a2@<eax>)
{
  return s_cc_on_ground_max_vertical_speed > fabs(
                                               (float)((float)(a2[309]
                                                             * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                                                     + (float)(a2[310]
                                                             * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
                                             + (float)(a2[308]
                                                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]));
}
