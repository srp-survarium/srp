vostok::math::float3 *__thiscall vostok::collision::composite_geometry_instance::get_closest_point_to(
        vostok::collision::composite_geometry_instance *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *point,
        const vostok::math::float4x4 *origin)
{
  vostok::math::float4x4 v6; // [esp+10h] [ebp-40h] BYREF

  vostok::math::mul4x3(&v6, origin, &this->m_matrix);
  vostok::collision::composite_geometry::get_closest_point_to(
    (vostok::collision::composite_geometry *)this->m_geometry,
    point,
    (const vostok::math::float4x4 *)result);
  return result;
}
