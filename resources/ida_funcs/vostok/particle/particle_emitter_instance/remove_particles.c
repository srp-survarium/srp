void __thiscall vostok::particle::particle_emitter_instance::remove_particles(
        vostok::particle::particle_emitter_instance *this,
        unsigned int num)
{
  vostok::particle::base_particle *to_del; // [esp+24h] [ebp-Ch]
  unsigned int index; // [esp+28h] [ebp-8h]
  vostok::particle::base_particle *P; // [esp+2Ch] [ebp-4h]

  index = 0;
  P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::front(
        (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
        (int)&this->m_particle_list);
  while ( P && index != num )
  {
    ++index;
    vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
      &this->m_particle_list,
      P);
    to_del = P;
    P = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(P);
    --this->m_num_live_particles;
    vostok::particle::particle_world::deallocate_particle(this->m_particle_world, to_del);
  }
  if ( num == -1 )
    vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::clear(&this->m_particle_list);
}
