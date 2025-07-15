void __usercall vostok::physics::bullet_character_controller::end_jump(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm4_4

  *(_BYTE *)(a2 + 1164) = 0;
  v2 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1];
  v3 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2];
  v4 = (float)((float)(*(float *)(a2 + 1236)
                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1])
             + (float)(*(float *)(a2 + 1240)
                     * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]))
     + (float)(*(float *)(a2 + 1232) * vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]);
  if ( v4 >= 0.0 )
    v4 = 0.0;
  *(float *)(a2 + 1232) = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * v4;
  *(float *)(a2 + 1236) = v2 * v4;
  *(float *)(a2 + 1240) = v3 * v4;
  *(_DWORD *)(a2 + 1244) = 0;
}
