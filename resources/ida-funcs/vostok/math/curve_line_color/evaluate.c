vostok::math::float4 *__thiscall vostok::math::curve_line_color::evaluate(
        vostok::math::curve_line_color *this,
        vostok::math::float4 *result,
        vostok::math::float4 *time,
        vostok::math::float4 default_value,
        unsigned int time_type)
{
  vostok::math::float4_pod *v6; // eax
  double w; // st7
  vostok::math::float4 *v8; // eax
  vostok::math::curve_line_points<vostok::math::float4_pod,1> *v9; // [esp+0h] [ebp-4Ch]
  float v10; // [esp+4h] [ebp-48h]
  vostok::math::float4_pod v11; // [esp+8h] [ebp-44h]
  vostok::math::enum_evaluate_time_type v12; // [esp+18h] [ebp-34h]
  float v13; // [esp+1Ch] [ebp-30h]
  float v14; // [esp+20h] [ebp-2Ch]
  vostok::math::float4_pod v15; // [esp+28h] [ebp-24h] BYREF
  vostok::math::float4_pod v16; // [esp+38h] [ebp-14h] BYREF

  *(_QWORD *)&v11.x = *(_QWORD *)&default_value.elements[1];
  *(_QWORD *)&v11.elements[2] = __PAIR64__(time_type, LODWORD(default_value.w));
  if ( LODWORD(result[3].z) )
  {
    v10 = vostok::math::random_float(result->x, result->y);
    v6 = vostok::math::curve_line_points<vostok::math::float4_pod,1>::evaluate(
           v9,
           (int)result,
           &v16,
           v10,
           v11,
           v12,
           v13,
           v14);
  }
  else
  {
    v6 = vostok::math::curve_line_points<vostok::math::float4_pod,1>::evaluate(
           (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)&v15,
           (int)result,
           &v15,
           default_value.x,
           v11,
           v12,
           v13,
           v14);
  }
  time->x = v6->x;
  time->y = v6->y;
  time->z = v6->z;
  w = v6->w;
  v8 = time;
  time->w = w;
  return v8;
}
