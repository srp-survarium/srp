void __thiscall vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>>::destroy(
        vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> > *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_variable);
  this->m_initialized = 0;
}
