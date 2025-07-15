void *__thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::allocate(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::allocate(this->m_allocator.m_variable);
}
