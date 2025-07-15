BOOL __userpurge vostok::physics::bullet_character_controller::impassable_slope@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>,
        const btVector3 *pre_step_bottom_pos,
        const btVector3 *a4,
        const btVector3 *a5)
{
  float v5; // xmm0_4
  float v7[4]; // [esp+10h] [ebp-10h] BYREF

  vostok::physics::capsule_center_to_bottom_position(
    (const btVector3 *)(a2 + 64),
    (const btCapsuleShape *)(a2 + 416),
    (int)v7);
  v5 = (float)((float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0]
                     * (float)(v7[0] - pre_step_bottom_pos->mVec128.m128_f32[0]))
             + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1]
                     * (float)(v7[1] - pre_step_bottom_pos->mVec128.m128_f32[1])))
     + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2]
             * (float)(v7[2] - pre_step_bottom_pos->mVec128.m128_f32[2]));
  return fabs(v5) >= 0.0000099999997 && v5 > 0.0;
}
