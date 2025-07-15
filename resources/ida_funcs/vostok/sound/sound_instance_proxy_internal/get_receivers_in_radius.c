void __thiscall vostok::sound::sound_instance_proxy_internal::get_receivers_in_radius(
        vostok::sound::sound_instance_proxy_internal *this,
        vostok::collision::space_partitioning_tree *spatial_tree,
        const vostok::math::float3 *position,
        float radius,
        vostok::vectora<vostok::collision::object const *> *query_result)
{
  vostok::math::float3 v5; // [esp+50h] [ebp-24h] BYREF
  vostok::math::aabb aabb; // [esp+5Ch] [ebp-18h] BYREF

  v5.x = radius;
  v5.y = radius;
  v5.z = radius;
  vostok::math::create_aabb_center_radius(&aabb, position, &v5);
  spatial_tree->aabb_query(spatial_tree, 1u, &aabb, query_result);
}
