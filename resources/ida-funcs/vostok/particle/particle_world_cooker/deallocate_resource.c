void __thiscall vostok::particle::particle_world_cooker::deallocate_resource(
        vostok::particle::particle_world_cooker *this,
        void *buffer)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::base_allocator *v3; // eax

  vostok::resources::unmanaged_allocator();
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::memory::free_helper<vostok::memory::base_allocator,char>(v3, (char **)&buffer);
}
