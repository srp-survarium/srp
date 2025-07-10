double __thiscall survarium::bullet::compute_max_error(
        survarium::bullet *this,
        float low,
        float high,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3_pod *v4; // ecx
  vostok::math::float3 *v5; // eax
  float v6; // xmm0_4
  vostok::math::float3 v9; // [esp+1Ch] [ebp-58h] BYREF
  vostok::math::float3 start_to_target; // [esp+28h] [ebp-4Ch] BYREF
  vostok::math::float3 target; // [esp+34h] [ebp-40h] BYREF
  vostok::math::float3 start; // [esp+40h] [ebp-34h] BYREF
  vostok::math::float3 start_to_max_error; // [esp+4Ch] [ebp-28h] BYREF
  float max_error_time; // [esp+58h] [ebp-1Ch]
  float magnitude; // [esp+5Ch] [ebp-18h]
  float cosine_alpha; // [esp+60h] [ebp-14h] BYREF
  vostok::math::float3 max_error; // [esp+64h] [ebp-10h] BYREF
  float sine_alpha; // [esp+70h] [ebp-4h]

  max_error_time = (float)(high + low) * 0.5;
  survarium::bullet::compute_trajectory_position(this, &start, low, gravity);
  survarium::bullet::compute_trajectory_position(this, &target, high, gravity);
  survarium::bullet::compute_trajectory_position(this, &max_error, max_error_time, gravity);
  vostok::math::operator-(&start, &max_error, &start_to_max_error);
  magnitude = vostok::math::float3_pod::length(v4, &start_to_max_error.x);
  vostok::math::float3_pod::operator*=(&start_to_max_error.x, *(float *)&clear_value / magnitude);
  v5 = vostok::math::operator-(&start, &target, &v9);
  start_to_target = *vostok::math::float3_pod::normalize(v5);
  vostok::math::operator|(&start_to_max_error, &start_to_target);
  vostok::math::min();
  vostok::math::max();
  cosine_alpha = -1.0;
  v6 = vostok::math::sqr<float>(&cosine_alpha);
  sine_alpha = vostok::math::sqrt(*(float *)&clear_value - v6);
  return magnitude * sine_alpha;
}
