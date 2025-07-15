vostok::math::aabb *__thiscall vostok::collision::box_geometry_instance::get_geometry_aabb(
        vostok::collision::sphere_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::float3 v3; // [esp+0h] [ebp-18h] BYREF
  vostok::math::float3 v4; // [esp+Ch] [ebp-Ch] BYREF

  v4.x = s_bm_current_air_resistance;
  v4.y = s_bm_current_air_resistance;
  v4.z = s_bm_current_air_resistance;
  memset(&v3, 0, sizeof(v3));
  vostok::math::create_aabb_center_radius(&v4, &v3, result);
  return result;
}
