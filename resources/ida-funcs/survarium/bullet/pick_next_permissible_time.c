float __userpurge survarium::bullet::pick_next_permissible_time@<xmm0>(
        survarium::bullet *this@<esi>,
        survarium::bullet *a2@<ecx>,
        float result@<xmm0>,
        float low_time,
        float high_time)
{
  survarium::bullet *v5; // eax
  const vostok::math::float3 *v6; // edx
  survarium::bullet *v7; // ecx
  float v8; // xmm0_4
  double v9; // st7
  survarium::bullet *v10; // ecx
  float v11; // xmm0_4
  float start_low; // [esp+4h] [ebp-18h]
  float i; // [esp+14h] [ebp-8h]
  float v14; // [esp+18h] [ebp-4h]
  float v15; // [esp+28h] [ebp+Ch]

  survarium::bullet::get_parabolic_time(a2);
  if ( low_time > result )
  {
    v8 = survarium::bullet::get_check_time_in_vacuum(v5, v6, low_time, LODWORD(high_time)).m128_f32[0];
    if ( high_time < v8 )
      return high_time;
    return v8;
  }
  if ( result > high_time )
  {
    v9 = high_time;
LABEL_6:
    start_low = v9;
    v11 = COERCE_FLOAT(survarium::bullet::get_check_time(v5, v7, low_time, start_low));
    goto LABEL_10;
  }
  v5 = this;
  if ( fabs(result - low_time) >= 0.0000099999997 )
  {
    v9 = result;
    goto LABEL_6;
  }
  LODWORD(v11) = survarium::bullet::get_check_time_in_vacuum(this, v6, result, LODWORD(high_time)).m128_u32[0];
LABEL_10:
  v15 = v11;
  for ( i = low_time; ; v11 = (float)(i + v15) * 0.5 )
  {
    v14 = v11;
    if ( fabs(i - v15) < 0.0000099999997 )
      break;
    if ( survarium::bullet::compute_max_error(this, v10, 0.0000099999997, low_time, v11) >= 0.050000001 )
      v15 = v14;
    else
      i = v14;
  }
  return i;
}
