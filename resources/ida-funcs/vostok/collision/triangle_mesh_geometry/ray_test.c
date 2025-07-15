char __thiscall vostok::collision::triangle_mesh_geometry::ray_test(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  vostok::collision::colliders::ray_test_geometry *v6; // ecx
  char v8; // [esp+2h] [ebp-56h] BYREF
  vostok::collision::colliders::geometry::vertical_predicate<1> predicate; // [esp+3h] [ebp-55h] BYREF
  int v10; // [esp+4h] [ebp-54h]
  _DWORD v11[2]; // [esp+8h] [ebp-50h] BYREF
  _DWORD v12[2]; // [esp+10h] [ebp-48h] BYREF
  vostok::collision::colliders::ray_aabb_collider v13; // [esp+18h] [ebp-40h] BYREF
  vostok::collision::triangle_mesh_geometry *v14; // [esp+48h] [ebp-10h]
  _DWORD *v15; // [esp+4Ch] [ebp-Ch]
  float v16; // [esp+50h] [ebp-8h]
  char v17; // [esp+54h] [ebp-4h]

  *distance = max_distance;
  v11[0] = distance;
  v11[1] = &v8;
  v8 = 0;
  v12[1] = vostok::collision::helper::predicate;
  v12[0] = v11;
  vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(&v13, direction, origin);
  v15 = v12;
  v10 = LODWORD(v13.m_direction.y) & 0x7FFFFFFF;
  v14 = this;
  v16 = max_distance;
  v17 = 0;
  predicate = 0;
  if ( COERCE_FLOAT(LODWORD(v13.m_direction.y) & 0x7FFFFFFF) == s_bm_current_air_resistance )
    vostok::collision::colliders::ray_test_geometry::query<vostok::collision::colliders::geometry::vertical_predicate<1>>(
      v6,
      this->m_root,
      &predicate);
  else
    vostok::collision::colliders::ray_test_geometry::query<vostok::collision::colliders::geometry::vertical_predicate<0>>(
      v6,
      this->m_root,
      (const vostok::collision::colliders::geometry::vertical_predicate<0> *)&predicate);
  return v8;
}
