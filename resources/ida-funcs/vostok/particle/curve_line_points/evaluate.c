double __thiscall vostok::particle::curve_line_points<float,0>::evaluate(
        vostok::particle::curve_line_points<float,0> *this,
        float time,
        float default_value,
        vostok::particle::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  float dist; // [esp+2Ch] [ebp-20h]
  float a_value; // [esp+30h] [ebp-1Ch]
  vostok::particle::curve_point<float> *b; // [esp+34h] [ebp-18h]
  float b_value; // [esp+38h] [ebp-14h]
  vostok::particle::curve_point<float> *a; // [esp+3Ch] [ebp-10h]
  unsigned int i; // [esp+40h] [ebp-Ch]
  vostok::particle::curve_point<float> *last_point; // [esp+44h] [ebp-8h]
  vostok::particle::curve_point<float> *first_point; // [esp+48h] [ebp-4h]

  if ( !this->num_points )
    return default_value;
  first_point = this->points.pointer;
  last_point = &first_point[this->num_points - 1];
  if ( this->num_points == 1 )
    return vostok::particle::linear_interpolation<float>(
             first_point->lower_value,
             first_point->upper_value,
             left_range_alpha);
  if ( time_type == linear_time_type )
    time = vostok::particle::linear_interpolation<float>(this->curve_time_min, this->curve_time_max, time);
  if ( first_point->time >= time )
    return vostok::particle::linear_interpolation<float>(
             first_point->lower_value,
             first_point->upper_value,
             left_range_alpha);
  if ( time >= last_point->time )
    return vostok::particle::linear_interpolation<float>(
             last_point->lower_value,
             last_point->upper_value,
             right_range_alpha);
  for ( i = 1; i < this->num_points; ++i )
  {
    a = &this->points.pointer[i - 1];
    b = &this->points.pointer[i];
    if ( a->time <= time && time <= b->time )
    {
      dist = b->time - a->time;
      vostok::math::abs();
      if ( dist > 0.0000099999997 )
      {
        a_value = vostok::particle::linear_interpolation<float>(a->lower_value, a->upper_value, left_range_alpha);
        b_value = vostok::particle::linear_interpolation<float>(b->lower_value, b->upper_value, right_range_alpha);
        if ( a->interp_type == curve_interp_type )
          return vostok::particle::cubic_interpolation<float,float>(
                   a_value,
                   a->tangent_out,
                   b_value,
                   b->tangent_in,
                   (float)(time - a->time) / dist);
        if ( a->interp_type == linear_interp_type )
          return vostok::particle::linear_interpolation<float>(a_value, b_value, (float)(time - a->time) / dist);
      }
    }
  }
  return default_value;
}


vostok::math::float3_pod *__thiscall vostok::particle::curve_line_points<vostok::math::float3_pod,0>::evaluate(
        vostok::particle::curve_line_points<vostok::math::float3_pod,0> *this,
        vostok::math::float3_pod *result,
        float time,
        vostok::math::float3_pod default_value,
        vostok::particle::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  float v8; // xmm0_4
  vostok::math::float3_pod v10; // [esp+24h] [ebp-110h] BYREF
  vostok::math::float3_pod v11; // [esp+38h] [ebp-FCh]
  vostok::math::float3_pod v12; // [esp+44h] [ebp-F0h] BYREF
  vostok::math::float3_pod v13; // [esp+58h] [ebp-DCh]
  vostok::math::float3_pod v14; // [esp+64h] [ebp-D0h] BYREF
  vostok::math::float3_pod v15; // [esp+78h] [ebp-BCh]
  vostok::math::float3_pod v16; // [esp+84h] [ebp-B0h] BYREF
  vostok::math::float3_pod v17; // [esp+98h] [ebp-9Ch]
  vostok::math::float3_pod v18; // [esp+A4h] [ebp-90h] BYREF
  vostok::math::float3_pod v19; // [esp+B8h] [ebp-7Ch]
  vostok::math::float3_pod v20; // [esp+C4h] [ebp-70h] BYREF
  vostok::math::float3_pod v21; // [esp+D8h] [ebp-5Ch]
  vostok::math::float3_pod v22; // [esp+E4h] [ebp-50h] BYREF
  vostok::math::float3_pod v23; // [esp+F8h] [ebp-3Ch]
  float dist; // [esp+104h] [ebp-30h]
  vostok::math::float3_pod a_value; // [esp+108h] [ebp-2Ch]
  vostok::particle::curve_point<vostok::math::float3_pod> *b; // [esp+114h] [ebp-20h]
  vostok::math::float3_pod b_value; // [esp+118h] [ebp-1Ch]
  vostok::particle::curve_point<vostok::math::float3_pod> *a; // [esp+124h] [ebp-10h]
  unsigned int i; // [esp+128h] [ebp-Ch]
  vostok::particle::curve_point<vostok::math::float3_pod> *last_point; // [esp+12Ch] [ebp-8h]
  vostok::particle::curve_point<vostok::math::float3_pod> *first_point; // [esp+130h] [ebp-4h]

  if ( this->num_points )
  {
    first_point = this->points.pointer;
    last_point = &this->points.pointer[this->num_points - 1];
    if ( this->num_points == 1 )
    {
      v23 = *vostok::particle::linear_interpolation<vostok::math::float3_pod>(
               &v22,
               first_point->lower_value,
               first_point->upper_value,
               left_range_alpha);
      *result = v23;
      return result;
    }
    else
    {
      if ( time_type == linear_time_type )
        time = vostok::particle::linear_interpolation<float>(this->curve_time_min, this->curve_time_max, time);
      if ( first_point->time < time )
      {
        if ( time < last_point->time )
        {
          for ( i = 1; i < this->num_points; ++i )
          {
            a = &this->points.pointer[i - 1];
            b = &this->points.pointer[i];
            if ( a->time <= time && time <= b->time )
            {
              dist = b->time - a->time;
              v8 = dist;
              vostok::math::abs();
              if ( v8 > 0.0000099999997 )
              {
                v17 = *vostok::particle::linear_interpolation<vostok::math::float3_pod>(
                         &v16,
                         a->lower_value,
                         a->upper_value,
                         left_range_alpha);
                a_value = v17;
                v15 = *vostok::particle::linear_interpolation<vostok::math::float3_pod>(
                         &v14,
                         b->lower_value,
                         b->upper_value,
                         right_range_alpha);
                b_value = v15;
                if ( a->interp_type == curve_interp_type )
                {
                  v13 = *vostok::particle::cubic_interpolation<vostok::math::float3_pod,float>(
                           &v12,
                           a_value,
                           a->tangent_out,
                           b_value,
                           b->tangent_in,
                           (float)(time - a->time) / dist);
                  *result = v13;
                  return result;
                }
                if ( a->interp_type == linear_interp_type )
                {
                  v11 = *vostok::particle::linear_interpolation<vostok::math::float3_pod>(
                           &v10,
                           a_value,
                           b_value,
                           (float)(time - a->time) / dist);
                  *result = v11;
                  return result;
                }
              }
            }
          }
          *result = default_value;
          return result;
        }
        else
        {
          v19 = *vostok::particle::linear_interpolation<vostok::math::float3_pod>(
                   &v18,
                   last_point->lower_value,
                   last_point->upper_value,
                   right_range_alpha);
          *result = v19;
          return result;
        }
      }
      else
      {
        v21 = *vostok::particle::linear_interpolation<vostok::math::float3_pod>(
                 &v20,
                 first_point->lower_value,
                 first_point->upper_value,
                 left_range_alpha);
        *result = v21;
        return result;
      }
    }
  }
  else
  {
    *result = default_value;
    return result;
  }
}


vostok::math::float4_pod *__thiscall vostok::particle::curve_line_points<vostok::math::float4_pod,1>::evaluate(
        vostok::particle::curve_line_points<vostok::math::float4_pod,1> *this,
        vostok::math::float4_pod *result,
        float time,
        vostok::math::float4_pod default_value,
        vostok::particle::enum_evaluate_time_type time_type,
        float left_range_alpha,
        float right_range_alpha)
{
  float v8; // xmm0_4
  vostok::math::float4_pod v10; // [esp+24h] [ebp-118h] BYREF
  vostok::math::float4_pod v11; // [esp+34h] [ebp-108h]
  vostok::math::float4_pod v12; // [esp+44h] [ebp-F8h] BYREF
  vostok::math::float4_pod v13; // [esp+54h] [ebp-E8h]
  vostok::math::float4_pod v14; // [esp+64h] [ebp-D8h] BYREF
  vostok::math::float4_pod v15; // [esp+74h] [ebp-C8h]
  vostok::math::float4_pod v16; // [esp+84h] [ebp-B8h] BYREF
  vostok::math::float4_pod v17; // [esp+94h] [ebp-A8h]
  vostok::math::float4_pod v18; // [esp+A4h] [ebp-98h] BYREF
  vostok::math::float4_pod v19; // [esp+B4h] [ebp-88h]
  vostok::math::float4_pod v20; // [esp+C4h] [ebp-78h] BYREF
  vostok::math::float4_pod v21; // [esp+D4h] [ebp-68h]
  vostok::math::float4_pod v22; // [esp+E4h] [ebp-58h] BYREF
  vostok::math::float4_pod v23; // [esp+F4h] [ebp-48h]
  float dist; // [esp+104h] [ebp-38h]
  vostok::math::float4_pod a_value; // [esp+108h] [ebp-34h]
  vostok::particle::curve_point<vostok::math::float4_pod> *b; // [esp+118h] [ebp-24h]
  vostok::math::float4_pod b_value; // [esp+11Ch] [ebp-20h]
  vostok::particle::curve_point<vostok::math::float4_pod> *a; // [esp+12Ch] [ebp-10h]
  unsigned int i; // [esp+130h] [ebp-Ch]
  vostok::particle::curve_point<vostok::math::float4_pod> *last_point; // [esp+134h] [ebp-8h]
  vostok::particle::curve_point<vostok::math::float4_pod> *first_point; // [esp+138h] [ebp-4h]

  if ( this->num_points )
  {
    first_point = this->points.pointer;
    last_point = &this->points.pointer[this->num_points - 1];
    if ( this->num_points == 1 )
    {
      v23 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(
               &v22,
               first_point->lower_value,
               first_point->upper_value,
               left_range_alpha);
      *result = v23;
      return result;
    }
    else
    {
      if ( time_type == linear_time_type )
        time = vostok::particle::linear_interpolation<float>(this->curve_time_min, this->curve_time_max, time);
      if ( first_point->time < time )
      {
        if ( time < last_point->time )
        {
          for ( i = 1; i < this->num_points; ++i )
          {
            a = &this->points.pointer[i - 1];
            b = &this->points.pointer[i];
            if ( a->time <= time && time <= b->time )
            {
              dist = b->time - a->time;
              v8 = dist;
              vostok::math::abs();
              if ( v8 > 0.0000099999997 )
              {
                v17 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(
                         &v16,
                         a->lower_value,
                         a->upper_value,
                         left_range_alpha);
                a_value = v17;
                v15 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(
                         &v14,
                         b->lower_value,
                         b->upper_value,
                         right_range_alpha);
                b_value = v15;
                if ( a->interp_type == curve_interp_type )
                {
                  v13 = *vostok::particle::cubic_interpolation<vostok::math::float4_pod,float>(
                           &v12,
                           a_value,
                           a->tangent_out,
                           b_value,
                           b->tangent_in,
                           (float)(time - a->time) / dist);
                  *result = v13;
                  return result;
                }
                if ( a->interp_type == linear_interp_type )
                {
                  v11 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(
                           &v10,
                           a_value,
                           b_value,
                           (float)(time - a->time) / dist);
                  *result = v11;
                  return result;
                }
              }
            }
          }
          *result = default_value;
          return result;
        }
        else
        {
          v19 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(
                   &v18,
                   last_point->lower_value,
                   last_point->upper_value,
                   right_range_alpha);
          *result = v19;
          return result;
        }
      }
      else
      {
        v21 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(
                 &v20,
                 first_point->lower_value,
                 first_point->upper_value,
                 left_range_alpha);
        *result = v21;
        return result;
      }
    }
  }
  else
  {
    *result = default_value;
    return result;
  }
}
