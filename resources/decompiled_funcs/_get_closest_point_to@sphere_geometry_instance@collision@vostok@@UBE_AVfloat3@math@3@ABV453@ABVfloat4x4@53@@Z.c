vostok::math::float3 *__thiscall vostok::collision::sphere_geometry_instance::get_closest_point_to(
        vostok::collision::sphere_geometry_instance *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *point,
        const vostok::math::float4x4 *origin)
{
  vostok::math::float3 *v4; // eax
  float z; // edx
  long double v6; // st7
  float v7; // ecx
  float _X; // [esp+8h] [ebp-5Ch]
  float v9; // [esp+8h] [ebp-5Ch]
  float direction; // [esp+Ch] [ebp-58h]
  float direction_4; // [esp+10h] [ebp-54h]
  float direction_4a; // [esp+10h] [ebp-54h]
  float direction_8; // [esp+14h] [ebp-50h]
  float direction_8a; // [esp+14h] [ebp-50h]
  __int64 resulta; // [esp+18h] [ebp-4Ch]
  vostok::math::float4x4 transform; // [esp+24h] [ebp-40h] BYREF

  vostok::math::mul4x3(&transform, origin, &this->m_matrix);
  direction_4 = point->y - transform.c.y;
  direction_8 = point->z - transform.c.z;
  direction = point->x - transform.c.x;
  _X = (float)((float)(direction_4 * direction_4) + (float)(direction_8 * direction_8)) + (float)(direction * direction);
  if ( *(float *)&clear_value <= _X )
  {
    v6 = 1.0 / sqrtf(_X);
    v9 = v6;
    direction_4a = direction_4 * v6;
    direction_8a = v6 * direction_8;
    *((float *)&resulta + 1) = transform.c.y + direction_4a;
    v4 = result;
    v7 = transform.c.z + direction_8a;
    *(float *)&resulta = transform.c.x + (float)(v9 * direction);
    *(_QWORD *)&result->x = resulta;
    result->z = v7;
  }
  else
  {
    v4 = result;
    z = point->z;
    *(_QWORD *)&result->x = *(_QWORD *)&point->x;
    result->z = z;
  }
  return v4;
}
