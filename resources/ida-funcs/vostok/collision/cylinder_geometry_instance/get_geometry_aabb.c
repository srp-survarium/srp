vostok::math::aabb *__thiscall vostok::collision::cylinder_geometry_instance::get_geometry_aabb(
        vostok::collision::cylinder_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax
  const vostok::math::float4x4 *v3; // edx
  __int64 v4; // [esp+Ch] [ebp-Ch]

  v2 = result;
  v3 = clear_value;
  LODWORD(v4) = clear_value;
  HIDWORD(v4) = clear_value;
  *(_QWORD *)&result->min.x = 0xBF800000BF800000uLL;
  *(_QWORD *)&result->max.x = v4;
  result->min.z = -1.0;
  LODWORD(result->max.z) = v3;
  return v2;
}
