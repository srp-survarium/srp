float __thiscall vostok::animation::fermi_interpolator::interpolated_value(
        vostok::animation::fermi_interpolator *this,
        float current_transition_time)
{
  long double v4; // [esp+0h] [ebp-10h]
  float v5; // [esp+0h] [ebp-10h]

  __libm_sse2_log(v4);
  return expf(v5);
}
