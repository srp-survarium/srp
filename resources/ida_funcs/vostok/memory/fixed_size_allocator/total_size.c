unsigned int __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::total_size(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return 208 * this->m_allocator.m_variable->m_max_count;
}


unsigned int __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::total_size(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this)
{
  return 12 * this->m_allocator.m_variable->m_max_count;
}


unsigned int __thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::total_size(
        vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *this)
{
  return 120 * this->m_allocator.m_variable->m_max_count;
}
