vostok::math::float4 *__userpurge vostok::math::curve_line_color::evaluate@<eax>(
        vostok::math::curve_line_color *this@<ecx>,
        int a2@<edi>,
        vostok::math::float4 *a3@<esi>,
        vostok::math::float4 *result,
        __int64 time,
        __int64 default_value_8,
        int a7,
        vostok::math::enum_evaluate_time_type time_type)
{
  vostok::math::float4_pod *v8; // eax
  double w; // st7
  vostok::math::float4 *v10; // eax
  float max_value; // [esp+4h] [ebp-40h]
  vostok::math::float4_pod v12; // [esp+8h] [ebp-3Ch]
  float left_range_alpha; // [esp+1Ch] [ebp-28h]
  float right_range_alpha; // [esp+20h] [ebp-24h]
  vostok::math::float4_pod v15; // [esp+24h] [ebp-20h] BYREF
  vostok::math::float4_pod resulta; // [esp+34h] [ebp-10h] BYREF

  right_range_alpha = 0.0;
  left_range_alpha = 0.0;
  *(_QWORD *)&v12.x = time;
  *(_QWORD *)&v12.elements[2] = default_value_8;
  if ( *(_DWORD *)(a2 + 56) )
  {
    max_value = vostok::math::random_float(*(float *)a2, *(float *)(a2 + 4));
    v8 = vostok::math::curve_line_points<vostok::math::float4_pod,1>::evaluate(
           (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)a2,
           &v15,
           max_value,
           v12,
           range_time_type,
           left_range_alpha,
           right_range_alpha);
  }
  else
  {
    v8 = vostok::math::curve_line_points<vostok::math::float4_pod,1>::evaluate(
           (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)a2,
           &resulta,
           *(float *)&result,
           v12,
           range_time_type,
           left_range_alpha,
           right_range_alpha);
  }
  a3->x = v8->x;
  a3->y = v8->y;
  a3->z = v8->z;
  w = v8->w;
  v10 = a3;
  a3->w = w;
  return v10;
}
