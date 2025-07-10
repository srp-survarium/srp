void __thiscall vostok::particle::particle_system_instance_impl::remove_emitter_instances(
        vostok::particle::particle_system_instance_impl *this)
{
  vostok::particle::particle_emitter_instance *v1; // ecx
  vostok::memory::pthreads3_allocator *v2; // eax
  vostok::particle::particle_emitter_instance *to_del; // [esp+18h] [ebp-Ch] BYREF
  vostok::particle::particle_emitter_instance *instance; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  for ( i = 0; i < this->m_num_lods; ++i )
  {
    instance = this->m_lods[i].m_emitter_instance_list.m_first;
    while ( instance )
    {
      to_del = instance;
      v1 = instance;
      instance = instance->m_next;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
      vostok::memory::detail::delete_helper_impl<vostok::memory::pthreads3_allocator,vostok::particle::particle_system_instance,vostok::memory::detail::call_destructor_predicate>(
        v2,
        (vostok::sound::sound_order **)&to_del);
    }
    vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::clear(&this->m_lods[i].m_emitter_instance_list);
  }
}
