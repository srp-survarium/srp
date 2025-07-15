vostok::math::aabb *__thiscall vostok::collision::truncated_sphere_geometry_instance::get_geometry_aabb(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax
  __int64 v3; // [esp+0h] [ebp-18h]
  __int64 v4; // [esp+Ch] [ebp-Ch]

  v2 = result;
  *(float *)&v4 = this->m_radius;
  HIDWORD(v4) = v4;
  LODWORD(v3) = v4 ^ 0x80000000;
  HIDWORD(v3) = v4 ^ 0x80000000;
  *(_QWORD *)&result->min.x = v3;
  *(_QWORD *)&result->max.x = v4;
  LODWORD(result->min.z) = v4 ^ 0x80000000;
  LODWORD(result->max.z) = v4;
  return v2;
}
