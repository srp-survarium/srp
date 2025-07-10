unsigned int __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::total_size(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return 208 * this->m_allocator.m_variable->m_max_count;
}
