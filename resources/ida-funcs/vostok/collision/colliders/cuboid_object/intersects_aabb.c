int __fastcall vostok::collision::colliders::cuboid_object::intersects_aabb(
        const vostok::math::float3 *aabb_extents,
        const vostok::math::float3 *aabb_center,
        vostok::collision::colliders::cuboid_object *this)
{
  vostok::math::aabb_plane *v3; // eax
  vostok::math::cuboid *v5; // [esp-4h] [ebp-20h]
  vostok::math::aabb v6; // [esp+0h] [ebp-1Ch] BYREF

  v3 = (vostok::math::aabb_plane *)vostok::math::create_aabb_center_radius(aabb_extents, aabb_center, &v6);
  return vostok::math::cuboid::test_inexact(v5, (int)this->m_cuboid, v3);
}
