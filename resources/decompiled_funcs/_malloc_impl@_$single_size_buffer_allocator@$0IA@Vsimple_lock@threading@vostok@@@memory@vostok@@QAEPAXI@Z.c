void *__thiscall vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::malloc_impl(
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *this,
        unsigned int size)
{
  _BYTE *v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(size == 128));
  return vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::allocate(this);
}
