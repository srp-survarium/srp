void __cdecl vostok::collision::new_box_geometry_instance(
        vostok::memory::base_allocator *allocator,
        const vostok::math::float4x4 *matrix)
{
  vostok::collision::box_geometry_instance *v2; // eax
  int v3; // ecx

  v2 = (vostok::collision::box_geometry_instance *)allocator->call_malloc(allocator, 136);
  if ( v2 )
    vostok::collision::box_geometry_instance::box_geometry_instance(v3, matrix, v2);
}
