void __thiscall vostok::particle::particle_world::deallocate_particle(
        vostok::particle::particle_world *this,
        vostok::particle::base_particle *P)
{
  --this->m_num_particles;
  if ( P )
    vostok::memory::base_allocator::free_impl(&this->m_allocator, P);
}
