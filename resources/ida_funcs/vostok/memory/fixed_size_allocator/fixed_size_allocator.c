void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this)
{
  vostok::memory::base_allocator::base_allocator(this);
  this->__vftable = (vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>_vtbl *)&vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::`vftable';
  this->m_allocator.m_variable = (vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex> *)&this->m_allocator;
  this->m_allocator.m_initialized = 0;
  this->m_allocator.m_construction_started = 0;
  this->m_arena_id = 0;
}
