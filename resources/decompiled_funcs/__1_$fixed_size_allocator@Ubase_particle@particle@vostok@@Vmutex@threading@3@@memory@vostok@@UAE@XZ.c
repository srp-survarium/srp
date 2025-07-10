void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::~fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this)
{
  this->__vftable = (vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>_vtbl *)&vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::`vftable';
  vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>>::destroy((vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> > *)&this->m_allocator);
  vostok::memory::base_allocator::~base_allocator(this);
}
