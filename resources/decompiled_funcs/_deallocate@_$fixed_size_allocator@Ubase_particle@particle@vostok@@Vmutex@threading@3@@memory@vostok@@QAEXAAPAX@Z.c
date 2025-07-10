void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::deallocate(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        void **data)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::deallocate(
    (vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *)this->m_allocator.m_variable,
    data);
}
