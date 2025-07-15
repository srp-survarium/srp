void *__thiscall vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator)
{
  return vostok::memory::doug_lea_allocator::malloc_impl(allocator, 0x10u);
}


void *__thiscall vostok::memory::new_helper<survarium::collision_geometry>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator)
{
  return vostok::memory::doug_lea_allocator::malloc_impl(allocator, 0x130u);
}


void *__cdecl vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::pthreads3_allocator>()
{
  return pt3malloc(0x10u);
}
