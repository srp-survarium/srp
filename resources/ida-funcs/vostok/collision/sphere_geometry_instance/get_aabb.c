vostok::math::aabb *__thiscall vostok::collision::sphere_geometry_instance::get_aabb(
        vostok::collision::sphere_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v4; // esi
  vostok::math::aabb *v5; // eax
  vostok::math::aabb v6; // [esp+0h] [ebp-30h] BYREF
  vostok::math::float3 v7; // [esp+18h] [ebp-18h] BYREF
  vostok::math::float3 v8; // [esp+24h] [ebp-Ch] BYREF

  v8.x = s_bm_current_air_resistance;
  v8.y = s_bm_current_air_resistance;
  v8.z = s_bm_current_air_resistance;
  memset(&v7, 0, sizeof(v7));
  vostok::math::create_aabb_center_radius(&v8, &v7, &v6);
  v4 = vostok::math::aabb::modify((vostok::math::aabb *)&this->m_matrix, &v6);
  v5 = result;
  qmemcpy(result, v4, sizeof(vostok::math::aabb));
  return v5;
}
