vostok::math::aabb *__userpurge vostok::collision::terrain_geometry_instance::get_geometry_aabb@<eax>(
        vostok::collision::terrain_geometry_instance *this@<ecx>,
        int a2@<xmm0>,
        vostok::math::aabb *result)
{
  vostok::collision::terrain_data *v3; // ecx
  vostok::math::aabb *v4; // eax
  __int64 v5; // [esp+Ch] [ebp-Ch]

  *(float *)&v5 = this->m_data.m_physical_size;
  vostok::collision::terrain_data::max_height((vostok::collision::terrain_data *)this);
  HIDWORD(v5) = a2;
  vostok::collision::terrain_data::min_height(v3);
  v4 = result;
  *(_QWORD *)&result->min.x = 0;
  *(_QWORD *)&result->max.x = v5;
  result->min.z = -*(float *)&v5;
  result->max.z = 0.0;
  return v4;
}
