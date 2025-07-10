vostok::math::aabb *__userpurge vostok::collision::terrain_geometry_instance::get_aabb@<eax>(
        vostok::collision::terrain_geometry_instance *this@<ecx>,
        const vostok::math::float4x4 *a2@<edi>,
        vostok::math::aabb *result)
{
  vostok::collision::terrain_data *v4; // ecx

  vostok::collision::terrain_data::max_height((vostok::collision::terrain_data *)this);
  vostok::collision::terrain_data::min_height(v4);
  *result = *vostok::math::aabb::modify((vostok::math::aabb *)&this->m_matrix, a2);
  return result;
}
