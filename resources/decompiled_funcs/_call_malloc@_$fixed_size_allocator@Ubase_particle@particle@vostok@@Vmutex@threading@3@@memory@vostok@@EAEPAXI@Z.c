void *__thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::call_malloc(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        unsigned int size)
{
  _BYTE *v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(size == 208));
  return vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::allocate(this);
}
