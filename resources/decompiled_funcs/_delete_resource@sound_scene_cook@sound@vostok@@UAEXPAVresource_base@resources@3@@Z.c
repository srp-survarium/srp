void __thiscall vostok::sound::sound_scene_cook::delete_resource(
        vostok::sound::sound_scene_cook *this,
        vostok::sound::sound_scene *resource)
{
  vostok::sound::sound_scene *scene; // [esp+14h] [ebp-4h] BYREF

  scene = resource;
  vostok::sound::sound_scene::clear_resources(resource);
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
    &scene);
}
