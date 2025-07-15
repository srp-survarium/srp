char __thiscall vostok::particle::particle_system_instance_impl::is_finished(
        vostok::particle::particle_system_instance_impl *this)
{
  vostok::particle::particle_system_instance_impl *v1; // esi
  vostok::particle::particle_emitter_instance *i; // eax
  unsigned int m_num_lods; // edx
  unsigned int v5; // edi
  vostok::particle::particle_emitter_instance **p_m_first; // ecx
  vostok::particle::particle_emitter_instance *j; // eax
  int m_current_lod; // eax
  vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,492,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_emitter_instance_list; // ebx
  int m_first; // edi
  vostok::particle::particle_emitter_instance *v11; // ecx
  vostok::particle::particle_emitter_instance *v12; // ecx
  vostok::particle::particle_emitter_instance *v13; // eax
  vostok::particle::particle_emitter_instance *v14; // ecx
  vostok::particle::particle_emitter_instance **p_m_next; // eax
  vostok::particle::particle_emitter_instance *v16; // edx
  vostok::particle::particle_emitter_instance *v17; // eax
  char v19; // [esp+Ah] [ebp-2h]
  char v20; // [esp+Bh] [ebp-1h]

  v1 = this;
  if ( this->m_no_more_create )
  {
    if ( this->m_time_to_finish > 0.0 )
    {
      for ( i = this->m_lods[this->m_current_lod].m_emitter_instance_list.m_first; i; i = i->m_next )
      {
        if ( i->m_num_live_particles )
          return 0;
      }
    }
    return 1;
  }
  else
  {
    m_num_lods = this->m_num_lods;
    v5 = 0;
    if ( m_num_lods )
    {
      p_m_first = &this->m_lods[0].m_emitter_instance_list.m_first;
      do
      {
        for ( j = *p_m_first; j; j = j->m_next )
        {
          if ( !j->m_emitter->m_num_loops )
            return 0;
        }
        ++v5;
        p_m_first += 8;
      }
      while ( v5 < m_num_lods );
    }
    m_current_lod = v1->m_current_lod;
    p_m_emitter_instance_list = &v1->m_lods[m_current_lod].m_emitter_instance_list;
    m_first = (int)v1->m_lods[m_current_lod].m_emitter_instance_list.m_first;
    if ( m_first )
    {
      v20 = 1;
      do
      {
        v19 = (*(int (__thiscall **)(int))(*(_DWORD *)m_first + 28))(m_first);
        if ( v19 )
        {
          if ( v1->m_always_looping )
          {
            *(_DWORD *)(m_first + 516) = 0;
            *(_BYTE *)(m_first + 558) = 1;
            *(_DWORD *)(m_first + 504) = 0;
            *(_BYTE *)(m_first + 557) = 0;
            *(_DWORD *)(m_first + 508) = 0;
            vostok::particle::particle_emitter_instance::recalc_duration(v11, m_first);
            v1 = this;
          }
          else
          {
            vostok::particle::particle_emitter_instance::remove_particles(v11, m_first, 0xFFFFFFFF);
          }
          if ( *(_BYTE *)(m_first + 556) )
          {
            vostok::particle::particle_emitter_instance::remove_particles(v12, m_first, 0xFFFFFFFF);
            v13 = p_m_emitter_instance_list->m_first;
            if ( v13 )
            {
              v14 = 0;
              while ( v13 != (vostok::particle::particle_emitter_instance *)m_first )
              {
                v14 = v13;
                v13 = v13->m_next;
                if ( !v13 )
                  goto LABEL_36;
              }
              --p_m_emitter_instance_list->m_size;
              p_m_next = &v13->m_next;
              v16 = *p_m_next;
              if ( v14 )
                v14->m_next = v16;
              else
                p_m_emitter_instance_list->m_first = v16;
              if ( !*p_m_next )
              {
                v17 = v14;
                if ( !v14 )
                  v17 = p_m_emitter_instance_list->m_first;
                p_m_emitter_instance_list->m_last = v17;
              }
            }
          }
        }
LABEL_36:
        if ( !v20 || (v20 = 1, !v19) )
          v20 = 0;
        m_first = *(_DWORD *)(m_first + 492);
      }
      while ( m_first );
      return v1->m_always_looping ? 0 : v20;
    }
    else
    {
      return 0;
    }
  }
}
