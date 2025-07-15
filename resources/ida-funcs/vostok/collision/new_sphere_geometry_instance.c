vostok::collision::geometry_instance *__cdecl vostok::collision::new_sphere_geometry_instance(
        const vostok::math::float4x4 *matrix)
{
  vostok::collision::geometry_instance *result; // eax

  result = (vostok::collision::geometry_instance *)((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
                                                     vostok::render::g_allocator.m_object,
                                                     72);
  if ( !result )
    return 0;
  result->m_delete_by_collision_object = 1;
  result->__vftable = (vostok::collision::geometry_instance_vtbl *)&vostok::collision::sphere_geometry_instance::`vftable';
  qmemcpy(&result[1], matrix, 0x40u);
  return result;
}
