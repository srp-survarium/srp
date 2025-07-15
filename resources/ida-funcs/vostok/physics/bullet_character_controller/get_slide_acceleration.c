btVector3 *__userpurge vostok::physics::bullet_character_controller::get_slide_acceleration@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        btVector3 *a2@<eax>,
        btVector3 *result)
{
  btVector3 *slope_slide_vector; // eax
  btVector3 *v5; // eax
  unsigned __int64 v6; // [esp+14h] [ebp-20h]
  float v7; // [esp+1Ch] [ebp-18h]
  btVector3 v8; // [esp+24h] [ebp-10h] BYREF

  if ( vostok::physics::bullet_character_controller::on_steep_slope(this, a2->mVec128.m128_f32) )
  {
    slope_slide_vector = vostok::physics::get_slope_slide_vector(
                           a2 + 73,
                           &v8,
                           COERCE_CONST_BTVECTOR3_(a2[72].mVec128.m128_f32[2]));
    *(float *)&v6 = slope_slide_vector->mVec128.m128_f32[0] * s_cc_slide_coefficient_value;
    *((float *)&v6 + 1) = slope_slide_vector->mVec128.m128_f32[1] * s_cc_slide_coefficient_value;
    v7 = slope_slide_vector->mVec128.m128_f32[2] * s_cc_slide_coefficient_value;
  }
  else
  {
    v6 = 0;
    v7 = 0.0;
  }
  v5 = result;
  result->mVec128.m128_u64[0] = v6;
  result->mVec128.m128_u64[1] = LODWORD(v7);
  return v5;
}
