vostok::math::float4_pod *__thiscall vostok::math::curve_line_points<vostok::math::float4_pod,1>::evaluate(
        vostok::math::curve_line_points<vostok::math::float4_pod,1> *this,
        vostok::math::float4_pod *result,
        float time,
        vostok::math::float4_pod default_value,
        vostok::math::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  unsigned int num_points; // edx
  vostok::math::curve_point<vostok::math::float4_pod> *pointer; // eax
  vostok::math::float4_pod *p_upper_value; // esi
  __int64 v10; // xmm0_8
  vostok::math::float4_pod *v11; // eax
  unsigned int v12; // xmm4_4
  unsigned int v13; // xmm3_4
  float v14; // xmm1_4
  vostok::math::float4_pod *v15; // eax
  unsigned int v16; // ecx
  vostok::math::curve_point<vostok::math::float4_pod> *v17; // edi
  float *p_time; // esi
  float v19; // xmm2_4
  float v20; // xmm0_4
  vostok::math::float4_pod *v21; // ebx
  vostok::math::float4_pod *v22; // eax
  vostok::math::float4_pod lower_value; // [esp-20h] [ebp-5Ch]
  vostok::math::float4_pod v24; // [esp-10h] [ebp-4Ch]
  float alpha; // [esp+0h] [ebp-3Ch]
  float dist; // [esp+10h] [ebp-2Ch]
  vostok::math::float4_pod upper_value; // [esp+1Ch] [ebp-20h] BYREF
  vostok::math::float4_pod v28; // [esp+2Ch] [ebp-10h] BYREF

  num_points = this->num_points;
  if ( num_points )
  {
    pointer = this->points.pointer;
    p_upper_value = &pointer[num_points - 1].upper_value;
    if ( num_points == 1 )
    {
      upper_value = pointer->upper_value;
      *(_QWORD *)&v28.x = *(_QWORD *)&pointer->lower_value.x;
      v10 = *(_QWORD *)&pointer->lower_value.elements[2];
      v11 = result;
      *(float *)&v12 = (float)(*((float *)&v10 + 1) * (float)(*(float *)&clear_value - left_range_alpha))
                     + (float)(upper_value.w * left_range_alpha);
      v28.x = (float)(v28.x * (float)(*(float *)&clear_value - left_range_alpha))
            + (float)(upper_value.x * left_range_alpha);
      v28.y = (float)(v28.y * (float)(*(float *)&clear_value - left_range_alpha))
            + (float)(upper_value.y * left_range_alpha);
      *(float *)&v13 = (float)(*(float *)&v10 * (float)(*(float *)&clear_value - left_range_alpha))
                     + (float)(upper_value.z * left_range_alpha);
      *(_QWORD *)&result->x = *(_QWORD *)&v28.x;
      *(_QWORD *)&result->elements[2] = __PAIR64__(v12, v13);
      return v11;
    }
    if ( time_type )
    {
      v14 = time;
    }
    else
    {
      v14 = (float)((float)(*(float *)&clear_value - time) * this->curve_time_min)
          + (float)(this->curve_time_max * time);
      time = v14;
    }
    if ( pointer->time < v14 )
    {
      if ( v14 >= p_upper_value[4].x )
      {
        v15 = vostok::math::linear_interpolation<vostok::math::float4_pod>(
                &v28,
                p_upper_value[1],
                *p_upper_value,
                right_range_alpha);
        goto LABEL_10;
      }
      v16 = 1;
      v17 = pointer + 1;
      p_time = &pointer->time;
      while ( 1 )
      {
        v19 = *p_time;
        if ( *p_time <= v14 )
        {
          v20 = p_time[18];
          if ( v14 <= v20 )
          {
            dist = v20 - v19;
            if ( fabs(v20 - v19) > 0.0000099999997 )
              break;
          }
        }
        ++v16;
        ++v17;
        p_time += 18;
        if ( v16 >= num_points )
          goto LABEL_19;
      }
      v21 = vostok::math::linear_interpolation<vostok::math::float4_pod>(
              &v28,
              *(vostok::math::float4_pod *)(p_time - 12),
              *(vostok::math::float4_pod *)(p_time - 16),
              left_range_alpha);
      v22 = vostok::math::linear_interpolation<vostok::math::float4_pod>(
              &upper_value,
              v17->lower_value,
              v17->upper_value,
              right_range_alpha);
      if ( *((_DWORD *)p_time + 1) || v17->interp_type )
      {
        v15 = vostok::math::cubic_interpolation<vostok::math::float4_pod,float>(
                &v28,
                *v21,
                *(vostok::math::float4_pod *)(p_time - 4),
                *v22,
                v17->tangent_in,
                (float)(time - *p_time) / dist);
        goto LABEL_10;
      }
      alpha = (float)(time - *p_time) / dist;
      v24 = *v22;
      lower_value = *v21;
    }
    else
    {
      alpha = left_range_alpha;
      v24 = pointer->upper_value;
      lower_value = pointer->lower_value;
    }
    v15 = vostok::math::linear_interpolation<vostok::math::float4_pod>(&v28, lower_value, v24, alpha);
LABEL_10:
    *result = *v15;
    return result;
  }
LABEL_19:
  v11 = result;
  *result = default_value;
  return v11;
}
