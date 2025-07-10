void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::call_free(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        void *pointer)
{
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::deallocate(
    this,
    &pointer);
}
