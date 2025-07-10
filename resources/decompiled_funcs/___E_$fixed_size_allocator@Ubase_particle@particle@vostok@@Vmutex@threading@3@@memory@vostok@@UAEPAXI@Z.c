vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *__thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::`vector deleting destructor'(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        char a2)
{
  vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::~fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
