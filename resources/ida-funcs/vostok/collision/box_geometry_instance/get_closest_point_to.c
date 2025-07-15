vostok::math::float3 *__thiscall vostok::collision::box_geometry_instance::get_closest_point_to(
        vostok::collision::box_geometry_instance *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *source,
        const vostok::math::float4x4 *origin)
{
  float z; // edx
  float _X; // xmm1_4
  int v6; // edi
  vostok::math::float4x4 *p_transform; // ebx
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm4_4
  float v12; // [esp+14h] [ebp-68h]
  __int64 axis; // [esp+18h] [ebp-64h]
  float axis_8; // [esp+20h] [ebp-5Ch]
  float dir; // [esp+24h] [ebp-58h]
  float dir_4; // [esp+28h] [ebp-54h]
  float dir_8; // [esp+2Ch] [ebp-50h]
  vostok::math::float3 half_sides; // [esp+30h] [ebp-4Ch]
  vostok::math::float4x4 transform; // [esp+3Ch] [ebp-40h] BYREF

  vostok::math::mul4x3(&transform, origin, &this->m_matrix);
  z = transform.c.z;
  dir = source->x - transform.c.x;
  dir_4 = source->y - transform.c.y;
  dir_8 = source->z - transform.c.z;
  *(_QWORD *)&result->x = *(_QWORD *)&transform.lines[3].x;
  _X = (float)((float)(transform.i.z * transform.i.z) + (float)(transform.i.y * transform.i.y))
     + (float)(transform.i.x * transform.i.x);
  result->z = z;
  half_sides.x = sqrtf(_X);
  half_sides.y = sqrtf(
                   (float)((float)(transform.j.z * transform.j.z) + (float)(transform.j.x * transform.j.x))
                 + (float)(transform.j.y * transform.j.y));
  half_sides.z = sqrtf(
                   (float)((float)(transform.k.x * transform.k.x) + (float)(transform.k.y * transform.k.y))
                 + (float)(transform.k.z * transform.k.z));
  v6 = 0;
  p_transform = &transform;
  do
  {
    axis = *(_QWORD *)&p_transform->i.x;
    axis_8 = p_transform->i.z;
    v12 = 1.0
        / sqrtf(
            (float)((float)(axis_8 * axis_8) + (float)(*((float *)&axis + 1) * *((float *)&axis + 1)))
          + (float)(p_transform->i.x * p_transform->i.x));
    v8 = (float)((float)((float)(axis_8 * v12) * dir_8) + (float)((float)(*((float *)&axis + 1) * v12) * dir_4))
       + (float)((float)(v12 * *(float *)&axis) * dir);
    v9 = *(&half_sides.x + v6);
    if ( v8 > v9 )
      v8 = *(&half_sides.x + v6);
    v10 = -v9;
    if ( v10 > v8 )
      v8 = v10;
    result->x = result->x + (float)((float)(v12 * *(float *)&axis) * v8);
    result->y = result->y + (float)((float)(*((float *)&axis + 1) * v12) * v8);
    ++v6;
    p_transform = (vostok::math::float4x4 *)((char *)p_transform + 16);
    result->z = result->z + (float)((float)(axis_8 * v12) * v8);
  }
  while ( v6 < 3 );
  return result;
}
