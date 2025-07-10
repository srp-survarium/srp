int __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::allocated_size(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return 208 * this->m_allocator.m_variable->m_allocated_count;
}
