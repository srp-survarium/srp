double __thiscall vostok::sound::encoded_sound_with_qualities_cook::satisfaction_with(
        vostok::sound::encoded_sound_with_qualities_cook *this,
        unsigned int quality_level,
        const vostok::math::float4x4 *user_matrix,
        unsigned int users_count)
{
  if ( quality_level == -1 )
    return 0.0;
  else
    return (double)(2 - quality_level) * 0.5;
}
