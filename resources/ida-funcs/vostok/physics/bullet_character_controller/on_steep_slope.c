BOOL __usercall vostok::physics::bullet_character_controller::on_steep_slope@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        float *a2@<eax>)
{
  return vostok::physics::bullet_character_controller::ms_max_slope_normal_dot > (float)((float)((float)(a2[293] * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
                                                                                               + (float)(a2[294] * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
                                                                                       + (float)(a2[292]
                                                                                               * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]));
}
