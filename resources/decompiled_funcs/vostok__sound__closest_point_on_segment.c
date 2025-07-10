vostok::math::float3 *__cdecl vostok::sound::closest_point_on_segment(
        vostok::math::float3 *result,
        const vostok::math::float3 *point,
        const vostok::math::float3 *segment_origin,
        SpeedTree::Vec3 *segment_displacement)
{
  float v5; // [esp+0h] [ebp-6Ch]
  __int64 v6; // [esp+8h] [ebp-64h]
  float v7; // [esp+1Ch] [ebp-50h]
  float domen_value; // [esp+68h] [ebp-4h]

  v5 = (float)((float)((float)(point->x - segment_origin->x) * segment_displacement->x)
             + (float)((float)(point->y - segment_origin->y) * segment_displacement->y))
     + (float)((float)(point->z - segment_origin->z) * segment_displacement->z);
  domen_value = v5 / vostok::math::float3_pod::squared_length(segment_displacement);
  if ( domen_value > 0.0 )
  {
    if ( domen_value > 1.0 )
      v7 = FLOAT_1_0;
    else
      v7 = domen_value;
  }
  else
  {
    v7 = *(float *)&FLOAT_0_0;
  }
  *(float *)&v6 = segment_origin->y + (float)(segment_displacement->y * v7);
  *((float *)&v6 + 1) = segment_origin->z + (float)(segment_displacement->z * v7);
  result->x = segment_origin->x + (float)(segment_displacement->x * v7);
  *(_QWORD *)&result->elements[1] = v6;
  return result;
}
