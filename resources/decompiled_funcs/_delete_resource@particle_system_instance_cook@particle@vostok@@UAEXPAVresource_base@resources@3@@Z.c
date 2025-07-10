void __thiscall vostok::particle::particle_system_instance_cook::delete_resource(
        vostok::particle::particle_system_instance_cook *this,
        vostok::particle::particle_system_instance *res)
{
  vostok::memory::pthreads3_allocator *v2; // eax
  vostok::particle::particle_system_instance *ps_instance; // [esp+14h] [ebp-4h] BYREF

  ps_instance = res;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::detail::delete_helper_impl<vostok::memory::pthreads3_allocator,vostok::particle::particle_system_instance,vostok::memory::detail::call_destructor_predicate>(
    v2,
    (vostok::sound::sound_order **)&ps_instance);
}
