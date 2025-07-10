vostok::math::aabb *__thiscall vostok::collision::truncated_sphere_geometry_instance::get_aabb(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax
  vostok::math::aabb v3; // [esp+0h] [ebp-24h]
  __int64 v4; // [esp+18h] [ebp-Ch]

  *(float *)&v4 = this->m_radius;
  HIDWORD(v4) = v4;
  LODWORD(v3.min.x) = v4 ^ 0x80000000;
  LODWORD(v3.min.y) = v4 ^ 0x80000000;
  LODWORD(v3.min.z) = v4 ^ 0x80000000;
  v2 = result;
  *(_QWORD *)&v3.max.x = v4;
  LODWORD(v3.max.z) = v4;
  *result = v3;
  return v2;
}
