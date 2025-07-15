char __thiscall vostok::particle::particle_system_instance_impl::is_finished(
        vostok::particle::particle_system_instance_impl *this)
{
  bool v2; // [esp+0h] [ebp-40h]
  bool finished; // [esp+27h] [ebp-19h]
  vostok::particle::particle_emitter_instance *k; // [esp+28h] [ebp-18h]
  unsigned int i; // [esp+2Ch] [ebp-14h]
  vostok::particle::particle_emitter_instance *j; // [esp+30h] [ebp-10h]
  bool ps_finished; // [esp+37h] [ebp-9h]
  vostok::particle::particle_emitter_instance *instance; // [esp+38h] [ebp-8h]
  vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *emitter_instances_list; // [esp+3Ch] [ebp-4h]

  if ( this->m_no_more_create )
  {
    for ( j = this->m_lods[this->m_current_lod].m_emitter_instance_list.m_first; j; j = j->m_next )
    {
      if ( j->m_num_live_particles )
        return 0;
    }
    return 1;
  }
  else
  {
    for ( i = 0; i < this->m_num_lods; ++i )
    {
      for ( k = this->m_lods[i].m_emitter_instance_list.m_first; k; k = k->m_next )
      {
        if ( !k->m_emitter->m_num_loops )
          return 0;
      }
    }
    emitter_instances_list = &this->m_lods[this->m_current_lod].m_emitter_instance_list;
    instance = this->m_lods[this->m_current_lod].m_emitter_instance_list.m_first;
    if ( instance )
    {
      ps_finished = 1;
      while ( instance )
      {
        finished = instance->is_finished(instance);
        if ( finished )
        {
          if ( this->m_always_looping )
          {
            instance->m_current_loop = 0;
            instance->m_delayed = 1;
            instance->m_delay_time = *(float *)&FLOAT_0_0;
            instance->m_waiting_for_end = 0;
            instance->m_emitter_time = *(float *)&FLOAT_0_0;
            vostok::particle::particle_emitter_instance::recalc_duration(instance);
          }
          else
          {
            vostok::particle::particle_emitter_instance::remove_particles(instance, 0xFFFFFFFF);
          }
        }
        if ( finished && instance->m_is_child_emitter_instance )
        {
          vostok::particle::particle_emitter_instance::remove_particles(instance, 0xFFFFFFFF);
          vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
            emitter_instances_list,
            instance);
        }
        v2 = ps_finished && finished;
        ps_finished = v2;
        instance = instance->m_next;
      }
      return !this->m_always_looping && ps_finished;
    }
    else
    {
      return 0;
    }
  }
}
