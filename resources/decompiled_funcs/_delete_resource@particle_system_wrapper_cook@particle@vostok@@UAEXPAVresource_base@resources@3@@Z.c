void __thiscall vostok::particle::particle_system_wrapper_cook::delete_resource(
        vostok::particle::particle_system_wrapper_cook *this,
        vostok::resources::resource_base *resource)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::base_allocator *v3; // eax

  vostok::resources::unmanaged_allocator();
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(v3, &resource);
}
