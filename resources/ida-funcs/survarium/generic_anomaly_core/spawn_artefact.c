void __thiscall survarium::generic_anomaly_core::spawn_artefact(
        survarium::generic_anomaly_core *this,
        unsigned int current_time_in_ms)
{
  unsigned int v3; // esi
  void *v4; // esp
  const char **v5; // eax
  void **M_start; // edi
  signed int v7; // edx
  unsigned int v8; // eax
  unsigned int m_artefacts_count; // esi
  void *v10; // esp
  const char **v11; // eax
  const char **v12; // edi
  survarium::artefact_base *m_object; // esi
  signed int v14; // edx
  unsigned int m_seed; // eax
  unsigned int v16; // eax
  vostok::particle::particle_system_instance_impl *v17; // esi
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *v18; // esi
  vostok::particle::particle_system_instance_impl *v19; // edi
  unsigned __int16 v20; // ax
  int v21; // ecx
  char v22; // al
  const char *v23[4]; // [esp+4h] [ebp-28h] BYREF
  const char **v24; // [esp+14h] [ebp-18h]
  const char **i; // [esp+18h] [ebp-14h]
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *v26; // [esp+1Ch] [ebp-10h]
  vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> object; // [esp+20h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+24h] [ebp-8h] BYREF
  bool v29; // [esp+2Bh] [ebp-1h] BYREF

  if ( this->artefacts_respawn_chance >= vostok::math::random32::random_f(&this->m_random, 1.0) )
  {
    v3 = this->m_artefact_containers._M_impl._M_finish - this->m_artefact_containers._M_impl._M_start;
    v4 = alloca(4 * v3);
    v28.m_object = 0;
    v5 = v23;
    object.m_object = (survarium::artefact_base *)v23;
    v24 = v23;
    for ( i = &v23[v3]; (unsigned int)v28.m_object < v3; ++v28.m_object )
    {
      M_start = this->m_artefact_containers._M_impl._M_start;
      if ( !*((_DWORD *)M_start[(int)v28.m_object] + 20)
        || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( v5 >= i
          && !`vostok::buffer_vector<survarium::artefact_container_core *>::push_back'::`11'::debug_macro_helper_ignore_always )
        {
          v29 = 0;
          vostok::debug::on_error(
            &v29,
            process_error_true,
            0,
            "assertion_failed",
            "fatal error",
            "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
            "vostok::buffer_vector<class survarium::artefact_container_core *>::push_back",
            (const char *)0x12E,
            "buffer overflow",
            v23[0]);
          if ( vostok::debug::is_debugger_present() || v29 )
            __debugbreak();
          v5 = v24;
        }
        if ( v5 )
          *v5 = (const char *)M_start[(int)v28.m_object];
        v24 = ++v5;
      }
    }
    v7 = ((char *)v5 - (char *)object.m_object) >> 2;
    if ( v7 == 1 )
      this->m_need_to_spawn_artefacts = 0;
    v8 = 134775813 * this->m_random.m_seed + 1;
    this->m_random.m_seed = v8;
    m_artefacts_count = this->m_artefacts_count;
    v26 = (vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base> *)*((_DWORD *)&object.m_object->__vftable + (((unsigned int)v7 * (unsigned __int64)v8) >> 32));
    v10 = alloca(4 * m_artefacts_count);
    v28.m_object = 0;
    v11 = v23;
    v12 = &v23[m_artefacts_count];
    object.m_object = (survarium::artefact_base *)v23;
    v24 = v23;
    if ( m_artefacts_count )
    {
      do
      {
        m_object = this->m_artefacts[(int)v28.m_object].m_object;
        if ( m_object->m_state == artefact_state_inactive )
        {
          if ( v11 >= v12
            && !`vostok::buffer_vector<survarium::artefact_base *>::push_back'::`11'::debug_macro_helper_ignore_always )
          {
            v29 = 0;
            vostok::debug::on_error(
              &v29,
              process_error_true,
              0,
              "assertion_failed",
              "fatal error",
              "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
              "vostok::buffer_vector<class survarium::artefact_base *>::push_back",
              (const char *)0x12E,
              "buffer overflow",
              v23[0]);
            if ( vostok::debug::is_debugger_present() || v29 )
              __debugbreak();
            v11 = v24;
          }
          if ( v11 )
            *v11 = (const char *)m_object;
          v24 = ++v11;
        }
        ++v28.m_object;
      }
      while ( (unsigned int)v28.m_object < this->m_artefacts_count );
    }
    v14 = ((char *)v11 - (char *)object.m_object) >> 2;
    if ( v14 )
    {
      m_seed = this->m_random.m_seed;
      v28.m_object = 0;
      v16 = 134775813 * m_seed + 1;
      this->m_random.m_seed = v16;
      v17 = (vostok::particle::particle_system_instance_impl *)*((_DWORD *)&object.m_object->__vftable
                                                               + (((unsigned int)v14 * (unsigned __int64)v16) >> 32));
      if ( v17 )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
        v28.m_object = v17;
        _InterlockedExchangeAdd(&v17->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object,
        &v28);
      v18 = v26;
      vostok::resources::resource_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object,
        v26 + 20);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object);
      v19 = v28.m_object;
      v20 = (unsigned __int16)v28.m_object->m_lods[1].m_template.m_object;
      if ( v20 == 0xFFFF )
        v21 = 1;
      else
        v21 = v20;
      survarium::inventory_item::set_amount((survarium::inventory_item *)v21, (int)v28.m_object);
      v22 = (char)v18[24].m_object;
      v19->m_lods[1].m_emitter_instance_list.m_last = 0;
      v19->m_lods[1].m_emitter_instance_list.gap4 = v22;
      v19->m_lods[1].m_emitter_instance_list.m_first = (vostok::particle::particle_emitter_instance *)LODWORD(v19->m_lods[0].m_time_fade_out);
      v19->m_lods[1].m_emitter_instance_list.m_size = 1;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
    }
  }
  this->m_next_artefact_spawn_time_ms = current_time_in_ms + 1000 * this->artefacts_respawn_time_sec;
}
