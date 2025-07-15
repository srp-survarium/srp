void *__usercall vostok::memory::new_helper<vostok::animation::EtCurve>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<esi>,
        const char *const function)
{
  char *v2; // eax

  v2 = type_info::raw_name(&vostok::animation::EtCurve `RTTI Type Descriptor');
  return allocator->call_malloc(
           allocator,
           84,
           v2,
           "vostok::animation::anm_track::initialize_empty",
           ".\\anim_track.cpp",
           function);
}


void *__usercall vostok::memory::new_helper<vostok::physics::bt_collision_shape>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<esi>,
        const char *function,
        const char *const file)
{
  char *v3; // eax

  v3 = type_info::raw_name(&vostok::physics::bt_collision_shape `RTTI Type Descriptor');
  return allocator->call_malloc(allocator, 280, v3, function, ".\\collision_shapes.cpp", file);
}


void *__usercall vostok::memory::new_helper<vostok::render::debug::draw_lines_command>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<esi>,
        const char *function,
        const char *const file)
{
  char *v3; // eax

  v3 = type_info::raw_name(&vostok::render::debug::draw_lines_command `RTTI Type Descriptor');
  return allocator->call_malloc(allocator, 10360, v3, function, ".\\debug_renderer.cpp", file);
}


void *__usercall vostok::memory::new_helper<vostok::render::debug::draw_triangles_command>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<esi>,
        const char *function,
        const char *const file)
{
  char *v3; // eax

  v3 = type_info::raw_name(&vostok::render::debug::draw_triangles_command `RTTI Type Descriptor');
  return allocator->call_malloc(allocator, 18552, v3, function, ".\\debug_renderer.cpp", file);
}


void *__usercall vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<esi>,
        const char *function,
        const char *const file)
{
  char *v3; // eax

  v3 = type_info::raw_name(&vostok::render::functor_command `RTTI Type Descriptor');
  return allocator->call_malloc(allocator, 152, v3, function, ".\\scene_renderer.cpp", file);
}


void *__usercall vostok::memory::new_helper<vostok::sound::sound_instance_proxy_order>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<esi>,
        const char *function,
        const char *const file)
{
  char *v3; // eax

  v3 = type_info::raw_name(&vostok::sound::sound_instance_proxy_order `RTTI Type Descriptor');
  return allocator->call_malloc(allocator, 56, v3, function, ".\\sound_instance_proxy_internal.cpp", file);
}
