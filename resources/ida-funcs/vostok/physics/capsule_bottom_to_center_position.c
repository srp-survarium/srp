btVector3 *__usercall vostok::physics::capsule_bottom_to_center_position@<eax>(
        const btVector3 *bottom_position@<edi>,
        const btCapsuleShape *shape@<esi>,
        int a3@<ecx>)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm3_4

  v3 = shape->m_implicitShapeDimensions.mVec128.m128_f32[(shape->m_upAxis + 2) % 3]
     + shape->m_implicitShapeDimensions.mVec128.m128_f32[shape->m_upAxis];
  v4 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[1] * v3;
  v5 = vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[2] * v3;
  *(float *)a3 = bottom_position->mVec128.m128_f32[0]
               + (float)(vostok::physics::bullet_character_controller::ms_up_vector.mVec128.m128_f32[0] * v3);
  *(float *)(a3 + 4) = bottom_position->mVec128.m128_f32[1] + v4;
  *(float *)(a3 + 8) = bottom_position->mVec128.m128_f32[2] + v5;
  *(_DWORD *)(a3 + 12) = 0;
  return (btVector3 *)a3;
}
