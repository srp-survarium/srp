void __thiscall survarium::medkit::tick(
        survarium::medkit *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  int v4; // esi
  vostok::resources::resource_link *m_first; // ecx
  unsigned int v6; // edx
  int v7; // eax
  vostok::resources::resource_link *v8; // eax
  bool v9; // zf
  vostok::threading::mutex *v10; // ecx
  unsigned __int64 v11; // kr00_8
  unsigned int v12; // ecx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v13; // edi
  survarium::damage_model *v14; // ecx
  survarium::body_part_parameters *body_part; // esi
  survarium::damage_model *v16; // ecx
  survarium::body_part_parameters *v17; // eax
  float m_health; // [esp+10h] [ebp-1Ch]
  float amount; // [esp+14h] [ebp-18h]
  float v20; // [esp+18h] [ebp-14h]
  int v21; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+20h] [ebp-Ch]
  int v23; // [esp+24h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v24; // [esp+28h] [ebp-4h] BYREF
  unsigned int v25; // [esp+34h] [ebp+8h]

  v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this[-1].m_active + 376) + 12))(*(_DWORD *)(*(_DWORD *)&this[-1].m_active + 376));
  v21 = v4;
  if ( !*(_BYTE *)(v4 + 764) )
    goto LABEL_13;
  m_first = this->m_children_resources.m_first;
  v6 = time_delta_ms;
  if ( !m_first
    || (v7 = -((unsigned int)m_first < time_delta_ms),
        m_first = (vostok::resources::resource_link *)((char *)m_first - time_delta_ms),
        v8 = (vostok::resources::resource_link *)(time_delta_ms + ((unsigned int)m_first & v7)),
        v9 = this->m_children_resources.m_first == v8,
        this->m_children_resources.m_first = (vostok::resources::resource_link *)((char *)this->m_children_resources.m_first
                                                                                - (unsigned int)v8),
        v9)
    && (time_delta_ms -= (unsigned int)v8, v6 != (_DWORD)v8) )
  {
    if ( *(_DWORD *)&this->m_children_resources.gapC == this->m_children_resources.m_lock )
    {
      survarium::medkit::remove_affects(
        (survarium::medkit *)m_first,
        (int)&this[-1].m_parent_resources.gapC,
        current_time_ms);
      vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(*(_DWORD *)((char *)&loc_11066 + v4 + 2) + 672),
        (survarium::player_params_modifier *)&this->m_parent_resources,
        v10);
    }
    v11 = *(unsigned int *)&this->m_children_resources.gapC - (unsigned __int64)time_delta_ms;
    v12 = time_delta_ms + (v11 & HIDWORD(v11));
    v25 = 0;
    v9 = BYTE4(this->m_reconstruction_info_actuality_tick) == 0;
    *(_DWORD *)&this->m_children_resources.gapC -= v12;
    if ( !v9 )
    {
      v23 = 0;
      v20 = (double)v12 * 0.001;
      do
      {
        v22 = v23 + *((_DWORD *)&this->vostok::resources::resource_flags + 3);
        amount = *(float *)(v22 + 16) * v20;
        if ( amount >= 0.000001 )
        {
          v13 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(int (__thiscall **)(int))(*(_DWORD *)(v4 + 264) + 8))(v4 + 264);
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v24,
            v13);
          body_part = survarium::damage_model::get_body_part(v14, (int)v24.m_object, (char *)v22);
          m_health = body_part->m_health;
          v17 = survarium::damage_model::get_body_part(v16, (int)v24.m_object, (char *)v22);
          survarium::body_part_parameters::increase_health(v17, current_time_ms, amount);
          *(float *)(LODWORD(this->m_reconstruction_info_actuality_tick) + 4 * v25) = (float)(body_part->m_health
                                                                                            - m_health)
                                                                                    + *(float *)(LODWORD(this->m_reconstruction_info_actuality_tick)
                                                                                               + 4 * v25);
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v24);
          v4 = v21;
        }
        ++v25;
        v23 += 20;
      }
      while ( v25 < BYTE4(this->m_reconstruction_info_actuality_tick) );
    }
    if ( !*(_DWORD *)&this->m_children_resources.gapC )
LABEL_13:
      survarium::medkit::set_active((survarium::medkit *)((char *)this - 288), 0, current_time_ms);
  }
}
