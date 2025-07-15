vostok::collision::geometry_instance *__usercall vostok::collision::new_box_geometry_instance@<eax>(
        vostok::memory::base_allocator *allocator@<eax>,
        const vostok::math::float4x4 *matrix)
{
  char *v3; // eax
  char *v4; // eax
  int v5; // edx

  v3 = type_info::raw_name(&vostok::collision::box_geometry_instance `RTTI Type Descriptor');
  v4 = (char *)allocator->call_malloc(
                 allocator,
                 136,
                 v3,
                 "vostok::collision::new_box_geometry_instance",
                 ".\\api.cpp",
                 109);
  if ( !v4 )
    return 0;
  v4[4] = 1;
  *(_DWORD *)v4 = &vostok::collision::box_geometry_instance::`vftable';
  qmemcpy(v4 + 8, matrix, 0x40u);
  vostok::math::invert4x3(matrix, (vostok::math::float4x4 *)(v4 + 72));
  return (vostok::collision::geometry_instance *)v5;
}
