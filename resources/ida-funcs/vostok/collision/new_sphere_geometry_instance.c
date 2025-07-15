vostok::collision::geometry_instance *__cdecl vostok::collision::new_sphere_geometry_instance(
        vostok::memory::base_allocator *matrix)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v2; // eax
  vostok::collision::geometry_instance *result; // eax

  v1 = vostok::render::g_allocator;
  v2 = type_info::raw_name(&vostok::collision::sphere_geometry_instance `RTTI Type Descriptor');
  result = (vostok::collision::geometry_instance *)v1->call_malloc(
                                                     v1,
                                                     72u,
                                                     v2,
                                                     "vostok::collision::new_sphere_geometry_instance",
                                                     ".\\api.cpp",
                                                     118u);
  if ( !result )
    return 0;
  result->m_delete_by_collision_object = 1;
  result->__vftable = (vostok::collision::geometry_instance_vtbl *)&vostok::collision::sphere_geometry_instance::`vftable';
  qmemcpy(&result[1], matrix, 0x40u);
  return result;
}
